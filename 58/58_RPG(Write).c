#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[128];
    int max_hp;
} Character;

void writeFile(int num);
int main(){
    int num_player = 3;
    writeFile(num_player);
    printf("write Sucess");

    return 0;
}

void writeFile(int num){
    Character *players = (Character*)calloc(num,sizeof(Character));
    int i;

    FILE *fp = fopen("save.bin", "wb");

    //input data
    fwrite(&num, sizeof(int), 1, fp);

    //Print Check Data
    strcpy(players[0].name,"Jone");
    strcpy(players[1].name,"Lucy");
    strcpy(players[2].name,"Josesy");
    players[0].max_hp = 1000;
    players[1].max_hp = 1000;
    players[2].max_hp = 1000;

    //print checkdata befor Write data
    for(i=0;i<num;i++){
        printf(" %s:%d \n",players[i].name, players[i].max_hp);
    }

    //WriteFile
    fwrite(players, sizeof(Character), num, fp);
    fclose(fp);

}
