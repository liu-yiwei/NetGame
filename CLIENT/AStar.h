#pragma once
#include <Vector>

typedef struct
{
	signed int x, y;
} Point;




std::vector<Point>* 
getPath(int **map, int height, int width, int sx, int sy, int dx, int dy);