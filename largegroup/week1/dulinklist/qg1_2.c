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
            follow->next = new;
            new->front = follow;
            new->next = NULL; 
            follow = follow->next;
        }
        
        new = (Event*)malloc(Len);
        printf("Please intput data(enter only to exit):> ");
        gets(new->data);
        fflush(stdin);
    }

    free(new);
    return(duhead);
}
