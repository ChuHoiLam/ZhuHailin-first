#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include <conio.h>
#define Len sizeof(struct event)    //Len为结构体的长度 
typedef  struct event Event;        //重命名结构体
#include"qg1_2.h"

int main(){
    Event *duhead,*read;
    duhead = getnode(duhead = NULL);
    read = duhead;
    int nu = 1;
    while(read){
        printf("data NO.%d: ",nu++);
        printf("%s\n",read->data);
        read = read->next;
    }
}
