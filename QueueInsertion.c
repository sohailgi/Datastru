#include <stdio.h>  

int q[100];   
int front=-1;  
int rear=-1;  

void insert(int n)  
{  
    if(front==-1 && rear==-1)     
    {  
        front=0;  
        rear=0;  
        q[rear]=n;  
    }  
    else if((rear+1)%100==front)    
    {  
        printf("\nqueue overflow");  
    }  
    else  
    {  
        rear=(rear+1)%100;         
        q[rear]=n;       
    }  
}  

int delete()  
{  
    if((front==-1) && (rear==-1))   
    {  
        printf("\nQueue underflow");  
    }  
    else if(front==rear)  
    {  
         printf("\nthe element deleted is %d", q[front]);  
         front=-1;  
         rear=-1;  
    }   
    else  
    {  
         printf("\nthe element deleted is %d", q[front]);  
         front=(front+1)%100;  
    }  
}  
  
void display()  
{  
    int i=front;  
    if(front==-1 && rear==-1)  
    {  
        printf("\nqueue is empty");  
    }  
    else  
    {  
          
        while(i<=rear)  
        {  
            printf("%d,", q[i]);  
            i=(i+1)%100;  
        }  
    } 
    printf("\n");
}  
int main()  
{  
    int ch=1,n;     
      
    while(ch!=0)     
    {  
    printf("\n1: Insert | 2: Delete | 3: Display\n ");
    scanf(" %d", &ch);  
      
    switch(ch)  
    {  
          
        case 1:  printf("\nEnter the element which is to be inserted:-");  
                 scanf("%d", &n);  
                 insert(n);  
                 break;  
        case 2:  delete(); 
                 break;
        case 3:  display();
                 break;
        default: printf("\nEnter the correct choice");
                 ch =1;
                 break;
  
    }
}  
    return 0;  
}