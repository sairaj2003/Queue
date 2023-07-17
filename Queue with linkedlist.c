#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* addr;
}*temp;

struct node* front=NULL;
struct node* rear=NULL;

void insertq(int);
int deleteq();
void displayq();

int main() 
{
	int n,ch;
	int deletedElement;
	
	do
	{
		printf("\n-------------------------------------------------------");
		printf("\n                        OPERATIONS                     ");
		printf("\n-------------------------------------------------------");
		printf("\n1.Insert\n2.Delete\n3.Display");
		printf("\n-------------------------------------------------------");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("\nEnter element tht you want to insert into queue:");
				scanf("%d",&n);
				insertq(n);
				printf("%d is successsfully inserted into queue...",n);
				break;
				
			case 2:	
				deleteq();
				printf("\nelement is successfully deleted from queue...");
				break;
				
			case 3:
				displayq();
				break;
			
		}
		printf("\n-------------------------------------------------------");
		printf("\nDo you want to continue press 1");
		scanf("%d",&ch);
	}while(ch==1);
		
	return 0;
}

void insertq(int n)
{
	temp=malloc(sizeof(struct node));
	temp->data=n;
	temp->addr=NULL;
	
	if(front==NULL && rear==NULL)
	{
		front=rear=temp;
	}
	else
	{
		rear->addr=temp;
		rear=rear->addr;
	}
}

int deleteq()
{
	if(front==rear)
	{
		temp=front;
		front=NULL;
		rear=NULL;
	}
	else
	{
		temp=front;
		front=front->addr;
	}
	free(temp);
}

void displayq()
{
	for(temp=front;temp!=rear;temp=temp->addr)    //when temp=rear it will not print last value so we print outside the loop
	{
		printf("| %d | %u |---->",temp->data,temp->addr);
	}
	printf("| %d | %u |---->",temp->data,temp->addr);         
}
