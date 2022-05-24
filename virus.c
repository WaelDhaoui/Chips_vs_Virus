#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stddef.h>

typedef struct virus{
int type;
int life;
int line;
int position;
int speed;
int turn;
struct virus* next;
struct virus* next_line;
struct virus* prev_line;
}Virus;

struct virus cree_v(int vie,int p,int s,char* path) {
	Virus v;
	
	FILE *file;
	char type;
    
	file = fopen(path,"r");
	
    if (file == NULL){printf ("erreur;check game file"); exit(1);}
    
    while (!feof(file)){
        //remplire 
    	fscanf(file,"%d %d %c",&v.turn,&v.line,&v.turn);
    	if(&type == "E")
    		v.type = -1;
    	else if(&type == "B")
    		v.type = -2;
    	else 
    		v.type = -3;
    }
	
	v.life = vie;
	v.position = p;
	v.speed = s;
    fclose (file);
	return v;
}
