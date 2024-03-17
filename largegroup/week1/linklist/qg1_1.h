#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include <conio.h>
#define Len sizeof(struct event)    //Len为结构体的长度 
typedef  struct event Event;        //重命名结构体

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
//
//
//以下是详细代码
char menu[7][60] = {                 //总菜单的字符串组
     "|          [A] Set new events             |",
     "|          [B] Modify events              |",
     "|          [C] Delete events              |",
     "|          [D] Check the list             |",
     "|          [E] Search the events          |",
     "|          [F] Set reminder               |",
     "|          [G] Exit                       |",
};
char srchmenu[5][60] = {            //检索类别选择菜单
     "|          [A] By Starttime               |",
     "|          [B] By Endtime                 |",
     "|          [C] By Reminder                |",
     "|          [D] By Eventdate               |",
     "|          [E] Exit                       |",
};
char modimenu[7][60] = {
     "|          [A] Modify Startime            |",
     "|          [B] Modify Endtime             |",
     "|          [C] Modify Reminder            |",
     "|          [D] Modify discription         |",
     "|          [E] Modify Location            |",
     "|          [F] Modify Date                |",
     "|          [G] Exit                       |",
};
struct date {                        //设定起始日期 终止日期结构体
     int year;                  //年
     int month;                 //月
     int day;                   //天
};
struct reminder {                    //设定 提醒日期及具体时间
     int ryear;                  //年
     int rmonth;                 //月
     int rday;                   //天
     int rhour;                  //时
     int rmins;                  //分
     int rsecd;                  //秒
};
struct time{
     int thour;
     int tmins;
};
struct event {                       //事件的结构体
    char discription[800];    //事件描述    
    Date eventdate;           //事件日期
    Time startTime;           //起始时间
    Time endTime;             //终止时间
    char location[30];        //地点
    Remd reminder;            //设置提醒时间
    Event *next;
};

//获取总事件表
Event *getevent(Event *head){          //&开设新事件

     Event *new, *tail;                //定义结构体节点指针(new)&尾引导指针(tail)
     tail = new = (Event *)malloc(Len);      //赋予结构体结点指针空间&地址,new & tail 指向该地址
     
     
     printf("Discription of the event (within 800 letters):\n");
     gets(new->discription);
     fflush(stdin);                      //清除缓冲区

     if (strlen(new->discription) == 0){          //输入第一个成员，如果为空则退出函数。
         free(new);
         return (0);
     }
     
     while(strlen(new->discription) != 0){
          Remd reminder = {0};
          printf("Date of the event\n");
          printf("< Year (YYYY)>: ");
          scanf("%d",&new->eventdate.year);                //获取事件日期(第二个成员)
          printf("< Month (MM)>:  ");
          scanf("%d",&new->eventdate.month);
          printf("< Day (DD)>:    ");
          scanf("%d",&new->eventdate.day);
          
          printf("Starttime of the event\n");
          printf("< Hour (HH)>:  ");
          scanf("%d",&new->startTime.thour);                 //获取起始时间(第三个成员)
          printf("< Minute (MM)>:");
          scanf("%d",&new->startTime.tmins);
          
          printf("Endtime of the event\n");
          printf("< Hour (HH)>:  ");
          scanf("%d",&new->endTime.thour);                   //获取终止时间(第四个成员)
          printf("< Minute (MM)>:");
          scanf("%d",&new->endTime.tmins);
          getchar();
          
          printf("Location of the event (within 30 letters):\n");
          gets(new->location);                          //获取事件地点(第五个成员)
          if (strlen(new->location) == 0){
               new->location[0] = '\0';
          }

          printf("Set a reminder for the event\n");
          printf("< Year > (Input 0 to exit): ");               //设定提醒时间（选填）
               scanf("%d",&new->reminder.ryear);
               while (1) {
                    if (new->reminder.ryear == 0) {
                         new->reminder.rhour = 0;
                         new->reminder.rmonth = 0;
                         new->reminder.rday = 0;
                         new->reminder.rmins = 0;
                         new->reminder.rsecd = 0;
                         printf("Not setting the reminder.\n"); 
                         break;
                    }
                    else {
                        printf("< Month >  :");
                        scanf("%d",&new->reminder.rmonth);
                        printf("< Day >    :");
                        scanf("%d",&new->reminder.rday);
                        printf("< Hour >   :");
                        scanf("%d",&new->reminder.rhour);
                        printf("< Minute > :");
                        scanf("%d",&new->reminder.rmins);
                        printf("< Second > :");
                        scanf("%d",&new->reminder.rsecd);
                        break;
                    }
               }                                                
                                 
          if (head == NULL){
             head = new;
          }
          else {
             tail->next = new;
             tail = new;                    
          }
          
          new = (Event*)malloc(Len);               //申请空间
          
          fflush(stdin);                           //清除缓冲区的回车键
          printf("\nDiscription of the event\n");
          gets(new->discription);
     
     }                                             //以上为输入结构体部分
     
     
     tail->next = NULL;                            //当输入事件描述为空时，结束输入循环,并使最后一个event的next指针指向NULL
     free(new);
     printf(">>>> Successfully set new events! >>>>\n");

     return (head);                                  //函数返回值为新输入的链表

}
//插入新事件（表）
Event *inst(Event *head, Event *snew){ //&新建stu链表，插入原有的head链表 //snew必须为空，建立一个新链表, 引用函数前 stu = NULL！
     
     printf("    ***************************\n");
     printf("\n<< Please set new events: >> \n");  
     snew = getevent(NULL);
     Event *p0;                     //定位指针
     
     if (snew == NULL) {printf("No data to insert.\n"); return(head);} 
     //如新链表为空，返回原链表
     else if (snew != NULL && head == NULL) {head = snew; return(head);}
     //如果原链表为空，head指向新链表
     else if (head){

          p0 = head;
          while(p0->next){              
               p0 = p0->next;               //定位指针指向最后一个event
          }
          p0->next = snew;                  //连接新老链表
          
     }
     return (head);
}
//（按时间大小）陈列事件
int checklist(Event *head){           //列出所有的事件
     
     Event *present, *p0;
     present = head;
     p0 = head;
     Event *current = head;
     if (head == NULL) {printf("\n>>>> NO EVENTS! >>>>\n"); return 0;}

     while(p0->next){                //采用冒泡法先按年份排序
          present = p0;              //让动指针指向定指针
          
          while(present){
               if (((p0->eventdate.year*365 + p0->eventdate.month*30 + p0->eventdate.day)*24 + p0->startTime.thour)*60 + p0->startTime.tmins > 
                   ((present->eventdate.year*365 + present->eventdate.month*30 + present->eventdate.day)*24 + present->startTime.thour)*60 + present->startTime.tmins){      //互换数据
                    Event *temp = (Event*)malloc(Len);
                    
                    strcpy(temp->discription, p0->discription);       //复制到temp；
                    strcpy(temp->location, p0->location);
                    temp->startTime = p0->startTime;
                    temp->endTime = p0->endTime;
                    temp->eventdate = p0->eventdate;
                    temp->reminder = p0->reminder;

                    strcpy(p0->discription, present->discription);    //present复制到p0；
                    strcpy(p0->location, present->location);
                    p0->startTime = present->startTime;
                    p0->endTime = present->endTime;
                    p0->eventdate = present->eventdate;
                    p0->reminder = present->reminder;

                    strcpy(present->discription, temp->discription);   //temp复制到present；
                    strcpy(present->location, temp->location);
                    present->startTime = temp->startTime;
                    present->endTime = temp->endTime;
                    present->eventdate = temp->eventdate;
                    present->reminder = temp->reminder;
               }
               present =present->next;
          }
          p0 = p0->next;
     }
     
     int n = 1;                                                     //初始化事件编号

          printf("\n    ****************EVENTS*****************\n\n");
     while(current != NULL){
          printf("      ----------Event%d---------\n",n++);
          printf("           < Discription >\n           %s\n",current->discription);
          printf("      Date     :  %02d/%02d/%02d\n",current->eventdate.month, current->eventdate.day, current->eventdate.year);
          printf("      Starttime:  %02d:%02d\n",current->startTime.thour, current->startTime.tmins);
          printf("      Endtime  :  %02d:%02d\n",current->endTime.thour, current->endTime.tmins);
          printf("      Location :  %s\n",current->location);
          if (current->reminder.ryear == 0) printf("      You haven't set any reminder for this event yet.\n");
          else
          printf("      Reminder :  %02d/%02d/%02d %02d:%02d:%02d\n",current->reminder.rmonth, current->reminder.rday, current->reminder.ryear, current->reminder.rhour, current->reminder.rmins, current->reminder.rsecd);
          printf("\n");
          current = current->next;
     }
     printf("    ***************************************\n");
     printf("\n    ");
     printf(">>>> PRESS ANY DIRECTION KEY TO MAIN MENU >>>>\n");

     return 0;
}

