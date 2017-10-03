#include<stdio.h>

char *strcpy(char* destination, char* source);
int main(){
	char msg[128] = "Hello Wolrd";
	char *msg_cpy;
	
	msg_cpy= (msg_cpy,msg);
	printf("%s", msg_cpy);
	
	return 0;
}
char *strcpy(char* destination, char* source){

	while(*source != '\0'){
		*destination = *source;
		source++;
		destination++;
	}
	return destination;
}
