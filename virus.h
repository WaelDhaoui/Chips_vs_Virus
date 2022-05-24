#ifndef VIRUS_H
#define VIRUS_H

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

Virus cree_v(int ,int ,int ,char* );
#endif
