/*
 массив структур
 */


#include <stdio.h>

enum {max_points = 10};

struct tag_point{
	double x, y, z;
};

int main(int argc, char **argv)
{
	struct tag_point figure_one[max_points];
	int figure_points = 0; //число точек в фигуре
	
	figure_one[0].x = 1.2;
	figure_one[0].y = -5.6;
	figure_one[0].z = 10.0;
	
	figure_one[1].x = 12.4;
	figure_one[1].y = 3.2;
	figure_one[1].z = 7.6;	
	
	figure_points = 2;
	
	printf("point 1: x=%.2f, y=%.2f, z=%.2f \n", figure_one[0].x, figure_one[0].y, figure_one[0].z);
	printf("point 2: x=%.2f, y=%.2f, z=%.2f \n", figure_one[1].x, figure_one[1].y, figure_one[1].z);
	
	return 0;
}

