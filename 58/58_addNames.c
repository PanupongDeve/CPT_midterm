#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char* names[4];
	char name[127];
	int i;
	for(i=0;i<4;i++){
		printf("Input name: ");
		gets(name);
		names[i] = calloc(strlen(name)+1,sizeof(char));
		strcpy(names[i],name);
	}
	
	for(i=0;i<4;i++){
		printf("%s \n",names[i]);
	}
	
	free(names);
	return 0;
}
