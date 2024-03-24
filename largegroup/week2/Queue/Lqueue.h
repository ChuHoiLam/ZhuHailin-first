#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include <conio.h>
#define MAXQUEUE 10
typedef struct Lqueue
{
    void *data[MAXQUEUE];      //数据域
    int front;
    int rear;
    int length;        //队列长度
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;
char datatype[MAXQUEUE];
int pri; 

void InitLQueue(LQueue *Q){
    int i;
    Q->
}
