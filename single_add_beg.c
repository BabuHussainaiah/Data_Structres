#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *start=NULL;
void  add_at_beg(int num);
void display();
#define A_ELE 4
int count=0;
void main()
{
	int num;
	int lal=10;
	int arr[A_ELE],i;
	printf("enter array element\n");
		 scanf("%d",&num);
	add_at_beg(num);
	display();
}
void add_at_beg(int num)
{
	struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=num;
	ptr->link=start;
	start=ptr;
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