//检索功能函数
Event *srchstarTime(Event *head){              //*形参为你要搜寻数据所在链表 返回值为符合要求的事件（表）`
     
     Time iwant;                               //寻找的起始时间的Time型
     Event *search = NULL;                     //已过滤事件（表）
     Event *newboo, *tail;                     //定义结构体指针(newboo)&尾引导指针(tail)
     newboo = (Event*)malloc(Len);             //赋予search空间 
     tail = newboo;                            //并让tail指向newboo;

     printf("\nYou are searching by the STARTTIME of the events...\n");
     printf("Please input HOUR: ");           //输入查找的小时
     scanf("%d",&iwant.thour);

     printf("Please input MINUTE: ");          //输入查找的分钟
     scanf("%d",&iwant.tmins);
     
     fflush(stdin);                           //清除缓冲区的回车键
     Event *current;
     current = head;                          //引导指针(current)指向总事件表
     
     while(current){            
          if (current->startTime.thour == iwant.thour){              //筛选出符合要求的事件
               
               if (current->startTime.tmins == iwant.tmins){
                    
                    strcpy(newboo->discription, current->discription);       //复制到newboo；
                    strcpy(newboo->location, current->location);
                    newboo->startTime = current->startTime;
                    newboo->endTime = current->endTime;
                    newboo->eventdate = current->eventdate;
                    newboo->reminder = current->reminder;
                        
                    if(!search) search = newboo;                            //search指向已过滤事件（表）的首事件
                    else{
                         tail->next = newboo;
                         tail = newboo;                                          //尾指针在此处更新
                    } 
                    tail->next = NULL;     
                    newboo = (Event*)malloc(Len);                               //赋予search空间 
                    current = current->next;
                    
               }
               else current = current->next;
          }
          else current = current->next;
     }

     free(newboo);                                //释放search的空间
     if(search == NULL){
          printf(">>>> NOT FOUND 404 >>>>\n>>>> PRESS ANY DIRECTION KRY TO MAIN MENU >>>>\n>>>> PRESS ENTER TO LAST MANU >>>>\n");
     }

     return(search);
     
}

Event *srchendTime(Event *head){                //*形参为你要搜寻数据所在链表 返回值为符合要求的事件（表）
     
     Time iwant;                               //寻找的起始时间的Time型
     Event *search = NULL;                     //已过滤事件（表）
     Event *newboo, *tail;                     //定义结构体指针(newboo)&尾引导指针(tail)
     newboo = (Event*)malloc(Len);             //赋予search空间 
     tail = newboo;                            //并让tail指向newboo;

     printf("\nYou are searching by the ENDTIME of the events...\n");
     printf("< Please input HOUR:  ");           //输入查找的小时
     scanf("%d",&iwant.thour);

     printf("< Please input MINUTE: ");           //输入查找的分钟
     scanf("%d",&iwant.tmins);
     
     fflush(stdin);                           //清除缓冲区的回车键
     Event *current;
     current = head;                          //引导指针(current)指向总事件表
     
     while(current){            
          if (current->endTime.thour == iwant.thour){              //筛选出符合要求的事件
               
               if (current->endTime.thour == iwant.tmins){
                      
                    strcpy(newboo->discription, current->discription);       //复制到newboo；
                    strcpy(newboo->location, current->location);
                    newboo->startTime = current->startTime;
                    newboo->endTime = current->endTime;
                    newboo->eventdate = current->eventdate;
                    newboo->reminder = current->reminder;
                        
                    if(!search) search = newboo;                            //search指向已过滤事件（表）的首事件
                    else{
                         tail->next = newboo;
                         tail = newboo;                                          //尾指针在此处更新
                    } 
                    tail->next = NULL;     
                    newboo = (Event*)malloc(Len);                               //赋予search空间 
                    current = current->next;
               }
               else current = current->next;
          }
          else current = current->next;
     }

     free(newboo);                                //释放search的空间
     if(search == NULL){
          printf(">>>> NOT FOUND 404 >>>>\n>>>> PRESS ANY DIRECTION KRY TO MAIN MENU >>>>\n>>>> PRESS ENTER TO LAST MANU >>>>\n");
     }
     return(search);
}

Event *srchreminder(Event *head){              //*形参为你要搜寻数据的所在链表 返回值为符合要求的事件（表）
     
     Remd iwant;                               //寻找的起始时间的Remd型
     Event *search = NULL;                     //已过滤事件（表）
     Event *newboo, *tail;                     //定义结构体指针(newboo)&尾引导指针(tail)
     newboo = (Event*)malloc(Len);             //赋予search空间 
     tail = newboo;                            //并让tail指向newboo;
     

     printf("\nYou are searching by the REMINDER(fine to the hour) of the event...\n");
     printf("< Please input year:  ");           //输入查找的年份
     scanf("%d",&iwant.ryear);

     printf("< Please input month: ");          //输入查找的月份
     scanf("%d",&iwant.rmonth);

     printf("< Please input day:   ");           //输入查找的日子
     scanf("%d",&iwant.rday);

     printf("< Please input the hour: ");         //输入查找的钟点数
     scanf("%d",&iwant.rhour);
     
     fflush(stdin);                           //清除缓冲区的回车键
     Event *current;
     current = head;                          //引导指针(current)指向总事件表
     
     while(current){            
          if (current->reminder.ryear == iwant.ryear){              //筛选出符合要求的事件
               
               if (current->reminder.rmonth == iwant.rmonth){
                    
                    if (current->reminder.rday == iwant.rday){   
                       
                         if(current->reminder.rhour == iwant.rhour){
                              
                              strcpy(newboo->discription, current->discription);       //复制到newboo；
                              strcpy(newboo->location, current->location);
                              newboo->startTime = current->startTime;
                              newboo->endTime = current->endTime;
                              newboo->eventdate = current->eventdate;
                              newboo->reminder = current->reminder;
                         
                              if(!search) search = newboo;                            //search指向已过滤事件（表）的首事件
                              else{
                               tail->next = newboo;
                               tail = newboo;                                          //尾指针在此处更新
                              }   
                              tail->next = NULL;
                              newboo = (Event*)malloc(Len);                               //赋予search空间 
                              current = current->next;
                         }
                    }
                    else current = current->next;
               }
               else current = current->next;
          }
          else current = current->next;
     }

     free(newboo);                                //释放search的空间
     if(search == NULL){
          printf(">>>> NOT FOUND 404 >>>>\n>>>> PRESS ANY DIRECTION KRY TO MAIN MENU >>>>\n>>>> PRESS ENTER TO LAST MANU >>>>\n");
     }
     return(search);
}

Event *srcheventdate(Event *head){
     
     Date iwant;                               //寻找的起始时间的Date型
     Event *search = NULL;                     //已过滤事件（表）
     Event *newboo, *tail;                     //定义结构体指针(newboo)&尾引导指针(tail)
     newboo = (Event*)malloc(Len);             //赋予search空间 
     tail = newboo;                            //并让tail指向newboo;

     printf("\nYou are searching by the DATE of the events...\n");
     printf("< Please input YEAR:  ");           //输入查找的年份
     scanf("%d",&iwant.year);

     printf("< Please input MONTH: ");           //输入查找的月份
     scanf("%d",&iwant.month);
     
     printf("< Please input DAY:   ");           //输入查找的日子
     scanf("%d",&iwant.day);

     fflush(stdin);                           //清除缓冲区的回车键
     Event *current;
     current = head;                          //引导指针(current)指向总事件表
     
     while(current){            
          if (current->eventdate.year == iwant.year){              //筛选出符合要求的事件
               
               if (current->eventdate.month == iwant.month){
                      
                    if(current->eventdate.day == iwant.day){
                       
                         strcpy(newboo->discription, current->discription);       //复制到newboo；
                         strcpy(newboo->location, current->location);
                         newboo->startTime = current->startTime;
                         newboo->endTime = current->endTime;
                         newboo->eventdate = current->eventdate;
                         newboo->reminder = current->reminder;
                        
                         if(!search) search = newboo;                            //search指向已过滤事件（表）的首事件
                         else{
                             tail->next = newboo;
                             tail = newboo;                                          //尾指针在此处更新
                         } 
                         tail->next = NULL;     
                         newboo = (Event*)malloc(Len);                               //赋予search空间 
                         current = current->next;

                    }
                    else current = current->next;
               }
               else current = current->next;
          }
          else current = current->next;
     }

     free(newboo);                                //释放search的空间
     if(search == NULL){
          printf(">>>> NOT FOUND 404 >>>>\n>>>> PRESS ANY DIRECTION KRY TO MAIN MENU >>>>\n>>>> PRESS ENTER TO LAST MANU >>>>\n");
     }
     return(search);

}

