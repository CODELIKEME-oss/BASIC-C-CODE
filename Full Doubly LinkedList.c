#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *create();
void display(struct node *head);
struct node *insert(struct node *head);
struct node *insend(struct node *head);
struct node *insmid(struct node *head);
struct node *deb(struct node *head);
struct node *dend(struct node *head);
struct node *dmid(struct node *head);
int main()
{
    struct node *head=NULL;
    int ch;
      while(1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at mid\n");
        printf("5. Delete at Beginning\n");
        printf("6. Display\n");
        printf("7. Delete at the end\n");
        printf("8. Delete at mid\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                head = create();
                break;

            case 2:
                head = insert(head);
                break;

            case 3:
                head = insend(head);
                break;

            case 4:
                head=insmid(head);
                break;

            case 5:
                head=deb(head);
                break;
            case 6:
                display(head);
                break;
            case 7:
                head=dend(head);
                break;
            case 8:
                head=dmid(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
struct node *create()
{
    struct node *head=NULL,*c,*n;
    head=(struct node*)malloc(sizeof(struct node));
    printf("enter the node=");
    scanf("%d",&head->info);
    char ch;
    head->next=NULL;
    head->prev=NULL;
    c=head;
    do
    {
        printf("enter y for new node=");
        scanf(" %c",&ch);
        if(ch=='y'||ch=='Y')
        {
            n=(struct node*)malloc(sizeof(struct node));
            printf("enter the new node=");
            scanf("%d",&n->info);
            n->prev=c;
            n->next=NULL;
            c->next=n;
            c=n;
        }
    } while(ch=='y'||ch=='Y');
        return head;
}
struct node *insert(struct node *head)
{
    struct node *n;
    char ch;
    ch='y';
    while(ch=='y'||ch=='Y')
    {
        n=(struct node*)malloc(sizeof(struct node));
        printf("enter the new node=");
        scanf("%d",&n->info);
        n->prev=NULL;
        n->next=head;
        head->prev=n;
        head=n;
        printf("enter y for inserting new node=");
        scanf(" %c",&ch);
    }
    return head;
}
struct node *insend(struct node *head)
{
    struct node *n,*c;
    char ch;
    c=head;
    ch='y';
    while(c->next!=NULL)
    {
        c=c->next;
    }
    while(ch=='y'||ch=='Y')
    {
        n=(struct node*)malloc(sizeof(struct node));
        printf("enter the new node=");
        scanf("%d",&n->info);
        n->next=NULL;
        n->prev=c;
        c->next=n;
        c=n;
        printf("enter y for new node=");
        scanf(" %c",&ch);
    }
    return head;
}
struct node *insmid(struct node *head)
{
    struct node *c,*n;
    c=head;
    char ch;
    int num;
    ch='y';
    printf("enter the node to insert after=");
    scanf("%d",&num);
    while(c!=NULL && c->info!=num)
    {
        c=c->next;
    }
    while(ch=='y'||ch=='Y')
    {
        n=(struct node*)malloc(sizeof(struct node));
        printf("enter the new node in mid");
        scanf("%d",&n->info);
        n->next = c->next;
        n->prev = c;
        c->next->prev = n;
        c->next = n;
        c=n;
        printf("enter y for more=");
        scanf(" %c",&ch);
    }
    return head;
}
struct node *deb(struct node *head)
{
    struct node *c;
    c=head;
    if(head==NULL)
    {
        printf("the list is empty");
    }
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    head=head->next;
    head->prev=NULL;
    free(c);
    return head;
}
struct node *dend(struct node *head)
{
    struct node *c;
    c=head;
    if(head==NULL)
    {
        printf("NULL\n");
    }
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    while(c->next!=NULL)
    {
        c=c->next;
    }
    c->prev->next=NULL;
    free(c);
    return head;
}
struct node *dmid(struct node *head)
{
    struct node *c;
    int d;
    printf("enter the node to delete");
    scanf("%d",&d);
    c=head;
    if(head==NULL)
    {
        printf("empty list");
        return NULL;
    }
    if(c->info==d)
    {
        head=c->next;
        if(head!=NULL)
        head->prev=NULL;
        free(c);
        return head;
    }
    while(c!=NULL&&c->info!=d)
    {
        c=c->next;
    }
    if(c==NULL)
    {
        printf("value not found\n");
        return head;
    }
    if(c->next!=NULL)
    {
        c->next->prev=c->prev;
    }
    if(c->prev!=NULL)
    {
        c->prev->next=c->next;
    }
    free(c);
    return head;
}

void display(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d<->",temp->info);
        temp=temp->next;
    }
    printf("NULL\n");
}
