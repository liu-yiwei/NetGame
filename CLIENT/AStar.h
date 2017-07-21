#define _CRT_SECURE_NO_WARNINGS

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
#include <Vector>

typedef struct
{
	signed int x, y;
} Point;

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
	Close* Array[MaxLength];    //���۽���ָ��
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

static MapNode graph[Height][Width];
static int srcX, srcY, dstX, dstY;    //��ʼ�㡢�յ�
static Close close[Height][Width];
static Close *start;


//���ͷ�ļ�Ψһ������
std::vector<Point>* printShortest();