Event *srchdiscrition(Event *head){ //**形参为你要搜寻数据的所在链表 返回值为符合要求的事件（表）
     char discription[100]={0};
     printf("Please input the discription of the event to search:\n");
     gets(discription);
     Event *search = head;                //search指针指向head首事件
     Event *target = NULL;                //记录指针先指向空
     int i = 0;
     
     if(strlen(discription) == 0){
        exit (0);
     }
     
     while(search){
          for (i = 0; discription[i] != '\0'; i++){
             if(search->discription[i] == discription[i]){
                
             }
          }
     }

}

Event *srchlocation(Event *head){   //**形参为你要搜寻数据的所在链表 返回值为符合要求的事件（表）
     
}


//修改功能函数
Event *modifystartTime(Event *head, Event *search){   //*修改开始时间 总事件表 已过滤的事件（表） 返回值为修改后的总事件表 
     printf("\n< Modifying the STARTTIME... >\n");
     Event *modified = head;                         //引导指针 指向总事件表首位

     if(!search){                                    //如果检索的事件（表）为空
       printf("\n****NO DATA!****\n");
       return (head);
     }

     else if(search->next){                          //当已过滤事件多于一件时
          int n = 0, i = 1;
          checklist(search);                           
          printf("\nPlease choose the event (input its number) you want to modify(input 0 to exit):> ");
          scanf("%d",&n);
          fflush(stdin);                           //清除缓冲区的回车键
          if (n == 0){                                //选择退出（输入0）后返回值为原总事件表
               printf("\n      Exit...\n");
               return(head);                        
          }
         
          Event *target = search;                     //标记指针(target)指向被选中的事件(search所指向的已过滤表不变)
          
          for (i = 1; i < n; i++){
             target = target->next;
          }
          
          while (modified){                           //在总事件表中搜寻目标
               if(modified->startTime.thour == target->startTime.thour){
                  
                  if(modified->startTime.tmins == target->startTime.tmins){

                    printf("\n**Please modify the starttime of the event:>\n");
                    printf("< Hour (HH)>:   ");
                    scanf("%d",&modified->startTime.thour);                //直接覆盖原数据
                    printf("< Minute (MM)>: ");
                    scanf("%d",&modified->startTime.tmins);
                    printf("\nModification is done!\n");
                    return(head);
                    break;
                    
                   }
                  else modified = modified->next;
               }
               else modified = modified->next;
          }
          
     }         
     
     else if(search->next == NULL){                   //已过滤事件唯一时
          Event *target = search;
          checklist(search);

          while (modified){                           //在总事件表中搜寻目标
               if(modified->startTime.thour == target->startTime.thour){
                  
                  if(modified->startTime.tmins == target->startTime.tmins){

                    printf("\n**Please modify the starttime of the event:>\n");
                    printf("< Hour (HH)>:   ");
                    scanf("%d",&modified->startTime.thour);                //直接覆盖原数据
                    printf("< Minute (MM)>: ");
                    scanf("%d",&modified->startTime.tmins);
                    printf("\nModification is done!\n");
                    return(head);
                    break;
                    
                   }
                  else modified = modified->next;
               }
               else modified = modified->next;
          }

     }

     printf(">>>> PRESS ANY DIRECTION KRY TO MAIN MENU >>>>\n>>>> PRESS ENTER TO LAST MANU >>>>\n");

}

Event *modifyendTime(Event *head, Event *search){   //*修改终止时间 总事件表 已过滤的事件（表） 返回值为修改后的总事件表
     printf("\n< Modifying the ENFTIME... >\n");
     Event *modified = head;                         //引导指针 指向总事件表首位

     if(!search){                                    //如果检索的事件（表）为空
       printf("\n****NO DATA!****\n");
       return (head);
     }

     else if(search->next){                          //当已过滤事件多于一件时
          int n = 0, i = 1;
          checklist(search);                         //陈列出已过滤的事件表  
          printf("\nPlease choose the event (input its number) you want to modify(input 0 to exit):> ");
          scanf("%d",&n);
          fflush(stdin);                           //清除缓冲区的回车键
          if (n == 0){                                //选择退出（输入0）后返回值为原总事件表
               printf("\n      Exit...\n");
               return(head);                        
          }
         
          Event *target = search;                     //标记指针(target)指向被选中的事件(search所指向的已过滤表不变)
          
          for (i = 1; i < n; i++){
             target = target->next;
          }
          
          while (modified){                           //在总事件表中搜寻目标
               if(modified->endTime.thour == target->endTime.thour){
                  
                  if(modified->endTime.tmins == target->endTime.tmins){

                    printf("\n**Please modify the enftime of the event:>\n");
                    printf("< Hour (HH)>:   ");
                    scanf("%d",&modified->endTime.thour);                //直接覆盖原数据
                    printf("< Minute (MM)>: ");
                    scanf("%d",&modified->endTime.tmins);
                    printf("\nModification is done!\n");
                    return(head);
                    break;
                    
                   }
                  else modified = modified->next;
               }
               else modified = modified->next;
          }
          
     }         
     
     else if(search->next == NULL){                   //已过滤事件唯一时
          Event *target = search;
          checklist(search);

          while (modified){                           //在总事件表中搜寻目标
              if(modified->endTime.thour == target->endTime.thour){
                  
                  if(modified->endTime.tmins == target->endTime.tmins){

                    printf("\n**Please modify the enftime of the event:>\n");
                    printf("< Hour (HH)>:   ");
                    scanf("%d",&modified->endTime.thour);                //直接覆盖原数据
                    printf("< Minute (MM)>: ");
                    scanf("%d",&modified->endTime.tmins);
                    printf("\nModification is done!\n");
                    return(head);
                    break;
                    
                   }
                  else modified = modified->next;
               }
               else modified = modified->next;
          }
     }
     
     printf(">>>> PRESS ANY DIRECTION KRY TO MAIN MENU >>>>\n>>>> PRESS ENTER TO LAST MANU >>>>\n");
}

Event *modifyremindertime(Event *head, Event *search){   //*修改提醒时间 总事件表 已过滤的事件（表） 返回值为修改后的总事件表
     printf("\n< Modifying the REMINDER... >\n");
     Event *modified = head;                         //引导指针 指向总事件表首位

     if(!search){                                    //如果检索的事件（表）为空
       printf("\n****NO DATA!****\n");
       return (head);
     }

     else if(search->next){                          //当已过滤事件多于一件时
          int n = 0, i = 1;
          checklist(search);                         //陈列出已过滤的事件表  
          printf("\nPlease choose the event (input its number) you want to modify(input 0 to exit):> ");
          scanf("%d",&n);
          fflush(stdin);                           //清除缓冲区的回车键
          if (n == 0){                                //选择退出（输入0）后返回值为原总事件表
               printf("\n      Exit...\n");
               return(head);                        
          }
         
          Event *target = search;                     //标记指针(target)指向被选中的事件(search所指向的已过滤表不变)
          
          for (i = 1; i < n; i++){
             target = target->next;
          }
          
          while (modified){                           //在总事件表中搜寻目标
               if(modified->reminder.ryear == target->reminder.ryear){
                  
                  if(modified->reminder.rmonth == target->reminder.rmonth){

                      if(modified->reminder.rday == target->reminder.rday){

                         if(modified->reminder.rhour == target->reminder.rhour){
                              
                              if(modified->reminder.rmins == target->reminder.rmins){
                                   
                                   if(modified->reminder.rsecd == target->reminder.rsecd){
                                        printf("\n**Please modify the reminder of the event:>\n");
                                        printf("< Year (YYYY)>: ");
                                        scanf("%d",&modified->reminder.ryear);                //直接覆盖原数据
                                        printf("< Month (MM)>:  ");
                                        scanf("%d",&modified->reminder.rmonth);
                                        printf("< Day (DD)>:    ");
                                        scanf("%d",&modified->reminder.rday);
                                        printf("< Hour (HH)>:   ");
                                        scanf("%d",&modified->reminder.rhour);
                                        printf("< Minute (mm)>: ");
                                        scanf("%d",&modified->reminder.rmins);
                                        printf("< Second (SS)>: ");
                                        scanf("%d",&modified->reminder.rsecd);
                                        printf("\n**Modification is done!**\n");
                                        return(head);                                       //返回修改后的总事件表
                                        break;
                                   }
                                   else modified = modified->next;
                              }
                              else modified = modified->next;
                         }
                         else modified = modified->next;
                      } 
                      else modified = modified->next;
                   }
                  else modified = modified->next;
               }
               else modified = modified->next;
          }
          
     }         
     
     else if(search->next == NULL){                   //已过滤事件唯一时
          Event *target = search;
          checklist(search);

          while (modified){                           //在总事件表中搜寻目标
               if(modified->reminder.ryear == target->reminder.ryear){
                  
                  if(modified->reminder.rmonth == target->reminder.rmonth){

                      if(modified->reminder.rday == target->reminder.rday){

                         if(modified->reminder.rhour == target->reminder.rhour){
                              
                              if(modified->reminder.rmins == target->reminder.rmins){
                                   
                                   if(modified->reminder.rsecd == target->reminder.rsecd){
                                        printf("\n**Please modify the reminder of the event:>\n");
                                        printf("< Year (YYYY)>: ");
                                        scanf("%d",&modified->reminder.ryear);                //直接覆盖原数据
                                        printf("< Month (MM)>:  ");
                                        scanf("%d",&modified->reminder.rmonth);
                                        printf("< Day (DD)>:    ");
                                        scanf("%d",&modified->reminder.rday);
                                        printf("< Hour (HH)>:   ");
                                        scanf("%d",&modified->reminder.rhour);
                                        printf("< Minute (mm)>: ");
                                        scanf("%d",&modified->reminder.rmins);
                                        printf("< Second (SS)>: ");
                                        scanf("%d",&modified->reminder.rsecd);
                                        printf("\n**Modification is done!**\n");
                                        return(head);                                       //返回修改后的总事件表
                                        break;
                                   }
                                   else modified = modified->next;
                              }
                              else modified = modified->next;
                         }
                         else modified = modified->next;
                      } 
                      else modified = modified->next;
                   }
                  else modified = modified->next;
               }
               else modified = modified->next;
          }
     }

     printf(">>>> PRESS ANY DIRECTION KRY TO MAIN MENU >>>>\n>>>> PRESS ENTER TO LAST MANU >>>>\n");
}

