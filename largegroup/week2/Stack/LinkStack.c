#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include'LinkStack.h'
int main()
{
    char str[1024]={0};//将数组每个元素赋值为'\0'
    printf("请输入四则运算表达式:\n");
    scanf("%s",str);
    int number=transform(str);
    if(number==-1)
    {
        printf("表达式转换错误:\n");
    }
    else if(number==1)
    {
        printf("转化后的表达式: %s\n",buffer);
    }
    else
    {
        return 0;
    }
}

