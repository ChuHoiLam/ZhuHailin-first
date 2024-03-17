#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include <conio.h>
#define Len sizeof(struct event)    //Len为结构体的长度 
typedef  struct event Event;        //重命名结构体

struct event {
    struct event *front;
    char data[100];
    struct event *next;
};

Event *getnode(Event *duhead){
    Event *follow, *new;
    follow = new = (Event*)malloc(Len);

    printf("Please intput data(enter only to exit):> ");
    gets(new->data);
    fflush(stdin);

    while(strlen(new->data)){
        
        if(duhead == NULL){ 
            new->front = NULL;
            new->next = NULL;
            duhead = new;
        }else{
            follow->next = new;  //连接新节点
            new->front = follow; //反向连接旧节点
            new->next = NULL;    //新节点next指针指向null
            follow = follow->next; //follow指向新节点（便于新节点反向连接）
        }
        
        new = (Event*)malloc(Len);
        printf("Please intput data(enter only to exit):> ");
        gets(new->data);
        fflush(stdin);
    }

    free(new); //释放申请的冗余空间
    return(duhead);
}