Event *modifydiscription(Event *head, Event *search){    //*修改事件描述 总事件表 已过滤的事件（表） 返回值为修改后的总事件表
     printf("\n< Modifying the DISCRIPTION... >\n");
     Event *modified = head;                         //引导指针 指向总事件表首位

     if(!search){                                    //如果检索的事件（表）为空
       printf("\n****NO DATA!****\n");
       return (head);
     }

     else if(search->next){                          //当已过滤事件多于一件时
          int n = 0, i = 1;
          checklist(search);                         //陈列出已过滤的事件表  
          printf("\nPlease choose the event (input its number) you want to modify(input 0 to exit):> ");
          scanf("%d",&n);
          fflush(stdin);                           //清除缓冲区的回车键
          if (n == 0){                                //选择退出（输入0）后返回值为原总事件表
               printf("\n      Exit...\n");
               return(head);                        
          }
         
          Event *target = search;                     //标记指针(target)指向被选中的事件(search所指向的已过滤表不变)
          
          for (i = 1; i < n; i++){
             target = target->next;
          }
          
          while (modified){                           //在总事件表中搜寻目标
               
               if(strcmp(modified->discription,target->discription) == 0){       //检测与target的事件描述是否相同
                    
                    printf("\n**Please modify the discription of the event:>\n");
                         printf("< Discription (Within 800 letters) >: ");
                         char temp[800];
                         gets(temp);
                         if(strlen(temp) == 0){                              //如输入事件描述为空
                            printf("\n**You didn't input any new discripton!\nThe previous discripton is preserved.\n");
                            return(head);
                            break;
                         }
                         else{
                             strcpy(modified->discription,temp);
                             printf("\n**Modofication is done!**\n");
                         }

                         return(head);                                       //返回修改后的总事件表
                         break;   
               }
               else modified = modified->next;
          }
     }         
     
     else if(search->next == NULL){                   //已过滤事件唯一时
          Event *target = search;
          checklist(search);

          while (modified){                           //在总事件表中搜寻目标
               if(strcmp(modified->discription,target->discription) == 0){       //检测与target的事件描述是否相同
                   printf("\n**Please modify the discription of the event:>\n");
                         printf("< Discription (Within 800 letters) >: ");
                         Sleep(40);
                         char temp[800];
                         gets(temp);
                         if(strlen(temp) == 0){                              //如输入事件描述为空
                            printf("\n**You didn't input any new discripton!\nThe previous discripton is preserved.\n");
                            return(head);
                            break;
                         }
                         else{
                             strcpy(modified->discription,temp);
                             printf("\n**Modofication is done!**\n");
                         }

                         return(head);                                       //返回修改后的总事件表
                         break;   
               }
               else modified = modified->next;
          }
     }

     printf(">>>> PRESS ANY DIRECTION KRY TO MAIN MENU >>>>\n>>>> PRESS ENTER TO LAST MANU >>>>\n");

}

Event *modifylocation(Event *head, Event *search){       //*修改事件地点 总事件表 已过滤的事件（表） 返回值为修改后的总事件表
     
     printf("\n< Modifying the LOCATION... >\n");
     Event *modified = head;                         //引导指针 指向总事件表首位

     if(!search){                                    //如果检索的事件（表）为空
       printf("\n****NO DATA!****\n");
       return (head);
     }

     else if(search->next){                          //当已过滤事件多于一件时
          int n = 0, i = 1;
          checklist(search);                         //陈列出已过滤的事件表  
          printf("\nPlease choose the event (input its number) you want to modify(input 0 to exit):> ");
          scanf("%d",&n);
          fflush(stdin);                           //清除缓冲区的回车键

          if (n == 0){                                //选择退出（输入0）后返回值为原总事件表
               printf("\n      Exit...\n");
               return(head);                        
          }
         
          Event *target = search;                     //标记指针(target)指向被选中的事件(search所指向的已过滤表不变)
          
          for (i = 1; i < n; i++){
             target = target->next;
          }
          
          while (modified){                           //在总事件表中搜寻目标
               
               if(strcmp(modified->location, target->location) == 0){       //检测与target的事件描述是否相同（函数返回值为0时触发）
                    
                    printf("\n**Please modify the location of the event:>\n");
                         printf("< Location (Within 30 letters) >: ");
                         Sleep(40);
                         char temp[30];
                         gets(temp);
                         if(strlen(temp) == 0){                              //如输入事件描述为空
                            printf("\n**You didn't input any new location!\nThe previous location is preserved.\n");
                            return(head);
                            break;
                         }
                         else{
                             strcpy(modified->location,temp);
                             printf("\n**Modofication is done!**\n");
                         }

                         return(head);                                       //返回修改后的总事件表
                         break;   
               }
               else modified = modified->next;
          }
     }         
     
     else if(search->next == NULL){                   //已过滤事件唯一时
          Event *target = search;
          checklist(search);

          while (modified){                           //在总事件表中搜寻目标
               if(strcmp(modified->location,target->location) == 0){       //检测与target的事件描述是否相同（函数返回值为0时触发）
                   printf("\n**Please modify the location of the event:>\n");
                         printf("< Location (Within 30 letters) >: ");
                         char temp[30];
                         gets(temp);
                         if(strlen(temp) == 0){                              //如输入事件描述为空
                            printf("\n**You didn't input any new location!\nThe previous location is preserved.\n");
                            return(head);
                            break;
                         }
                         else{
                             strcpy(modified->location,temp);
                             printf("\n**Modofication is done!**\n");
                         }

                         return(head);                                       //返回修改后的总事件表
                         break;   
               }
               else modified = modified->next;
          }
     }

     printf(">>>> PRESS ANY DIRECTION KRY TO MAIN MENU >>>>\n>>>> PRESS ENTER TO LAST MANU >>>>\n");
}

