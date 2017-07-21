#include <stdio.h>
#include <math.h>
#include<iostream>
#include "a.h"
#include<Vector>
using namespace std;










// 优先队列基本操作
void initOpen(Open *q)    //优先队列初始化
{
	q->length = 0;        // 队内元素数初始为0
}

void push(Open *q, Close cls[Height][Width], int x, int y, float g)
{    //向优先队列（Open表）中添加元素
	Close *t;
	int i, mintag;
	cls[x][y].G = g;    //所添加节点的坐标
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
	q->Array[mintag] = t;    //将评价函数值最小节点置于队头
}

Close* shift(Open *q)
{
	return q->Array[--q->length];
}

// 地图初始化操作
void initClose(Close cls[Height][Width], int sx, int sy, int dx, int dy)
{    // 地图Close表初始化配置
	int i, j;
	for (i = 0; i < Height; i++)
	{
		for (j = 0; j < Width; j++)
		{
			cls[i][j].cur = &graph[i][j];        // Close表所指节点
			cls[i][j].vis = !graph[i][j].reachable;        // 是否被访问
			cls[i][j].from = NULL;                // 所来节点
			cls[i][j].G = cls[i][j].F = 0;
			cls[i][j].H = abs(dx - i) + abs(dy - j);    // 评价函数值
		}
	}
	cls[sx][sy].F = cls[sx][sy].H;            //起始点评价初始值
											  //    cls[sy][sy].G = 0;                        //移步花费代价值
	cls[dx][dy].G = Infinity;
}

void initGraph(int** map,int height,int width, int sx, int sy, int dx, int dy)
{    //地图发生变化时重新构造地
	int i, j;
	srcX = sx;    //起点X坐标
	srcY = sy;    //起点Y坐标
	dstX = dx;    //终点X坐标
	dstY = dy;    //终点Y坐标
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < height; j++)
		{
			graph[i][j].x = i; //地图坐标X
			graph[i][j].y = j; //地图坐标Y
			graph[i][j].value = map[i][j];
			graph[i][j].reachable = (graph[i][j].value == Reachable);    // 节点可到达性
			graph[i][j].sur = 0; //邻接节点个数
			if (!graph[i][j].reachable)
			{
				continue;
			}
			if (j > 0)
			{
				if (graph[i][j - 1].reachable)    // left节点可以到达
				{
					graph[i][j].sur |= West;
					graph[i][j - 1].sur |= East;
				}
				if (i > 0)
				{
					if (graph[i - 1][j - 1].reachable
						&& graph[i - 1][j].reachable
						&& graph[i][j - 1].reachable)    // up-left节点可以到达
					{
						graph[i][j].sur |= North_West;
						graph[i - 1][j - 1].sur |= South_East;
					}
				}
			}
			if (i > 0)
			{
				if (graph[i - 1][j].reachable)    // up节点可以到达
				{
					graph[i][j].sur |= North;
					graph[i - 1][j].sur |= South;
				}
				if (j < width - 1)
				{
					if (graph[i - 1][j + 1].reachable
						&& graph[i - 1][j].reachable
						&& map[i][j + 1] == Reachable) // up-right节点可以到达
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
{    // A*算法遍历
	 //int times = 0;
	int i, curX, curY, surX, surY;
	float surG;
	Open q; //Open表
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
	return NoSolution; //无结果
}

Close* getShortest()
{    // 获取最短路径
	int result = astar();
	Close *p, *t, *q = NULL;
	switch (result)
	{
	case Sequential:    //顺序最近
		p = &(close[dstX][dstY]);
		while (p)    //转置路径
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


vector<Point>* printShortest()
{
	vector < Point>* list = new vector<Point>;
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
			
		//	printf("（%d，%d）→\n", p->cur->x, p->cur->y);
			a.x = p->cur->x;
			a.y = p->cur->y;
			list->push_back(a);
			p = p->from;
			step++;
		}
		a.x = p->cur->x;
		a.y = p->cur->y;
		list->push_back(a);
		//printf("（%d，%d）\n", p->cur->x, p->cur->y);
		//cout << p->cur->x;
		//cout << a->x;
		graph[srcX][srcY].value = Source;
		graph[dstX][dstY].value = Destination;
		return list;
	}
}


int main(int argc, const char **argv)
{

	int** map1 = new int*[9];
	for (int i = 0; i < 9; i++)
	{
		map1[i] = new int[9];
		for (int j = 0; j < 9; j++)
		{
			if (i+j==8)
				map1[i][j] = 1;
			else
			{
				map1[i][j] = 0;
			}
			//cout << map1[i][j]<<",";
		};
	}

	//initGraph(map1,9,9, 0, 0, 0, 0);
	srcX = 0; srcY = 0;
	dstX = 4, dstY = 3;
	cout << printShortest()->size()<<"\n";
		if (printShortest()->size() == 5)
		{
		}
		else
		{
			printf("从（%d，%d）不可到达（%d，%d）\n",
				srcX, srcY, dstX, dstY);
		}

		int i = 0;

		for each (Point var in *printShortest())
		{
			cout << i++ << ":";
			cout << var.x << " " << var.y << "\n";
		}
}