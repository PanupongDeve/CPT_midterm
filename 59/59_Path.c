#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
	int x,y;
} Point;

typedef struct {
	int amount;
	Point *points;
} Path;

void path_input(Path *p);
void point_inout(Point *p);
void path_clear(Path *p);
float path_distance(Path *p);
float line_distance(Point *p1,Point *p2);

int main(){
	Path p;
	path_input(&p);
	
	return 0;
}
void path_input(Path *p){
	int i, amount;
//	scanf(" %d", &amount);
//	p->amount = amount;
	Point *ptr = &(p->points);
	ptr = (Point*)calloc(amount,sizeof(Point));

}

