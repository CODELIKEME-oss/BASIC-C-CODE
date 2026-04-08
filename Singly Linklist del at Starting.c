#include <stdio.h>
#include <stdlib.h>
struct node{
    int info;
    struct node*next;
};
struct node *create();
struct node *del(struct node *head);
void display(struct node *head);
int main()
{
    struct node *head;
    head=create();
    char d;
    printf("enter d for delete the starting node");
    scanf(" %c",&d);
    if(d=='d'||d=='D')
    {
        head=del(head);
    }
    display(head);
}
struct node *del(struct node *head)
{
    struct node *temp;
    if(head==NULL)
    {
         printf("list is empty");
         return head;
    }       
    temp=head;
    head=head->next;
    free(temp);
    return head;
}
struct node *create()
{
    struct node *head=NULL,*n,*c;
    char ch;
    do
    {
        n=(struct node*)malloc(sizeof(struct node));

        printf("enter the data: ");
        scanf("%d",&n->info);
        n->next=NULL;

        if(head==NULL)
        {
            head=n;
            c=n;
        }
        else
        {
            c->next=n;
            c=n;
        }

        printf("enter y for node: ");
        scanf(" %c",&ch);

        if(ch!='y' && ch!='Y')
            break;

    }while(1);
    return head;
}
void display(struct node *head)
{
    struct node*temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->info);
        temp=temp->next;
    }
    printf("NULL\n");
}