Event *modifyevendate(Event *head, Event *search){       //*修改事件日期 总事件表 已过滤的事件（表） 返回值为修改后的总事件表 
     printf("\n< Modifying the DATE... >\n");
     Event *modified = head;                         //引导指针 指向总事件表首位

     if(!search){                                    //如果检索的事件（表）为空
       printf("\n****NO DATA!****\n");
       return (head);
     }

     else if(search->next){                          //当已过滤事件多于一件时
          int n = 0, i = 1;
          checklist(search);                           
          printf("\nPlease choose the event (input its number) you want to modify(input 0 to exit):> ");
          scanf("%d",&n);
          fflush(stdin);                           //清除缓冲区的回车键
          if (n == 0){                                //选择退出（输入0）后返回值为原总事件表
               printf("\n      Exit...\n");
               return(head);                        
          }
         
          Event *target = search;                     //标记指针(target)指向被选中的事件(search所指向的已过滤表不变)
          
          for (i = 1; i < n; i++){
             target = target->next;
          }
          
          while (modified){                           //在总事件表中搜寻目标
               if(modified->eventdate.year == target->eventdate.year){
                  
                  if(modified->eventdate.month == target->eventdate.month){

                      if(modified->eventdate.day == target->eventdate.day){
                         printf("\n**Please modify the date of the event:>\n");
                         printf("< Year (YYYY)>: ");
                         scanf("%d",&modified->eventdate.year);                //直接覆盖原数据
                         printf("< Month (MM)>:  ");
                         scanf("%d",&modified->eventdate.month);
                         printf("< Day (DD)>:    ");
                         scanf("%d",&modified->eventdate.day);
                         printf("\n Modification is done!\n");
                         return(head);
                         break;
                      } 
                      else modified = modified->next;
                   }
                  else modified = modified->next;
               }
               else modified = modified->next;
          }
          
     }         
     
     else if(search->next == NULL){                   //已过滤事件唯一时
          Event *target = search;
          checklist(search);

          while (modified){                           //在总事件表中搜寻目标
               if(modified->eventdate.year == target->eventdate.year){
                  
                  if(modified->eventdate.month == target->eventdate.month){

                      if(modified->eventdate.day == target->eventdate.day){
                         printf("\n**Please modify the date of the event:>\n");
                         printf("< Year (YYYY)>: ");
                         scanf("%d",&modified->eventdate.year);                //直接覆盖原数据
                         printf("< Month (MM)>:  ");
                         scanf("%d",&modified->eventdate.month);
                         printf("< Day (DD)>:    ");
                         scanf("%d",&modified->eventdate.day);
                         printf("\n Modification is done!\n");
                         return(head);
                         break;
                      } 
                      else modified = modified->next;
                   }
                  else modified = modified->next;
               }
               else modified = modified->next;
          }

     }

     printf(">>>> PRESS ANY DIRECTION KRY TO MAIN MENU >>>>\n>>>> PRESS ENTER TO LAST MANU >>>>\n");
}

