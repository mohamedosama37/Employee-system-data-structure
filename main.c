#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define null -32
struct employee
{
    char name[30];
    int id;
    int salary;
};

struct Node
{
    struct employee emp;
    struct Node *next;
    struct Node *prev;
};
struct Node *pfirst=NULL;
struct Node *plast=NULL;
struct Node *pcurrent=NULL;

 void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

 void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}

struct Node *create (struct employee  e)
{
   struct Node* New=(struct Node *)malloc(1*sizeof(struct Node));
    New->emp=e;

    New->next=New->prev=NULL;
}

void Add (struct Node *PNEW)
{
    if(pfirst==NULL)
    {
        pfirst=plast=PNEW;
    }
    else
    {
        plast->next=PNEW;
        PNEW->prev=plast;
        plast=PNEW;
    }
}






void Delete(struct Node*pdelete)
{
    if(plast== pfirst)
    {
        if(pfirst==plast)
        {
            pfirst=plast=NULL;
        }
        else
        {
            pfirst=pfirst->next;
            pfirst->prev=NULL;
        }
    }
    else if(pdelete==plast)
    {
        plast=plast->prev;
        plast->next=NULL;
    }
    else
    {
        pdelete->prev->next=pdelete->next;
        pdelete->next->prev=pdelete->prev;
    }
    free(pdelete);
}


void Swap(struct Node *ptr1,struct Node *ptr2)
{
    if(ptr1==pfirst  &&ptr2 !=plast)
    {
        ptr1->next=ptr2->next;
        ptr2->next->prev=ptr1;
        ptr2->next=ptr1;
         ptr2->prev=NULL;
        ptr1->prev=ptr2;
        pfirst=ptr2;
    }
    else if(ptr2==plast && ptr1!=plast)
    {
        ptr2->prev=ptr1->prev;
        ptr1->prev->next=ptr2;
        ptr2->next=ptr1;
        ptr1->prev=ptr2;
        ptr1->next=NULL;
        plast=ptr1;
         }
         else if(ptr1==pfirst && ptr2==plast )
         {
             ptr1->prev=ptr2;
             ptr2->next=ptr1;
             ptr1->next=NULL;
             ptr2->prev=NULL;
             pfirst=ptr2;
             plast=ptr1;
         }
         else
         {
             ptr1->next=ptr2->next;
             ptr2->prev=ptr1->prev;
             ptr1->prev->next=ptr2;
             ptr2->next->prev=ptr1;
             ptr1->prev=ptr2;
             ptr2->next=ptr1;
         }
}

void Bubble_sorting()
{
    int size=0;
    int i;
struct Node *temp=pfirst;
 while(temp !=NULL)
 {
     temp=temp->next;
     size++;
 }
 temp=pfirst;

 int counter,index,sorted_flag=0;
    for(counter=0;counter<size-1&&sorted_flag!=1;counter++)
    {
    sorted_flag=1;
    temp=pfirst;
        for(index=0;index<size-counter-1;index++)
        {
            if(temp->emp.id>temp->next->emp.id)
            {
                Swap(temp,temp->next);
                sorted_flag=0;

            }else{
                temp=temp->next;
            }


        }
    }

}

void display()
{
    struct Node *ptr=pfirst;
    while(ptr !=NULL)
    {
        printf("%s\n",ptr->emp.name);
        printf("%d\n",ptr->emp.id);
        printf("%d\n",ptr->emp.salary);
        ptr=ptr->next;


    }
}
int main ()
{
    struct employee emp;
  struct    Node *ptr;
     printf("enter the first name\n");
    scanf("%s",emp.name);
    printf("enter the id\n");
    scanf("%d",&emp.id);
    printf("enter the salary\n");
    scanf("%d",&emp.salary);

   ptr= create(emp);
    Add(ptr);

    printf("enter the first name\n");
    scanf("%s",emp.name);
    printf("enter the id\n");
    scanf("%d",&emp.id);
    printf("enter the salary\n");
    scanf("%d",&emp.salary);

    ptr=create(emp);
    Add(ptr);

      printf("enter the first name\n");
    scanf("%s",ptr->emp.name);
    printf("enter the id\n");
    scanf("%d",&emp.id);
    printf("enter the salary\n");
    scanf("%d",&emp.salary);
    ptr=create(emp);
    Add(ptr);
    Bubble_sorting();


    display();



}
