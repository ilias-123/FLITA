#include <stdio.h>
#include<stdlib.h>

typedef struct Que{
    int value;
    struct Que* prev;
    }
Queue;

void push(int value, Queue** first, Queue** last);
void show(Queue* first,Queue* last);
int pop (Queue** first);

int main(void){

Queue* Last=NULL;
Queue* First=NULL;
    int log=0;
    int a=0;
    int num=0;
    int ind;
    while(!log){
        printf("Press 1 to push a new number\n");
        printf("Press 2 to pop the first number\n");
        printf("Press any other symbol to quit\n");
        show(First,Last);
        printf(">");
        scanf("%d",&a);
        switch (a){
            case 1:
            printf("Enter one number\n");
            printf(">");
            scanf("%d",&num);
            push(num,&First,&Last);
            break;
        case 2:
            ind=pop(&First);
            if(!ind)
                printf("Failed to pop the last number\n");
            else
                printf("The first number: %d\n",ind);
            break;
        default:
        log=1;
        break;   
         }
    }
return 0;
}

void push(int value, Queue** first, Queue** last){
Queue* temp=(Queue*)malloc(sizeof(Queue));
if((*last)!=NULL)
    (*last)->prev=temp;
(*last)=temp;
if((*first)==NULL)
    (*first)=temp;
temp->value=value;  
}
int pop (Queue** first){
    Queue* temp=*first;
     if (!(*first)){
         return 0;
     }
     (*first)=temp->prev;
     int value=temp->value;
     free(temp);
     return value;
     
}

 void show(Queue* first,Queue* last){
if(first==NULL) {
    printf("Queue is empty\n");
    return;
}
 printf("Queue:\n");
while (first!=last){
  printf("%d\n",first->value);
  first=first->prev;   
}
printf("%d\n",first->value);
 }