//删除功能函数
Event *delete(Event *head, Event *search){               //*删除已过滤事件（表）总事件表 已过滤的事件（表） 返回值为修改后的总事件表
     printf("\n< Deleting the event(s)... >\n");
     Event *delete;                    //引导指针指向总事件表
     delete = head;                    

     if(!search){                      //如果已过滤事件为空
          printf(">>>>>> Event Not Found! >>>>>>\n");
          return (head);
     }
     
     else if(search->next){           //如果已过滤事件不唯一
          
          checklist(search);          //陈列出所有事件（带编号）

          printf("\n>>> Input Y to delete all the selected events.\n");
            printf(">>> Input S to selsect events to delete.\n");
            printf(">>> Input other key to exit\n");
            printf(">>> Please input your decision:> ");
          
          char X = getchar();

          if(X != 'Y' && X != 'y' && X != 'S' && X != 's'){                     //退出删除
              printf("\n      Exit...\n");
              return (head);
          }

          else if(X == 'Y' || X == 'y'){                //删除所有已过滤事件
               Event *target = search;      //target记录需要删除的数据

               while(target){               //逐个删除已过滤事件表
                    
                    while(delete){          //检索总事件表

                         if(strcmp(delete->discription, target->discription) == 0){
                             
                              if(delete->eventdate.year == target->eventdate.year){
                                
                                   if(delete->startTime.thour == target->startTime.thour){
                                        
                                        if(delete->endTime.thour == target->endTime.thour){
                                             
                                             if(strcmp(delete->location, target->location) == 0){

                                                  if(delete->reminder.ryear == target->reminder.ryear){

                                                       if(delete->eventdate.month == target->eventdate.month){
                                                            
                                                            if(delete->eventdate.day == target->eventdate.day){

                                                                 if(delete->endTime.tmins == target->endTime.tmins){

                                                                      if(delete->startTime.tmins == target->startTime.tmins){

                                                                           if(delete->reminder.rmonth == target->reminder.rmonth){
                                                                                
                                                                                if(delete->reminder.rday == target->reminder.rday){
                                                                                     
                                                                                     if(delete->reminder.rhour == target->reminder.rhour){

                                                                                          if(delete->reminder.rmins == target->reminder.rmins){

                                                                                               if(delete->reminder.rsecd == target->reminder.rsecd){
                                                                                                  
                                                                                                    if(delete == head){                    //目标节点为首事件
                                                                                                         head = delete->next;
                                                                                                         free(delete);
                                                                                                         break;
                                                                                                    }

                                                                                                    else if(delete->next == NULL){          //事件不唯一，目标节点为尾事件
                                                                                                         Event *temp = head;                //建立临时指针 指向
                                                                                                         while(temp->next != delete){
                                                                                                              temp = temp->next;
                                                                                                         } 
                                                                                                         temp->next = NULL;
                                                                                                         free(delete);
                                                                                                         break;                             //退出检索总事件表
                                                                                                    }

                                                                                                    else if(delete->next){                  //普通节点
                                                                                                         Event *temp = head;
                                                                                                         while(temp->next != delete){
                                                                                                              temp = temp->next;
                                                                                                         }
                                                                                                         temp->next = delete->next;
                                                                                                         free(delete);
                                                                                                         break;                               //退出检索总事件表
                                                                                                    }

                                                                                               }
                                                                                               else delete = delete->next;
                                                                                          }
                                                                                          else delete = delete->next;
                                                                                     }
                                                                                     else delete = delete->next;
                                                                                }
                                                                                else delete = delete->next;
                                                                           }
                                                                           else delete = delete->next;
                                                                      }
                                                                      else delete = delete->next;
                                                                 }
                                                                 else delete = delete->next;
                                                            }
                                                            else delete = delete->next;
                                                       }
                                                       else delete = delete->next; 
                                                  }
                                                  else delete = delete->next;
                                             }
                                             else delete = delete->next;
                                        }
                                        else delete = delete->next;
                                   }
                                   else delete = delete->next;
                              }
                             else delete = delete->next;
                         }
                         else delete = delete->next;
                    }
                    
                    delete = head;          //引导指针指向总事件表
                    target = target->next;  //引导指针指向总事件表（移向下一位）
               }
               free(search);
          }

          else if(X == 'S' || X == 's'){                //选择部分事件删除
               Event *count = search;       //数出已过滤事件数量
               int sum = 0;
               while(count){
                    sum++;
                    count = count->next;
               }

               printf("\n>>>Please choose events to delete...\n");
               printf("Delete event*(input 0 to stop ): ");                    //***************************
               int d[sum],    //数组记录需要删除事件的编号
                   dsum = 0,        //记录删除事件的总和
                   i = 0,           //数组下标
                   t = 1;           //中转值
               
                   for(int j = 0; j < sum; j++){  //初始化记录数组（为0）
                        d[j] = 0;
                    }
               
               while(t != 0){     //输入并纪录需要删除事件的编号到记录数组  

                    scanf("%d",&t);

                    if(t > sum || t < 0){
                         printf("\nPlease input number between 0 and %d\n",sum);
                         continue;
                    }

                    else if(i > sum - 1){
                         printf("\nToo many orders! You can delete up to %d events.\n",sum);
                         break;
                    }
                    
                    else{
                         d[i] = t;      //中转值传递给记录数组
                         if(t != 0){    //检测出输入值不为0才使删除事件总和+1
                              dsum++;
                              printf("<<< Event %d is selected.\n",t);
                              printf("Delete event*(input 0 to stop ): ");
                         }

                         if(t == 0) printf("\n<<< Selection is done!\n");
                         i++;
                    }
               }

               Event *select;                //选择指针（检索）
               select = search;              //指向已过滤事件表首事件（编号为1）
               Event *newboo = (Event*)malloc(Len), *tail;
               tail = newboo;
               Event *chosen = NULL;       //选出指针(最终选出的事件将存于此处)

               int S = 1;             //事件编号
               i = 0; 
               while(d[i] != 0){        //选出对应事件
                  select = search;
                  S = 1;

                  while(select){  
                     if(S == d[i]){     //当选择指针指向的事件编号与记录数组的号码相同时
                         strcpy(newboo->discription, select->discription);       //复制到newboo；
                         strcpy(newboo->location, select->location);
                         newboo->startTime = select->startTime;
                         newboo->endTime = select->endTime;
                         newboo->eventdate = select->eventdate;
                         newboo->reminder = select->reminder;

                         if(!chosen) chosen = newboo;
                         else{
                              tail->next = newboo;
                              tail = newboo;
                         }
                         tail->next = NULL;
                         newboo = (Event*)malloc(Len);
                         i++;                         //选中才让记录数组进位
                         break;
                    }
                    else {              //当选择指针指向的事件编号与记录数组的号码*不同时
                         S++;
                         select = select->next;       //选择指针进位（检索）S++
                    }
                  }
               }

               free(newboo);

               Event *target = chosen;      //target记录需要删除的数据

               while(target){               //逐个删除已过滤事件表
                    
                    while(delete){          //检索总事件表

                         if(strcmp(delete->discription, target->discription) == 0){
                             
                              if(delete->eventdate.year == target->eventdate.year){
                                
                                   if(delete->startTime.thour == target->startTime.thour){
                                        
                                        if(delete->endTime.thour == target->endTime.thour){
                                             
                                             if(strcmp(delete->location, target->location) == 0){

                                                  if(delete->reminder.ryear == target->reminder.ryear){

                                                       if(delete->eventdate.month == target->eventdate.month){
                                                            
                                                            if(delete->eventdate.day == target->eventdate.day){

                                                                 if(delete->endTime.tmins == target->endTime.tmins){

                                                                      if(delete->startTime.tmins == target->startTime.tmins){

                                                                           if(delete->reminder.rmonth == target->reminder.rmonth){
                                                                                
                                                                                if(delete->reminder.rday == target->reminder.rday){
                                                                                     
                                                                                     if(delete->reminder.rhour == target->reminder.rhour){

                                                                                          if(delete->reminder.rmins == target->reminder.rmins){

                                                                                               if(delete->reminder.rsecd == target->reminder.rsecd){
                                                                                                  
                                                                                                    if(delete == head){                    //目标节点为首事件
                                                                                                         head = delete->next;
                                                                                                         free(delete);
                                                                                                         break;
                                                                                                    }

                                                                                                    else if(delete->next == NULL){          //事件不唯一，目标节点为尾事件
                                                                                                         Event *temp = head;                //建立临时指针 指向
                                                                                                         while(temp->next != delete){
                                                                                                              temp = temp->next;
                                                                                                         } 
                                                                                                         temp->next = NULL;
                                                                                                         free(delete);
                                                                                                         break;                             //退出检索总事件表
                                                                                                    }

                                                                                                    else if(delete->next){                  //普通节点
                                                                                                         Event *temp = head;
                                                                                                         while(temp->next != delete){
                                                                                                              temp = temp->next;
                                                                                                         }
                                                                                                         temp->next = delete->next;
                                                                                                         free(delete);
                                                                                                         break;                               //退出检索总事件表
                                                                                                    }

                                                                                               }
                                                                                               else delete = delete->next;
                                                                                          }
                                                                                          else delete = delete->next;
                                                                                     }
                                                                                     else delete = delete->next;
                                                                                }
                                                                                else delete = delete->next;
                                                                           }
                                                                           else delete = delete->next;
                                                                      }
                                                                      else delete = delete->next;
                                                                 }
                                                                 else delete = delete->next;
                                                            }
                                                            else delete = delete->next;
                                                       }
                                                       else delete = delete->next; 
                                                  }
                                                  else delete = delete->next;
                                             }
                                             else delete = delete->next;
                                        }
                                        else delete = delete->next;
                                   }
                                   else delete = delete->next;
                              }
                             else delete = delete->next;
                         }
                         else delete = delete->next;
                    }
                    
                    delete = head;          //引导指针指向总事件表
                    target = target->next;  //引导指针指向总事件表（移向下一位）
               }
               free(search);
               printf(">>>> PRESS ANY DIRECTION KRY TO MAIN MENU >>>>\n>>>> PRESS ENTER TO LAST MANU >>>>\n");
               return(head);
          }
     }

     else if(!search->next){      //如果已过滤事件唯一
          
          checklist(search);          //陈列出该事件（带编号）
          
          printf("\n>>> Input Y to delete this event.\n");
            printf(">>> Input other key to exit:>  ");

          char X = getchar();

          if(X != 'Y' && X !='y'){
              printf("\n      Exit...\n");
              return (head);
          }

          else if(X == 'Y' || X == 'y'){
               Event *target = search;      //target记录需要删除的数据

               while(target){               //逐个删除已过滤事件表
                    
                    while(delete){          //检索总事件表

                         if(strcmp(delete->discription, target->discription) == 0){
                             
                              if(delete->eventdate.year == target->eventdate.year){
                                
                                   if(delete->startTime.thour == target->startTime.thour){
                                        
                                        if(delete->endTime.thour == target->endTime.thour){
                                             
                                             if(strcmp(delete->location, target->location) == 0){

                                                  if(delete->reminder.ryear == target->reminder.ryear){

                                                       if(delete->eventdate.month == target->eventdate.month){
                                                            
                                                            if(delete->eventdate.day == target->eventdate.day){

                                                                 if(delete->endTime.tmins == target->endTime.tmins){

                                                                      if(delete->startTime.tmins == target->startTime.tmins){

                                                                           if(delete->reminder.rmonth == target->reminder.rmonth){
                                                                                
                                                                                if(delete->reminder.rday == target->reminder.rday){
                                                                                     
                                                                                     if(delete->reminder.rhour == target->reminder.rhour){

                                                                                          if(delete->reminder.rmins == target->reminder.rmins){

                                                                                               if(delete->reminder.rsecd == target->reminder.rsecd){
                                                                                                  
                                                                                                    if(delete == head){                    //目标节点为首事件
                                                                                                         head = delete->next;
                                                                                                         free(delete);
                                                                                                         break;
                                                                                                    }

                                                                                                    else if(delete->next == NULL){          //事件不唯一，目标节点为尾事件
                                                                                                         Event *temp = head;                //建立临时指针 指向
                                                                                                         while(temp->next != delete){
                                                                                                              temp = temp->next;
                                                                                                         } 
                                                                                                         temp->next = NULL;
                                                                                                         free(delete);
                                                                                                         break;                             //退出检索总事件表
                                                                                                    }

                                                                                                    else if(delete->next){                  //普通节点
                                                                                                         Event *temp = head;
                                                                                                         while(temp->next != delete){
                                                                                                              temp = temp->next;
                                                                                                         }
                                                                                                         temp->next = delete->next;
                                                                                                         free(delete);
                                                                                                         break;                               //退出检索总事件表
                                                                                                    }

                                                                                               }
                                                                                               else delete = delete->next;
                                                                                          }
                                                                                          else delete = delete->next;
                                                                                     }
                                                                                     else delete = delete->next;
                                                                                }
                                                                                else delete = delete->next;
                                                                           }
                                                                           else delete = delete->next;
                                                                      }
                                                                      else delete = delete->next;
                                                                 }
                                                                 else delete = delete->next;
                                                            }
                                                            else delete = delete->next;
                                                       }
                                                       else delete = delete->next; 
                                                  }
                                                  else delete = delete->next;
                                             }
                                             else delete = delete->next;
                                        }
                                        else delete = delete->next;
                                   }
                                   else delete = delete->next;
                              }
                             else delete = delete->next;
                         }
                         else delete = delete->next;
                    }
                    
                    delete = head;          //引导指针指向总事件表
                    target = target->next;  //引导指针指向总事件表（移向下一位）
               }
               free(search);
               printf(">>>> PRESS ANY DIRECTION KRY TO MAIN MENU >>>>\n>>>> PRESS ENTER TO LAST MANU >>>>\n");
               return (head);
          }
     }
}

//提醒功能（具体）
void Reminder(Event *head){  //提醒功能
     time_t tt_;
     struct tm *tm_;
     Event *current = head;
     while(!kbhit()){
           time(&tt_);
           tm_ = localtime(&tt_);

           if(current->reminder.ryear ==1900 + tm_->tm_year){
               if(current->reminder.rmonth == tm_->tm_mon + 1){
                    if(current->reminder.rday == tm_->tm_mday){
                         if(current->reminder.rhour == tm_->tm_hour){
                              if(current->reminder.rmins == tm_->tm_min){
                                   if(current->reminder.rsecd == tm_->tm_sec){
                                       printf(">>>> IT'S TIME FOR %s\n",current->discription);
                                       printf("\a");
                                       current = current->next;
                                   }
                                   else current = current->next;
                              }
                              else current = current->next;
                         }
                         else current = current->next;
                    }
                    else current = current->next;
               }
               else current = current->next;
           }
           
           if(current == NULL) current = head;    //到达末尾再从头开始
     }
}

