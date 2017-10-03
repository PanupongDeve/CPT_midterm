#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[128];
	int max_hp;
} Character;

void readOnlyFile(FILE *fp,int num);

int main(){
	int num,i, done = 0;
	Character c;
	fpos_t position;
	
	FILE *fp = fopen("save.bin", "rb+");
	fread(&num, sizeof(int), 1, fp);
	

//	readOnlyFile(fp,num);
	

	
	
	for(i=0;i<num && !done;i++){
		fgetpos(fp, &position);	
		fread(&c, sizeof(Character), 1, fp);		
		if(strcmp(c.name, "Lucy") == 0){
			c.max_hp = 9999;
			printf("%s \n", c.name);
			printf("%d \n", c.max_hp);
			fsetpos(fp, &position);
			fwrite(&c, sizeof(Character), 1, fp);
			done =1;
		}
	}
	
	
	printf("Read and Write Success\n");
	fclose(fp);
	return 0;
}
void readOnlyFile(FILE *fp,int num){
	Character c;
	int i;
	for(i=0;i<num; i++){
		fread(&c, sizeof(Character), 1, fp);
		printf(" %s:%d \n",c.name, c.max_hp);
	}
}
