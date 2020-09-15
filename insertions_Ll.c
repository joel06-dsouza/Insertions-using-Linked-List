#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void display(node*);
node * insert_beg(node *);
node * insert_end(node *);
node * insert_at(node *);
node * insert_before(node *);
node * insert_after(node *);
int main()
{
    struct node * start=NULL;
    int ch;
    while(1)
    {
        printf("\nMenu:\n1.Insert_beg\n2.Insert_end\n3.Insert_at");
        printf("\n4.Insert_before\n5.Insert_after\n6.Display\n7.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: start=insert_beg(start);
                break;
            case 2: start=insert_end(start);
                break;
            case 3: start=insert_at(start);
                break;
            case 4: start=insert_before(start);
                break;
            case 5: start=insert_after(start);
                break;
            case 6: display(start);
                break;
            case 7: exit(0);
            default : printf("You entered wrong choice");
        }
    }
}

void display (node* start)
{
    node * ptr;
    ptr=start;
    if(ptr==NULL)
    {
        printf("Empty list");
    }
    else
    {
        printf("\nElements of the list:\n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}

node * insert_beg(node * start)
{
    node *newnode=malloc(sizeof(node));
    printf("Enter data : ");
    scanf("%d",&newnode->data);
    newnode->next=start;
    start=newnode;
    return start;
}

node * insert_end(node * start)
{
    node *newnode=malloc(sizeof(node));
    node * ptr;
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    ptr=start;
    if(start==NULL)
    {
    newnode->next=start;
    start=newnode;
    return start;
    }
    else
    {
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=NULL;
    }
    return start;
}

node * insert_after(node * start)
{
    node *ptr;
    int val;
    node *newnode=malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    printf("Enter value of node after which to insert data : ");
    scanf("%d",&val);
    if(start==NULL)
    {
        printf("List is empty cannot insert\n");
    }
    else
    {
        ptr=start;
        while(ptr!=NULL&&ptr->data!=val)
        {
            ptr=ptr->next;
        }
        if(ptr!=NULL)
        {
            newnode->next=ptr->next;
            ptr->next=newnode;
        }
        else
        {
            printf("Value not found. Can't insert");
        }
    }
    return start;
}


node * insert_before(node *start)
{
    node *ptr1, *ptr2;
    int val;
    node *newnode=malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    printf("Enter value of node before which to insert data : ");
    scanf("%d",&val);
    if(start==NULL)
    {
        printf("List is empty cannot insert\n");
    }
    else
    {
        ptr1=ptr2=start;
        while(ptr2!=NULL&&ptr2->data!=val)
        {
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        if(ptr2==NULL)
        {
            printf("Value not found ! Can't insert");
        }
        else
        {
            newnode->next=ptr2;
            if(ptr1==ptr2)
            {
                start=newnode;
            }
            else
            {
                ptr1->next=newnode;
            }
        }
    }
    return start;
}

node * insert_at(node *start)
{
    node *ptr1, *ptr2;
    int pos,count=0;
    node *newnode=malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    printf("Enter position to insert data : ");
    scanf("%d",&pos);
    if(start==NULL && pos>1)
    {
        printf("List is empty cannot insert\n");
    }
	if(pos==1)
	{
	   newnode->next=start;
	   start=newnode;
	}
    else
    {
        ptr1=ptr2=start;
        while(ptr2!=NULL&&count<pos-1)
        {
            count=count++;
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        if(count==pos-1)
        {
            newnode->next=ptr2;
            ptr1->next=newnode;
        }
        else
        {
               printf("Cant insert at position %d",pos);
        }
    }
    return start;
}





