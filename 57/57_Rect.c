#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NUM 5

typedef struct {
	int x,y;
} Point;

typedef struct {
	char *title;
	float circum;
	Point points[3];
} Rect;

void input_rect(Rect *r);
float line_distance(Point *p1, Point *p2);
float rect_circum(Rect *r);
Rect *longest_rect(Rect rt[], int len);

int main(){
	Rect rt[NUM];
	Rect *r;
	int i;
	
	for(i=0; i<NUM; i++){
		input_rect(rt+i);
	}
	
	r = longest_rect(rt, NUM);
	printf("Longest = %s\n", r->title);
 	
	
	return 0;
}
void input_rect(Rect *r){
	int i;
	char title[128];
	
	printf("get Title: ");
	
	r->title = (char*)calloc(128,sizeof(char));
	scanf("%s", r->title);

	
	for(i=0;i<3;i++){
		printf("get xy[%d]",i+1);
		scanf(" %d %d",&r->points[i].x, &r->points[i].y);
	}
	
	r->circum = rect_circum(r);
	
	fflush(title);
	
}

float line_distance(Point *p1, Point *p2){
//	printf(" %d %d\n",p1->x, p1->y);
//	printf(" %f \n", sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2)));
	return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

float rect_circum(Rect *r){
	float circum = 0.0;
	int i;
	
	for(i=0;i<3;i++){
		if(i==2){
			circum += line_distance(&r->points[2], &r->points[0]);
			break;
		}
		circum += line_distance(&r->points[i], &r->points[i+1]);
	}
	
	printf("%.2f\n", circum);
	return circum;
}
Rect *longest_rect(Rect rt[], int len){
	int i;
	Rect *ptr;
	ptr = &rt[0];
	for(i=0;i<len;i++){
		if(rt[i].circum > ptr->circum){
			ptr = &rt[i];
		}
//		printf(" %.2f \n", rt[i].circum);
	}
	
	return ptr;
}

























