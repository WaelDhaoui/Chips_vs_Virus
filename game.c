#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stddef.h>
#include"virus.h"
#include"chips.h"

typedef struct{
Virus* virus;
Chips* chips;
int turn;
int money;
}Game;

Game init_game() {
	Game g;
	g.virus = NULL;
	g.chips = NULL;
	g.turn = 8;
	g.money = 400;
	return g;
}
unsigned vide_virus(Game g) {
	return (g.virus == NULL);
}
void remplir_v(Virus *v,Game *g) {
	if(g->virus == NULL) {
		g->virus = v;
		v->next=NULL;
	}else{
		Virus * p;
		p=g->virus->next;
		while(p != NULL) {
			p=p->next;
		}
		p=v;
		v->next=NULL;
	}
}
void remplir_c(Chips* c,Game *g) {
	if(g->chips == NULL) {
		g->chips = c;
		c->next = NULL;
	}else {
		c->next = g->chips;
		g->chips = c;
	}
}
void defiler(Game g) {
	if(!vide_virus(g)) {
		Virus *p;
		p=g.virus;
		g.virus->next =NULL;
		g.virus = p->next;
	}
}
Chips recherche(Game g,int e) {
	Chips c;
	c=*(g.chips);
	do {
		if(c.type == e) {
			return c;
		}
		c=*(c.next);
	}while(c.next != NULL); 
}

