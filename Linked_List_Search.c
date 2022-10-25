#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void insertion_at_end(struct node *head,int num)
{
    struct node *ptr,*temp;
    ptr = head;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = num;
    temp->link = NULL;

    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    ptr->link = temp;

}

int search(struct node *head,int a)
{
    int i=0;
    while(head!=NULL)
    {
        if(head->data == a)
        {
            i++;
            return i;
        }
        else
        {
            i++;
        }
        head = head->link;
    }
    return 0;
}

int main()
{
    int n;
    printf("Enter the number of elements in the linked list here ");
    scanf("%d",&n);
    printf("Enter the elements in the linked list here ");
    struct node *head = (struct node*)malloc(sizeof(struct node));
    
    for(int i=0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        if(i == 0)
        {
            head->data = num;
            head->link = NULL;
        }
        else{
            insertion_at_end(head,num);
        }
    }

    printf("Enter the element you want to search in linked list is ");
    int a;
    scanf("%d",&a);
    int pos = search(head,a);
    if(pos)
    {
        printf("Element is there in linked list at position %d\n",pos);
    }
    else
    {
        printf("Element is not present in the linked list\n");
    }
    return 0;
}