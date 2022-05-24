#ifndef CHIPS_H
#define CHIPS_H

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

Chips cree_c(int ,int ,int ,int ,int );

#endif
