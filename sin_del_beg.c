#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *start=NULL;
void delete_at_beg();
void create_list_at_end(int *,int);
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
		printf("enter array elements\n");
			for(i=0;i<A_ELE;i++)
				scanf("%d",&arr[i]);
		create_list_at_end(arr,A_ELE);
		delete_at_beg();
		display();
	}
}

void delete_at_beg()
{
	struct node *temp;
	temp=start;
	if(temp==NULL)
	{
		printf("list is empty \n");
		return;
	}
	start=start->link;
	free(temp);
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
void create_list_at_end(int *iptr,int n)
{
	int i;
	struct node *l_start,*temp;
	struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=iptr[0];
	ptr->link=NULL;
	l_start=temp=ptr;
	for(i=1;i<n;i++)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		ptr->data=iptr[i];
		ptr->link=temp->link;
		temp->link=ptr;
		temp=ptr;
	}
	if(start==NULL)
	{
		start=l_start;
		return;
	}
	temp=start;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=l_start;
	
}

