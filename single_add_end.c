#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *start=NULL;
void  add_at_end(int num);
void display();
#define A_ELE 4
int count=0;
void main()
{
	int num;
	int lal=10;
	int arr[A_ELE],i;
	while(1)
	{
	printf("enter array element  (0 FOR EXIT)\n");
		 scanf("%d",&num);
	if(num==0)
		exit(0);
	add_at_end(num);
	display();
	}
}

void display()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	printf("Array Elements Are : \n");
	temp=start;
	while(temp!=NULL)
	{
		printf("%d \n",temp->data);
		temp=temp->link;
	}
}
void add_at_end(int num)
{
	struct node *temp;
	struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=num;
	//ptr->link=NULL;
	if(start==NULL)
	{
		start=ptr;
		return;
	}
	temp=start;
	while(temp->link!=NULL)
		temp=temp->link;
	temp->link=ptr;
	//printf("total numbeer of nodes:-%d\n",count);
	
}

