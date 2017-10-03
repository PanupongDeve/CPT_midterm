#include <stdio.h>

char *strdiff(char *s1,char *s2);
int main(){
	char s1[128] = "Hello";
	char s2[128] = "Henry";
	
	char *ptr;
	
	ptr = strdiff(s1,s2);
	
	printf("%s", ptr);
	return 0;
}
char *strdiff(char *s1,char *s2){
	while(*s1 != '\0'){
		if(*s1 != *s2){
			return s1;
		}
		
		s1++;
		s2++;
	}
	
	
	return s1;
}
