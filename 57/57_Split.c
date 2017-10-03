#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char** split(char *s, char key, int *count_p);
char* cfind(char *s, char key);
int main(){
	char **result = NULL;
	char buf[128] = "abc:def:g";
	int s_len = 0;
	int i;

	
	result = split(buf,':', &s_len);
	if(result != NULL){
		for(i=0; i< s_len;i++){
			printf("%s\n", result[i]);
		}
	}

	free(result);
	
	return 0;
}

char* cfind(char *s,char key){
	*s = '\0';
	return s+1;
}

char** split(char *s,char key,int *count_p){
	char **result;
	char *p =s;
	int i;


	*count_p =1;
	
	while( *p != '\0'){
		if(*p == key){
			(*count_p)++;
		}
		p++;
	}
	
	result = calloc(128,sizeof(char[*count_p]));
	result[0] = s;	
	p=s;
	i=0;
	while( *p != '\0'){
		if(*p==key){
			i++;
			result[i] = cfind(p,key);
		}	
		p++;
	}


	return result;
}
