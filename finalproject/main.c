#include <stdio.h>
#include <stdlib.h>
#include "gotoxy.c"
typedef struct customer customer;
static int  person;
 static int ID;
static float WaitTime;
struct customer{
    int ID;
int  arrivalTime;
int Transaction_Duration;
int WaitingTime;
int TotalTime;

};

struct LinkedList {
    struct LinkedList *next;
  customer customer;
};

struct queue {
    struct LinkedList *head;
    struct LinkedList *tail;
    int TotalDuration;
int TotalWaitingTime;
};

struct queue *queueCreate(void)
{
    struct queue *q;
    q = malloc(sizeof(struct queue));
    q->head = q->tail = 0;
 q->TotalDuration=0;
  q->TotalWaitingTime=0;
    return q;
}
void enq(struct queue *q,  customer c)
{
    struct LinkedList *e;
    e = malloc(sizeof(struct LinkedList));
    e->customer.arrivalTime= c.arrivalTime;
    e->customer.Transaction_Duration= c.Transaction_Duration;
q->TotalDuration+=c.Transaction_Duration;
        e->next = 0;
    if(q->head == 0) {
        q->head = e;
        e->customer.WaitingTime=NULL;
    } else {
        /* Otherwise I get in line after the old tail */
        q->tail->next = e;

    }
    q->tail = e;
    bubbleSort(q->head);
WaitingTime(q->head);

}

int queueEmpty(const struct queue *q)
{
    return (q->head == 0);
}
struct LinkedList* dequeue(struct queue* q) {
        struct LinkedList *tmp1;
        struct LinkedList *tmp2;
        if(q->head == NULL && q->tail == NULL) {
            printf("queue is empty\n");
        }

        tmp1 = q->head;
        tmp2 = tmp1->next;
        q->head = tmp2;
        if(q->head== NULL) {
            q->tail= q->head;
                printf("removed  from queue\n");
        }
        return tmp1;
}


void queuePrint(struct queue *q)
{
    struct LinkedList *e;
int ID=0;
    for(e = q->head; e != 0; e = e->next) {
            ID++;
            e->customer.ID=ID;
            printf("\n  %d",ID);
        printf("\t    %d\t\t\t%d", e->customer.arrivalTime,e->customer.Transaction_Duration);
        e->customer.TotalTime=e->customer.arrivalTime+e->customer.Transaction_Duration;
        printf("\t\t  %d",(e->customer.TotalTime));
        printf("\t\t  %d",(e->customer.WaitingTime));


    }
     printf("\tTotal Duration : %d",q->TotalDuration);
    putchar('\n');
}

int main()
{
    int i;
    struct queue *q[3];
    struct queue *temp;
    struct customer cust;
    struct customer cust2;

 int counter=1;

    char input;
    q[0] = queueCreate();
    q[1] = queueCreate();
    q[2] = queueCreate();
    temp=queueCreate();


struct LinkedList *c;
    int x=1;
do{system("cls");
    char option[4][20]={"New"," Display","Exit","Report"};
    for(int i=1; i<5; i++)
        {
            if(i==counter)
            {
                SetColor(9);
            }
            else
            {
                SetColor(10);
            }
            gotoxy(50,i*2);
            printf("%s",option[i-1]);
        }

 input=_getch();
        if (input == -32)
        {
            input=_getch();
            if(input== 72)
            {
                counter--;
                // up_arrow
                if(counter==0)
                {
                    counter=4;
                }
            }
            else if(input==80)
            {
                counter++;
                // down_arrow
                if(counter==5)
                {
                    counter=1;
                }
            }
            else if(input==71)
            {
                // home_button
                counter=1;
            }
            else if(input==79)
            {
                // end_button
                counter=3;
            }
        }
        else if(input==13)
        {
            if(counter==1)
            {
                system("cls");
                 person++;
                 printf("Arrival Time :");
                scanf("%d",&cust.arrivalTime);
    printf("\nDuration:");
    scanf("%d",&cust.Transaction_Duration);

   enq(temp,cust);
   for(c= temp->head; c!= 0; c= c->next)
   {
    if (q[0]->head==NULL || (q[0]->TotalDuration< q[1]->TotalDuration &&  q[0]->TotalDuration< q[2]->TotalDuration))
             {
                 enq(q[0],c->customer);

}
        else if (q[1]->head==NULL || (q[1]->TotalDuration< q[0]->TotalDuration && q[1]->TotalDuration< q[2]->TotalDuration))
            { enq(q[1],c->customer);
}
          else {enq(q[2],c->customer);}
   }
    _getch();
    dequeue(temp);
            }
            else if(counter==2)
            {
                system("cls");
                   printf("ID \tArrival Time \tTransaction Duration \t  end\t WaitingTime ");
             printf("\nq0");
                 queuePrint(q[0]);
                   printf("\nq1");
                 queuePrint(q[1]);
                 printf("\nq2");
                 queuePrint(q[2]);
                _getch();
            }
            else if( counter==4){     SetColor(10);   system("cls");      printf("\nTotal Number of customers: %d",person);
            if(q[0]->tail != NULL)
            {printf("\nFirst Queue Customers Number %d",q[0]->tail->customer.ID);}
            if(q[1]->tail != NULL)
                printf("\nSecond Queue Customers Number %d",q[1]->tail->customer.ID);
             if(q[2]->tail != NULL)
             printf("\nThird Queue Customers Number %d",q[2]->tail->customer.ID);
             printf("\n Total Average Waiting Time %f",WaitTime/person);


            _getch();}
        }

    }
    while(input != 13 || counter != 3);

    return 0;
}



void bubbleSort(struct LinkedList *head)
{
    int swapped, i;
    struct LinkedList *ptr1;
    struct LinkedList *lptr = NULL;

    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
           if (ptr1->customer.arrivalTime > ptr1->next->customer.arrivalTime)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }

            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

/* function to swap data of two nodes a and b*/
void swap(struct LinkedList *a, struct LinkedList *b)
{
    int temp = a->customer.arrivalTime;
    int temp2 =a->customer.Transaction_Duration;
    a->customer.arrivalTime= b->customer.arrivalTime;
    b->customer.arrivalTime = temp;
       a->customer.Transaction_Duration= b->customer.Transaction_Duration;
    b->customer.Transaction_Duration= temp2;

}

void  CalcTime(struct LinkedList *cust1,struct LinkedList *cust2 )
{


    cust2->customer.WaitingTime=cust1->customer.arrivalTime+cust1->customer.Transaction_Duration-cust1->next->customer.arrivalTime;
    WaitTime+=cust2->customer.WaitingTime;

}

void WaitingTime(struct LinkedList *head)
{
    int Flag, i;
    struct LinkedList *ptr1;
    struct LinkedList *lptr = NULL;
    ptr1->customer.WaitingTime=NULL;


    if (head == NULL)
        return;

    do
    {
        Flag = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
           if ((ptr1->customer.arrivalTime+ptr1->customer.Transaction_Duration) > ptr1->next->customer.arrivalTime)
            {
               CalcTime(ptr1, ptr1->next);
                Flag= 1;
            }
else {ptr1->next->customer.WaitingTime=NULL; Flag=0;}
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (Flag);

}
