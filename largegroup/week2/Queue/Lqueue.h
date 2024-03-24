#define MAXQUEUE 10
typedef struct Aqueue
{
    void *data[MAXQUEUE];      //数据域
    int front;
    int rear;
   int length;        //队列长度
} AQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;
char datatype[MAXQUEUE];
int pri; 