//显示时间函数
void show24Time(){   //24小时制
     time_t tt_;
     struct tm *tm_ ;
     while(!kbhit())               //按下键盘任意键退出循环（包括鼠标点击）
     {
         time(&tt_);               //获取秒数
         tm_ = localtime(&tt_);    //将秒数转换为本地时间（北京时间）

         /* 自己定义打印样式; %02d:宽度为两个整型，如果不够，左边补零; \r：回车不换行 */
         printf("  Current Time <24>: %d/%d/%d %02d:%02d:%02d\r", tm_->tm_mon + 1, tm_->tm_mday, 1900 + tm_->tm_year, tm_->tm_hour, tm_->tm_min, tm_->tm_sec);
         Sleep(500);               
     }
}
void show12Time(){   //12小时制
     time_t tt_;
     struct tm *tm_ ;
     int hour; 
     char period[3];
     while(!kbhit())
     {
          time(&tt_);
          tm_ = localtime(&tt_);
          hour = tm_->tm_hour;
          if(hour >= 12){
               hour = hour - 12;
               strcpy(period,"PM");
          }
          else{
               strcpy(period,"AM");
          }
          printf("  Current Time <12>: %02d/%02d/%d %02d:%02d:%02d %s\r", tm_->tm_mon + 1, tm_->tm_mday,1900 + tm_->tm_year, hour, tm_->tm_min, tm_->tm_sec, period);
          Sleep(500);
     }
}
//文件操作函数
Event *getfromfile(){
     FILE *file = fopen("schdata.txt","r");
     Event *head = NULL;
     if(file == NULL){
          printf("Error...\n");
          return head;
     }
     
     
     Event *new = (Event*)malloc(Len);
     Event *tail;
     tail = new;

     while(fscanf(file,"%800s %d %d %d %d %d %d %d %d %d %d %d %d %d %30s",new->discription,&new->eventdate.month, 
          &new->eventdate.day, &new->eventdate.year,&new->startTime.thour,&new->startTime.tmins, &new->endTime.thour, &new->endTime.tmins,
          &new->reminder.rmonth, &new->reminder.rday, &new->reminder.ryear, &new->reminder.rhour, &new->reminder.rmins, &new->reminder.rsecd,new->location) != EOF){

               if(!head){
                    head = new;
               }
               else{
                    tail->next = new;
                    tail = new;
               }
               tail->next = NULL;
               new = (Event*)malloc(Len);
          }
     free(new);
     fclose(file);
     printf("\n>>>>Get data sucessfully!>>>> \n");
     return (head);
     
}
void *savetofile(Event *head){
     FILE *file = fopen("schdata.txt","w");
     if(file == NULL){
          printf("No data. \n");
          return 0;
     }

     Event *current = head;
     if(head == NULL) printf(">>> No data to save! \n");
    

     while (current){
          fprintf(file, "%800s %d %d %d %d %d %d %d %d %d %d %d %d %d %30s",current->discription,current->eventdate.month, 
          current->eventdate.day,current->eventdate.year,current->startTime.thour,current->startTime.tmins,current->endTime.thour,current->endTime.tmins,
          current->reminder.rmonth,current->reminder.rday,current->reminder.ryear,current->reminder.rhour,current->reminder.rmins,current->reminder.rsecd,current->location);
          current = current->next;
     }

     fclose(file);
}

void displaymenu(int hilight){//总菜单显示函数
     int i;
     printf("\n  | ******************MENU***************** |  \n");
     for (i = 0; i < 7; i++){
         if (i == hilight - 1)  printf("<<%s>>\n",menu[i]);
         else                   printf("  %s\n",menu[i]);
     }
     printf("\n  <<< Please choose the function you need >>> \n");
}

void displaysrchmenu(int hilight){//检索方式显示函数
     int i;
     printf("\n  | ******************MENU***************** |  \n");
     for (i = 0; i < 5; i++){
         if (i == hilight - 1)  printf("<<%s>>\n",srchmenu[i]);
         else                   printf("  %s\n",srchmenu[i]);
     }
     printf("\n  <<< Please choose the function you need >>> \n");
}

void displaymodimenu(int hilight){//修改项显示函数
     int i;
     printf("\n  | ******************MENU***************** |  \n");
     for (i = 0; i < 7; i++){
         if (i == hilight - 1)  printf("<<%s>>\n",modimenu[i]);
         else                   printf("  %s\n",modimenu[i]);
     }
     printf("\n  <<< Please choose the function you need >>> \n");
}

int showsrchmenu(int ccc,Event *head){//选择方式菜单
     char c = ' ';
     int sel = 1;
     displaysrchmenu(sel);
     for (;;){
          if(ccc == 1) show24Time();
          else show12Time();
          Reminder(head);
          if (kbhit()) {
               if (GetAsyncKeyState(VK_UP)) {
                  sel = (sel > 1) ? sel - 1 : sel;
                  Sleep(25);          //确保不会过于灵敏
                  system("cls");
                  displaysrchmenu(sel);
                  getch();
                  getch();
               }
               else if (GetAsyncKeyState(VK_DOWN)){
                  sel = (sel < 5) ? sel + 1 : sel;
                  Sleep(25);
                  system("cls");
                  displaysrchmenu(sel);
                  getch();
                  getch();
               }           
               else{
                    c=getch();   //读取按键值
                    if (c<='z'&& c>='a') c=c-('a'-'A');
                    if (c<='D' && c>='A'){
                         sel=c-'A'+1;
                         system("cls");
                         displaysrchmenu(sel);
                         printf("command is [%c]",c);
                         switch(sel){
                              case 1:return 1;
                                   break;
                              case 2:return 2;
                                   break; 
                              case 3:return 3;
                                   break;
                              case 4:return 4;
                                   break;
                              case 5:return 0;
                                   break;
                             
                         } 
                    }
                    else if (c=='\r'){    //判断是否<回车>键  ，注意不是'\n'
                         if (sel == 5) return (0);
                         printf("command is [%c]\n",'A'+sel-1); 
                          //.........依据sel的值，执行所选功能
                         switch(sel){
                              case 1:return 1; 
                                   break;
                              case 2:return 2;
                                   break; 
                              case 3:return 3;
                                   break;
                              case 4:return 4;
                                   break;
                              case 5:return 0;
                                   break;
                         } 
                    }
                    else if (c=='E') return(0);
               }
            Sleep(50); //延时50ms
          }
     }
}

int showmodimenu(int ccc,Event *head){//修改方式菜单
     char c = ' ';
     int sel = 1;
     displaymodimenu(sel);
     for (;;){
          if(ccc == 1) show24Time();
          else show12Time();
          Reminder(head);
          if (kbhit()) {
               if (GetAsyncKeyState(VK_UP)) {
                  sel = (sel > 1) ? sel - 1 : sel;
                  Sleep(25);          //确保不会过于灵敏
                  system("cls");
                  displaymodimenu(sel);
                  getch();
                  getch();
               }
               else if (GetAsyncKeyState(VK_DOWN)){
                  sel = (sel < 7) ? sel + 1 : sel;
                  Sleep(25);
                  system("cls");
                  displaymodimenu(sel);
                  getch();
                  getch();
               }            
               else{
                    c=getch();   //读取按键值
                    if (c<='z'&& c>='a')c=c-('a'-'A');
                    if (c<='G' && c>='A'){
                         sel=c-'A'+1;
                         system("cls");
                         displaymodimenu(sel);
                         printf("command is [%c]",c);
                         switch(sel){
                              case 1:return 1;
                                   break;
                              case 2:return 2;
                                   break; 
                              case 3:return 3;
                                   break;
                              case 4:return 4;
                                   break;
                              case 5:return 5;
                                   break;
                              case 6:return 6;
                                   break;
                              case 7: return 0;
                                   break;
                         } 
                    }
                    else if (c=='\r'){    //判断是否<回车>键  ，注意不是'\n'
                         if (sel==7) return (0);
                         printf("command is [%c]\n",'A'+sel-1); 
                          //.........依据sel的值，执行所选功能
                         switch(sel){
                              case 1:return 1;
                                   break;
                              case 2:return 2;
                                   break; 
                              case 3:return 3;
                                   break;
                              case 4:return 4;
                                   break;
                              case 5:return 5;
                                   break;
                              case 6:return 6;
                                   break;
                              case 7: return 0;
                                   break;
                         } 
                    }
                    else if (c=='G') return(0);
               }
            Sleep(50); //延时50ms
          }
     }
}

