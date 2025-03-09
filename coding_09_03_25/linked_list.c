#include <stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct node* CreateHeader()
{
    /*CreateHeader() is a fuction pointer of type struct. This function
     is making another pointer: head. Head has been allocated memory of
     struct size:2+?. this also means
     that the head contains the address of memory block of struct size.  */
    struct node* head=(struct node*)malloc(sizeof(struct node*));
    head->data=0;
    head->next=NULL;
    printf("Header data value=%d\n", head->data);
    return head; // address of head is returned
}

struct node* InsertNodeAtBegin(struct node* header,int data) /*InsertNodeAtBegin() is a function
                                                               pointer of type struct.  */
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node*)); // newnode is a pointer
    newNode->data=data;
    newNode->next=header;
    // header->next=newNode;
    printf("data value of new node=%d\n",newNode->data);
    return newNode;
}

struct node* reverseList(struct node* header)
{
    struct node *curr=header,*prev=NULL, *next;

    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

struct node* deleteNode(struct node* header, int pos)
{
    struct node* temp=header;
    struct node* prev=NULL;

    if(temp==NULL)
    printf("no data tp delete");
    return header;

    // if(position==1)
    // {
    //     header=temp->next;
    //     free(temp);
    //     return header;
    // }

    for(int i=0;temp!=NULL && i<pos;i++)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp!=NULL)
    {
        prev->next=temp->next;
        free(temp);
        printf("node %d deleted", pos);
    }
    else
    {
        printf("data not present\n");
    }
    return header;
}

int main(){
struct node* header=CreateHeader();     /*  the address of head is in header.
                                         This means that header is pointing the same
                                         memory address which the head was pointing to.*/

int data=0,option=0;

// printf("header value before insert at the begin=%d\n",header);
header=InsertNodeAtBegin(header,data);
// printf("header value after insert at the begin=%d\n",header);

while(1)
{
    printf("\nMENU\n");
    printf(" 1)Create new node\n 2)Delete node\n 3)Reverse list\n 4) exit\n");
    printf("Enter yout option=");
    scanf("%d",&option);

    switch(option)
    {
        case 1: printf("enter data value of  node %d=", (header->data+1));
                scanf("%d",&data);
                header=InsertNodeAtBegin(header,data);
                break;
        case 2: int position=0;
                printf("Enter the node number to be deleted=");
                scanf("%d\n",position);
                header=deleteNode(header,position);
                break;
        case 3:header=reverseList(header);

               break;
        case 4:printf("exiting...");
                return 0;
                break;
        default: printf("Invalid Input! Try again.");
                break;
    }
}
    return 0;
}
