#define _CRT_SECURE_NO_WARNINGS

#define MaxLength 100    //用于优先队列（Open表）的数组
#define Height     9    //地图高度
#define Width      9    //地图宽度

#define Reachable   0    //可以到达的结点
#define Bar         1    //障碍物
#define Pass        2    //需要走的步数
#define Source      3    //起点
#define Destination 4    //终点

#define Sequential  0    //顺序遍历
#define NoSolution  2    //无解决方案
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

typedef struct //优先队列（Open表）
{
	int length;        //当前队列的长度
	Close* Array[MaxLength];    //评价结点的指针
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
static int srcX, srcY, dstX, dstY;    //起始点、终点
static Close close[Height][Width];
static Close *start;


//这个头文件唯一包含的
std::vector<Point>* printShortest();