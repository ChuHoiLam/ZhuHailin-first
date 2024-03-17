#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include <conio.h>
#define Len sizeof(struct event)    //Len为结构体的长度 
typedef  struct event Event;        //重命名结构体

//以下为简化获取模型
struct event {
    char data[100];
    struct event *next;
};

Event *getnode(Event *head){ //获取节点
     Event *new, *tail;                //定义结构体节点指针(new)&尾引导指针(tail)
     tail = new = (Event *)malloc(Len);      //赋予结构体结点指针空间&地址,new & tail 指向该地址
    
    printf("Please input the data (enter to stop it):> ");
    gets(new->data);
    fflush(stdin);  

    while(strlen(new->data)){

        if(head == NULL){
            head = new;
        }
        else{
            tail->next = new;
            tail = new;
        }

        new = (Event *)malloc(Len);
        printf("Please input the data (enter only to exit):> ");
        gets(new->data);
        fflush(stdin);
    }

    free(new);
    tail->next = NULL;
    return(head);
}
//以下为简化反转模型（尚未应用到主程序中）
Event *UpsideDown(Event *head)
{
	int a = 0;
	Event *p1 = head, *p2 = head, *p3 = head;//p3正向遍历,p2与p1反向连接
	while (p3 != NULL)
	{
		a++;
		p2 = p3;
		p3 = p3->next;
		if (p3 == NULL) head = p2; //将头指针倒置
		if (a == 1) tail = p1, p1->next = NULL;
		else p2->next = p1;
		p1 = p2;
	}
    return(head)
	printf("链表已反转\n");
}
