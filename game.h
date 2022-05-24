#ifndef GAME_H
#define GAME_H

#include"virus.h"
#include"chips.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stddef.h>

typedef struct{
Virus* virus;
Chips* chips;
int turn;
int money;
}Game;


Game init_game();
unsigned vide_virus(Game);
void remplir_v(Virus *,Game *);
//void defiler(Virus *,Game);
void remplir_c(Chips*,Game *);
void defiler(Game );
Chips recherche(Game g,int e);


#endif
