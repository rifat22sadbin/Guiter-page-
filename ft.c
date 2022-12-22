#include <stdio.h>
#include <stdlib.h>
struct node *createlinkedlist(int array[],int size );
void insertatstart(struct node*head,int value);
void print(struct node *head);
int search(struct node* head,int value);

struct node
{
    int data;
    struct node *next;
};
int main()
{
    int a[100],n,rt,j,f;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter  the array\n");
    for(j=0; j<n; j++)
    {
        scanf("%d",&a[j]);
    }
    struct node *head=NULL;

    head=createlinkedlist(a,n);
    print(head);

    printf("\nEnter the value that you want to add\n");
    scanf("%d",&f);
    insertatstart(head,f);
    struct node *current=head;
    printf("\nEnter the vale that you want to search\n");
    scanf("%d",&rt);
    printf("The index is :%d",search(head,rt ));



    return 0;
}
void insertatstart(struct node*head,int number)
{

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=number;
    temp->next=head;
    struct node *newhead=temp;
    struct node *current=newhead;
    newhead=temp;
    print(newhead);


}
void print(struct node *head)
{

    struct node*current=head;
    while(current!=NULL)
    {
        printf("%d--",current->data);
        current=current->next;
    }
    printf("--NULL");
}
int search(struct node*head,int value)
{
    int index=1;
    while(head!=NULL)
    {
        if(head->data==value)
        {
            return index;
        }
        index++;
        head=head->next;
    }
    return -1;
}
struct node *createlinkedlist(int array[],int size )
{
    struct node *head=NULL,*temp=NULL,*current=NULL;
    int i;
    for(i=0; i<size; i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=array[i];
        temp->next=NULL;
        if(head==NULL)
        {

            head=temp;
            current=temp;
        }
        else
        {
            current->next=temp;
            current=current->next;
        }
    }
    return head;
}
