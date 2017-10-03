#include<stdio.h>
#include<stdlib.h>

int main(){
	char* names[4];
	char name[128];
	int i;
	
	for(i=0;i<4;i++){
		gets(name);
		names[i] = (char*)calloc(strlen(name)+1,sizeof(char));
		strcpy(names[i],name);
	}
	
	for(i=0;i<4;i++){
		printf("%s \n", names[i]);
	}
	return 0;
}
