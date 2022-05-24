#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stddef.h>

typedef struct chips{
int type;
int life;
int line;
int position;
int price;
struct chips* next;
}Chips;

Chips cree_c(int ty,int vie,int l,int p,int pr) {
	Chips c;
	c.type = ty;
	c.life = vie;
	c.line = l;
	c.position = p;
	c.price =pr;
	return c;
}

