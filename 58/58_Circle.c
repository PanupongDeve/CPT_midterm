#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
	int x,y;
} Point;

typedef struct{
	Point c;
	int r;
} Circle;

void input_circle(Circle *r);
float line_distance(Point *p1, Point *p2);
int is_intersect(Circle *c1, Circle *c2); // 1 for yes , o for no;

int main(){
	Circle main;
	Circle *others;
	int i,num, count = 0;
	
	main.c.x = 4;
	main.c.y = 5;
	main.r = 8;
	
	input_circle(&main);//input main circle
	
	printf("Enter num: ");
	scanf(" %d", &num);
	
	others = (Circle*)calloc(num,sizeof(Circle));// allocate Others Cicle
	
	for(i = 0;i< num; i++){
		input_circle(&others[i]);
//		printf("Circle[%d] = %d ,%d ,%d \n",i, others[i].c.x, others[i].c.y, others[i].r);
	}
	
	for(i=0; i< num;i++){
		if(is_intersect(&main,&others[i])){
			count++;
		}
	}
	
	printf("Intersected circle = %d\n", count);
	
	free(others);
	return 0;
}
void input_circle(Circle *r){
	printf("Circle x, y, r: ");
	scanf("%d %d %d", &r->c.x, &r->c.y, &r->r); // scanf Circle
//	printf("%d, %d, %d", r->c.x, r->c.y, r->r);

}
float line_distance(Point *p1, Point *p2){
	return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));

}
int is_intersect(Circle *c1, Circle *c2){

	int sum_r = c1->r+c2->r;
	float distance = line_distance(&c1->c,&c2->c);
	if(distance < sum_r){
		return 1;
	}
	return 0;
}
