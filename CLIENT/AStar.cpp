#include <stdio.h>
#include <math.h>
#include<iostream>
#include "AStar.h"
#include<Vector>

#define MaxLength 100    //�������ȶ��У�Open��������
#define Height     9    //��ͼ�߶�
#define Width      9    //��ͼ���

#define Reachable   0    //���Ե���Ľ��
#define Bar         1    //�ϰ���
#define Pass        2    //��Ҫ�ߵĲ���
#define Source      3    //���
#define Destination 4    //�յ�

#define Sequential  0    //˳�����
#define NoSolution  2    //�޽������
#define Infinity    0xfffffff

#define East       (1 << 0)
#define South_East (1 << 1)
#define South      (1 << 2)
#define South_West (1 << 3)
#define West       (1 << 4)
#define North_West (1 << 5)
#define North      (1 << 6)
#define North_East (1 << 7)

typedef struct
{
	int x, y;
	unsigned char reachable, sur, value;
} MapNode;

typedef struct Close
{
	MapNode *cur;
	char vis;
	struct Close *from;
	float F, G;
	int H;
} Close;

typedef struct //���ȶ��У�Open��
{
	int length;        //��ǰ���еĳ���
	Close* Array[100];    //���۽���ָ��
} Open;

const Point dir[8] =
{
	{ 0, 1 },   // East
	{ 1, 1 },   // South_East
	{ 1, 0 },   // South
	{ 1, -1 },  // South_West
	{ 0, -1 },  // West
	{ -1, -1 }, // North_West
	{ -1, 0 },  // North
	{ -1, 1 }   // North_East
};

static MapNode graph[9][9];
static int srcX, srcY, dstX, dstY;    //��ʼ�㡢�յ�
static Close close[9][9];
static Close *start;
// ���ȶ��л�������
void initOpen(Open *q)    //���ȶ��г�ʼ��
{
	q->length = 0;        // ����Ԫ������ʼΪ0
}

void push(Open *q, Close cls[Height][Width], int x, int y, float g)
{    //�����ȶ��У�Open�������Ԫ��
	Close *t;
	int i, mintag;
	cls[x][y].G = g;    //����ӽڵ������
	cls[x][y].F = cls[x][y].G + cls[x][y].H;
	q->Array[q->length++] = &(cls[x][y]);
	mintag = q->length - 1;
	for (i = 0; i < q->length - 1; i++)
	{
		if (q->Array[i]->F < q->Array[mintag]->F)
		{
			mintag = i;
		}
	}
	t = q->Array[q->length - 1];
	q->Array[q->length - 1] = q->Array[mintag];
	q->Array[mintag] = t;    //�����ۺ���ֵ��С�ڵ����ڶ�ͷ
}

Close* shift(Open *q)
{
	return q->Array[--q->length];
}

// ��ͼ��ʼ������
void initClose(Close cls[Height][Width], int sx, int sy, int dx, int dy)
{    // ��ͼClose���ʼ������
	int i, j;
	for (i = 0; i < Height; i++)
	{
		for (j = 0; j < Width; j++)
		{
			cls[i][j].cur = &graph[i][j];        // Close����ָ�ڵ�
			cls[i][j].vis = !graph[i][j].reachable;        // �Ƿ񱻷���
			cls[i][j].from = NULL;                // �����ڵ�
			cls[i][j].G = cls[i][j].F = 0;
			cls[i][j].H = abs(dx - i) + abs(dy - j);    // ���ۺ���ֵ
		}
	}
	cls[sx][sy].F = cls[sx][sy].H;            //��ʼ�����۳�ʼֵ
											  //    cls[sy][sy].G = 0;                        //�Ʋ����Ѵ���ֵ
	cls[dx][dy].G = Infinity;
}

void initGraph(int** map, int height, int width, int sx, int sy, int dx, int dy)
{    //��ͼ�����仯ʱ���¹����
	int i, j;
	srcX = sx;    //���X����
	srcY = sy;    //���Y����
	dstX = dx;    //�յ�X����
	dstY = dy;    //�յ�Y����
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < height; j++)
		{
			graph[i][j].x = i; //��ͼ����X
			graph[i][j].y = j; //��ͼ����Y
			graph[i][j].value = map[i][j];
			graph[i][j].reachable = (graph[i][j].value == Reachable);    // �ڵ�ɵ�����
			graph[i][j].sur = 0; //�ڽӽڵ����
			if (!graph[i][j].reachable)
			{
				continue;
			}
			if (j > 0)
			{
				if (graph[i][j - 1].reachable)    // left�ڵ���Ե���
				{
					graph[i][j].sur |= West;
					graph[i][j - 1].sur |= East;
				}
				if (i > 0)
				{
					if (graph[i - 1][j - 1].reachable
						&& graph[i - 1][j].reachable
						&& graph[i][j - 1].reachable)    // up-left�ڵ���Ե���
					{
						graph[i][j].sur |= North_West;
						graph[i - 1][j - 1].sur |= South_East;
					}
				}
			}
			if (i > 0)
			{
				if (graph[i - 1][j].reachable)    // up�ڵ���Ե���
				{
					graph[i][j].sur |= North;
					graph[i - 1][j].sur |= South;
				}
				if (j < width - 1)
				{
					if (graph[i - 1][j + 1].reachable
						&& graph[i - 1][j].reachable
						&& map[i][j + 1] == Reachable) // up-right�ڵ���Ե���
					{
						graph[i][j].sur |= North_East;
						graph[i - 1][j + 1].sur |= South_West;
					}
				}
			}
		}
	}
}


