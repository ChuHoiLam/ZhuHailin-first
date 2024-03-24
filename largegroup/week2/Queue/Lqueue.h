#define LQUEUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include <conio.h>

#define MAXQUEUE 10
typedef int Status;
typedef struct Lqueue
{
    void *data[MAXQUEUE];      //数据域
    int front;
    int rear;
    int length;        //队列长度
} LQueue;

/*typedef enum
{
    FALSE=0, TRUE=1
} Status;*/

char type;
char datatype[MAXQUEUE];
int pri; 

void InitLQueue(LQueue *Q){
    int i;
    Q->length = MAXQUEUE;
    for(i = 0; i < MAXQUEUE; i++){
        Q->data[i] = (void *)malloc(60);
    }

    Q->front = Q->rear = 0;
}

int LengthLQueue(LQueue *Q){
    return(Q->rear - Q->front + Q->length) % Q->length;
}

void DestoryLQueue(LQueue *Q){ //销毁队列所有节点数据
    int i = 0;
    
    while(Q->length--) 
        free(Q->data[i++]);
    
    Q->data[0] = NULL;
}

Status IsFullLQueue(const LQueue *Q){ //判断是否为满
    if(LengthLQueue(Q) == MAXQUEUE - 1){
       return 1;
    } else {
        return 0;
    }
}

Status IsEmptyLQueue(const LQueue *Q){ //判断是否为空
     return LengthLQueue(Q) == 0 ? 1 : 0;
}

Status GetHeadLQueue(LQueue *Q, void *e){ //获取头元素
	if (IsEmptyLQueue(Q)) {
		return 0;
	}

	int typeSize;
	if(datatype[0] == 'i') {
		typeSize = sizeof(int);
	} else if(datatype[0] == 'd') {
		typeSize = sizeof(double);
	} else if(datatype[0] == 'c') {
		typeSize = sizeof(char);
	} else {
		typeSize = sizeof(Q->data[0]);
	}
	memcpy(e,Q->data[0],typeSize);
	return 1;
}

Status EnLQueue(LQueue *Q, void *data){ //节点入列
	if (IsFullLQueue(Q))  return 0;
	
    memcpy(Q->data[Q->rear], data, 20);
	
    Q->rear = (Q->rear + 1) % MAXQUEUE;
	Q->length++;
	return 1;
}

Status DeLQueue(LQueue *Q){ //删除节点
	if (IsEmptyLQueue(Q))
     {
       
         return 0;
     }
     Q->front = (Q->front+1)%MAXQUEUE;
     Q->length--;
     return 1;
}

void ClearLQueue(LQueue *Q){ //清空队列
	Q->front = Q->rear = 0;
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){ //遍历以及打印
	pri = 0;
	if (IsEmptyLQueue(Q)) {
		
		return 1;
	}
	int i = 0;
	
	while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
		foo(Q->data[Q->front+i]);
		i = (i + 1) % MAXQUEUE;
	}
	printf("\n");
	return 0;
}

void LPrint(void *q)
{
	if(datatype[pri] == 'i') {
		printf("%d  ",*(int*)q);
		pri++;
	} else if(datatype[pri] == 'd') {
		printf("%.2f  ",*(double*)q);
		pri++;
	}
	else if (datatype[pri] == 'c') {
		printf("%c  ", *(char*)q);
		pri++;
	}
}