int main (){//主函数
     Event *head = getfromfile();
     Event *snew;
     Event *search = NULL;
     int schoice = 0;
     int mchoice = 0;
     printf(">>>> Previous List:\n");
     checklist(head);
     printf("\n");
     printf(">>>> Please choose a timeform:>\n>>>> Enter 1 is <24>form\n>>>> Enter other number is <12>form\n");
     int ccc = 0;
     scanf("%d",&ccc);
     fflush(stdin);
     if(ccc == 1) show24Time();
     else show12Time();
     printf("\n>>>> Press any direction key to go on... >>>>\n");
     char c = ' ';
     char *str;
     char *filename = NULL;
     int sel = 1;
     displaymenu(sel);
     for (;;){
          if(ccc == 1) show24Time();
          else show12Time();
          Reminder(head);
          if (kbhit()) {
               if (GetAsyncKeyState(VK_UP)) {
                  sel = (sel > 1) ? sel - 1 : sel;
                  Sleep(25);          //确保不会过于灵敏
                  system("cls");
                  displaymenu(sel);
                  getch();
                  getch();
               }
               else if (GetAsyncKeyState(VK_DOWN)){
                  sel = (sel < 7) ? sel + 1 : sel;
                  Sleep(25);
                  system("cls");
                  displaymenu(sel);
                  getch();
                  getch();
               }           
               else{
                    c=getch();   //读取按键值
                    if (c<='z'&& c>='a')c=c-('a'-'A');
                    if (c<='F' && c>='A'){
                         sel=c-'A'+1;
                         system("cls");
                         displaymenu(sel);
                         printf("command is [%c]",c);
                         switch(sel){
                              case 1:
                                   system("cls");
                                   if(!head){
                                        head = getevent(head);
                                   }
                                   else if(head){
                                        head = inst(head,snew);
                                   }
                                   savetofile(head);   //保存数据
                                   break;
                              case 2:
                                   printf("   Please choose a way to search the information to MODIDFY.\n");
                                   schoice = showsrchmenu(ccc,head);
                                   switch(schoice){     //选完后产生已过滤时间表(search)
                                        case 1:search = srchstarTime(head);
                                             break;
                                        case 2:search = srchendTime(head);
                                             break;
                                        case 3:search = srchreminder(head);
                                             break;
                                        case 4:search = srcheventdate(head);
                                             break;
                                        case 0: search = NULL;
                                             break;
                                   }
                                   if(search){
                                        printf("   Please choose the datatype yoou want to modify.\n");
                                        mchoice = showmodimenu(ccc,head);
                                        switch(mchoice){      //根据选择选择修改选项
                                             case 1: head = modifystartTime(head,search);
                                                  break;
                                             case 2: head = modifyendTime(head, search); 
                                                  break; 
                                             case 3: head = modifyremindertime(head, search);
                                                  break;
                                             case 4: head = modifydiscription(head, search);
                                                  break;
                                             case 5: head = modifylocation(head, search);
                                                  break;
                                             case 6: head = modifyevendate(head, search);
                                                  break;
                                             case 7: break;
                                        }
                                   }
                                   savetofile(head);   //保存数据
                                   break; 
                              case 3:
                                   printf("   Please choose a way to search the information to DELETE.\n");
                                   schoice = showsrchmenu(ccc,head);
                                   switch(schoice){     //选完后产生已过滤时间表(search)
                                        case 1:search = srchstarTime(head);
                                             break;
                                        case 2:search = srchendTime(head);
                                             break;
                                        case 3:search = srchreminder(head);
                                             break;
                                        case 4:search = srcheventdate(head);
                                             break;
                                        case 0: search = NULL;
                                              break;
                                   }
                                   head = delete(head,search);
                                   savetofile(head);
                                   break;
                              case 4:
                                    checklist(head);
                                    if(ccc == 1) show24Time();
                                    else show12Time();
                                   break;
                              case 5:
                                   printf("   Please choose a way to search the information.\n");
                                   schoice = showsrchmenu(ccc,head);
                                   switch(schoice){     //选完后产生已过滤时间表(search)
                                        case 1:search = srchstarTime(head);
                                             break;
                                        case 2:search = srchendTime(head);
                                             break;
                                        case 3:search = srchreminder(head);
                                             break;
                                        case 4:search = srcheventdate(head);
                                             break;
                                        case 0: search = NULL;
                                             break;
                                   };
                                   checklist(search);
                                   break;
                              case 6:printf("   Please choose a way to search the information to set REMINDER.\n");
                                   schoice = showsrchmenu(ccc,head);
                                   switch(schoice){     //选完后产生已过滤时间表(search)
                                        case 1:search = srchstarTime(head);
                                             break;
                                        case 2:search = srchendTime(head);
                                             break;
                                        case 3:search = srchreminder(head);
                                             break;
                                        case 4:search = srcheventdate(head);
                                             break;
                                        case 0: search = NULL;
                                              break;
                                   }
                                   if (search){
                                      head = modifyremindertime(head, search);
                                   }
                                   savetofile(head);
                                   break;
                              case 7: return 0;
                                   break;
                         } 
                    }
                    
                    else if (c=='\r'){    //判断是否<回车>键  ，注意不是'\n'
                         if (sel==7) return (0);
                         printf("command is [%c]\n",'A'+sel-1); 
                          //.........依据sel的值，执行所选功能
                         switch(sel){
                              case 1:
                                   system("cls");
                                   if(!head){
                                        head = getevent(head);
                                   }
                                   else if(head){
                                        head = inst(head,snew);
                                   }
                                   savetofile(head);   //保存数据
                                   break;
                              case 2:
                                   printf("   Please choose a way to search the information to MODIDFY.\n");
                                   schoice = showsrchmenu(ccc,head);
                                   switch(schoice){     //选完后产生已过滤时间表(search)
                                        case 1:search = srchstarTime(head);
                                             break;
                                        case 2:search = srchendTime(head);
                                             break;
                                        case 3:search = srchreminder(head);
                                             break;
                                        case 4:search = srcheventdate(head);
                                             break;
                                        case 0: search = NULL;
                                             break;
                                   }
                                   if(search){
                                        printf("   Please choose the datatype yoou want to modify.\n");
                                        mchoice = showmodimenu(ccc,head);
                                        switch(mchoice){      //根据选择选择修改选项
                                             case 1: head = modifystartTime(head,search);
                                                  break;
                                             case 2: head = modifyendTime(head, search); 
                                                  break; 
                                             case 3: head = modifyremindertime(head, search);
                                                  break;
                                             case 4: head = modifydiscription(head, search);
                                                  break;
                                             case 5: head = modifylocation(head, search);
                                                  break;
                                             case 6: head = modifyevendate(head, search);
                                                  break;
                                             case 7: break;
                                        }
                                   } 
                                   savetofile(head);   //保存数据
                                   break; 
                              case 3:
                                   printf("   Please choose a way to search the information to DELETE.\n");
                                   schoice = showsrchmenu(ccc,head);
                                   switch(schoice){     //选完后产生已过滤时间表(search)
                                        case 1:search = srchstarTime(head);
                                             break;
                                        case 2:search = srchendTime(head);
                                             break;
                                        case 3:search = srchreminder(head);
                                             break;
                                        case 4:search = srcheventdate(head);
                                             break;
                                        case 0: search = NULL;
                                              break;
                                   }
                                   head = delete(head,search);
                                   savetofile(head);
                                   break;
                              case 4:
                                    checklist(head);
                                    void show24Time();
                                   break;
                              case 5:
                                   printf("   Please choose a way to search the information.\n");
                                   schoice = showsrchmenu(ccc,head);
                                   switch(schoice){     //选完后产生已过滤时间表(search)
                                        case 1:search = srchstarTime(head);
                                             break;
                                        case 2:search = srchendTime(head);
                                             break;
                                        case 3:search = srchreminder(head);
                                             break;
                                        case 4:search = srcheventdate(head);
                                             break;
                                        case 0: search = NULL;
                                             break;
                                   };
                                   checklist(search);
                                   break;
                              case 6:printf("   Please choose a way to search the information to set REMINDER.\n");
                                   schoice = showsrchmenu(ccc,head);
                                   switch(schoice){     //选完后产生已过滤时间表(search)
                                        case 1:search = srchstarTime(head);
                                             break;
                                        case 2:search = srchendTime(head);
                                             break;
                                        case 3:search = srchreminder(head);
                                             break;
                                        case 4:search = srcheventdate(head);
                                             break;
                                        case 0: search = NULL;
                                              break;
                                   }
                                   if (search){
                                      head = modifyremindertime(head, search);
                                   }
                                   savetofile(head);
                                   break;
                              case 7: return 0;
                                   break;
                         } 
                    }
                    else if (c=='G') return(0);
               }
            Sleep(100); //延时100ms
          }
          
     }
}