int astar()
{    // A*�㷨����
	 //int times = 0;
	int i, curX, curY, surX, surY;
	float surG;
	Open q; //Open��
	Close *p;

	initOpen(&q);
	initClose(close, srcX, srcY, dstX, dstY);
	close[srcX][srcY].vis = 1;
	push(&q, close, srcX, srcY, 0);

	while (q.length)
	{    //times++;
		p = shift(&q);
		curX = p->cur->x;
		curY = p->cur->y;
		if (!p->H)
		{
			return Sequential;
		}
		for (i = 0; i < 8; i++)
		{
			if (!(p->cur->sur & (1 << i)))
			{
				continue;
			}
			surX = curX + dir[i].x;
			surY = curY + dir[i].y;
			if (!close[surX][surY].vis)
			{
				close[surX][surY].vis = 1;
				close[surX][surY].from = p;
				surG = p->G + sqrt((double)((curX - surX) * (curX - surX) + (curY - surY) * (curY - surY)));
				push(&q, close, surX, surY, surG);
			}
		}
	}
	//printf("times: %d\n", times);
	return NoSolution; //�޽��
}

Close* getShortest()
{    // ��ȡ���·��
	int result = astar();
	Close *p, *t, *q = NULL;
	switch (result)
	{
	case Sequential:    //˳�����
		p = &(close[dstX][dstY]);
		while (p)    //ת��·��
		{
			t = p->from;
			p->from = q;
			q = p;
			p = t;
		}
		close[srcX][srcY].from = q->from;
		return &(close[srcX][srcY]);
	case NoSolution:
		return NULL;
	}
	return NULL;
}


std::vector<Point>* printShortest()
{
	std::vector < Point>* list = new std::vector<Point>;
	Close *p;
	int step = 0;

	Point a;
	//cout << list->size()<<"asdf";

	p = getShortest();
	start = p;
	if (!p)
	{
		return list;
	}
	else
	{
		while (p->from)
		{
			graph[p->cur->x][p->cur->y].value = Pass;

			//	printf("��%d��%d����\n", p->cur->x, p->cur->y);
			a.x = p->cur->x;
			a.y = p->cur->y;
			list->push_back(a);
			p = p->from;
			step++;
		}
		a.x = p->cur->x;
		a.y = p->cur->y;
		list->push_back(a);
		//printf("��%d��%d��\n", p->cur->x, p->cur->y);
		//cout << p->cur->x;
		//cout << a->x;
		graph[srcX][srcY].value = Source;
		graph[dstX][dstY].value = Destination;
		return list;
	}
}

//
//int main(int argc, const char **argv)
//{
//
//	int** map1 = new int*[9];
//	for (int i = 0; i < 9; i++)
//	{
//		map1[i] = new int[9];
//		for (int j = 0; j < 9; j++)
//		{
//			if (i + j == 8)
//				map1[i][j] = 1;
//			else
//			{
//				map1[i][j] = 0;
//			}
//			//cout << map1[i][j]<<",";
//		};
//	}
//
//	//initGraph(map1,9,9, 0, 0, 0, 0);
//	srcX = 0; srcY = 0;
//	dstX = 4, dstY = 3;
//	cout << printShortest()->size() << "\n";
//	if (printShortest()->size() == 5)
//	{
//	}
//	else
//	{
//		printf("�ӣ�%d��%d�����ɵ��%d��%d��\n",
//			srcX, srcY, dstX, dstY);
//	}
//
//	int i = 0;
//
//	for each (Point var in *printShortest())
//	{
//		cout << i++ << ":";
//		cout << var.x << " " << var.y << "\n";
//	}
//}


std::vector<Point>* getPath(int **map, int height, int width, int sx, int sy, int dx, int dy)
{
	initGraph(map,9,9, 0, 0, 0, 0);
	srcX = sx; srcY = sy;
	dstX = dx, dstY = dy;
	return  printShortest();
	
}