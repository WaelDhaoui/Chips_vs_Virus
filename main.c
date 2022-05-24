#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stddef.h>
#include"game.h"
#include"virus.h"
#include"chips.h"
#define l 3
#define C 4


int main() {
	
	int i,k,ligne,pos;
	
	Chips c1,c2,c3;
	Virus v1,v2,v3;
	Game g;
	
	g= init_game();
	
	//creation virus
	v1=cree_v(3,3,1,"level1.txt");//Un gros vilain très solide mais très lent.
	v2=cree_v(1,3,1,"level1.txt");//Un gros vilain de base pas trop solide et pas trop rapide.
	v3=cree_v(2,3,2,"level1.txt");//Un gros vilain très rapide mais de résistance raisonnable.
	
	//creation_chips
	c1=cree_c(1,1,0,0,100);//Une tourelle de base abordable, faisant de petits dégâts uniquement sur sa ligne.
	c2=cree_c(2,2,1,0,200);//mur
	c3=cree_c(3,1,2,0,150);//Une tourelle de type mine, abordable, et explose au contact en tuant ainsi seulement le premier gros vilain.
	//remplissage
	remplir_v(&v3,&g);
	remplir_v(&v2,&g);
	remplir_v(&v1,&g);
	remplir_c(&c1,&g);
	remplir_c(&c2,&g);
	remplir_c(&c3,&g);
	
	Virus Tv[l][C];
	Chips Tc[l][0];
	
	for(i=0;i<l;i++) {
		Tc[i][0].life = 0;
		for(k=0;k<C;k++) 
			Tv[i][k].type = 0;
	}
	
	int j=1;
	
	while(j<=g.turn) {
		int res;
		if(g.money <= 0 || res == -1) 
			break; 
		if(g.virus->turn == j || 1 == 1) {
			Virus *v;
			v=g.virus;
			//virus
			defiler(g);
			Tv[v->line][v->position] = *v;
			if(v->line == 0) {
				v->next_line = &Tv[v->line + 1][C-1];
				v->prev_line = NULL;
			}
			else if(v->line == (l-1)) {
				v->prev_line = &Tv[v->line - 2][C-1];
			}
		}
		for(i=0;i<l;i++) {
			printf("%d\t",Tc[i][0].life);
			for(k=0;k<C;k++) {
				printf("%d  ",Tv[i][k].type);
				}
			printf("\n");
		}
		
		//Chips
		printf("choose a num :\n");
		printf("1 | ALU \n");
		printf("2 | RAM \n");
		printf("3 | PMMU \n");
		
		int entre;
		Chips n;
		do {
			scanf("%d",&entre);
			switch(entre) {
				case 1 : n=c1; break;
				case 2 : n=c2; break;
				case 3 : n=c3; break;
				default : printf("please enter a valid type ! \n");
			}
			if(g.money < n.price) {
				printf("you don't have the money'\n");
				entre = -1;
			}
			g.money-=n.price;
		}while(entre <0 && entre > 3);
		
		int last,check=0;
		for(last=0;last<l;last++) {
		 	if(Tc[last][0].type == 0) {
		 		Tc[last][0] = n;
			}
		}
		if(last >= l) {
			printf("les position sont plien\n");
		}
		
		//jeu pour chips
		for(k=0;k<l;k++) {
			if(Tc[k][0].type > 0 && Tc[k][0].type <= 3) {
				pos=0;
				while(Tv[k][pos].type == 0 && pos<C) {
					pos++;
				}
				if(pos<C) {
					Tv[k][pos].life-=Tc[k][0].life;
					Tc[k][0].life--;
				}
			}else {
				break;
			}
		}
		//jeu pour virus
		for(i=0;i<l;i++) {
			if(res == -1)
				break;
			for(k=0;k<C;k++) {
				if(Tv[i][k].type < 0 ) {
					Tv[i][k].life--;
					if(Tv[i][k].life == 0) {
						Tv[i][k].type = 0;
						continue;
					} else {
						if(k - Tv[i][k].speed >= 0) {
							Virus tmp;
							tmp = Tv[i][k];
							Tv[i][k] = Tv[i][k - Tv[i][k].speed];
							Tv[i][k - Tv[i][k].speed] = tmp;
						} else {
							res=-1;
							break;
						}
					}
				}
			}
		}
		j++;
		printf("************\n");
	}
	
	if(j <= g.turn) 
		printf("lost\n");
	else 
		printf("******* win ********\n") ;
	
	printf("terminer");
	return 0;

}
