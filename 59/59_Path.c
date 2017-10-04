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
void point_input(Point *p);
void path_clear(Path *p);
float path_distance(Path *p);
float line_distance(Point *p1,Point *p2);

int main(){
	Path p;
	path_input(&p);
	printf("Path Distance = %.2f\n", path_distance(&p));
	return 0;
}

void path_input(Path *p){
	int i, amount;
	scanf(" %d", &amount);
	p->amount = amount;
	
	p->points = (Point*)calloc(amount,sizeof(Point));
	
	for(i=0;i<amount;i++){
		printf(" %2d. ", i+1);
		point_input(&p->points[i]);
	}

}

void point_input(Point *p){
	printf("(x,y): ");
	scanf(" %d %d", &p->x, &p->y);
}

void path_clear(Path *p){
	free(p);
}

float path_distance(Path *p){
	int i;
	float total = 0.0;
	
//	printf("%d\n", p->amount);
	for(i=1;i<p->amount;i++){
		total += line_distance(&p->points[i-1],&p->points[i]);
	}

	return total;
}

float line_distance(Point *p1, Point *p2){
	return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

