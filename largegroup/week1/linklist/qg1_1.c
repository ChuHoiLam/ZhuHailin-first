#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include <conio.h>
#include <time.h>                   //
#define Len sizeof(struct event)    //Len为结构体的长度 
typedef  struct event Event;        //重命名结构体
typedef  struct date Date;
typedef  struct reminder Remd;
typedef  struct time Time;

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

