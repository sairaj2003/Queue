#include <stdio.h>
#include <stdlib.h>
#define M 3

int que[M];
int front = 0, rear = 0;
int temp;

void insertq(int);
int deleteq();
void displayq();

int main()
{
    int n, ch;
    do
    {
        printf("\n-----------------------------------------------------");
        printf("\n                       OPERATIONS                    ");
        printf("\n-----------------------------------------------------");
        printf("\n1.Insert\n2.Delete\n3.Display");
        printf("\n-----------------------------------------------------");
        printf("\nEnter your choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter element that you want to enter into the queue:");
            scanf("%d", &n);
            insertq(n);
            break;

        case 2:
            temp = deleteq();
            printf("\n%d is successfully deleted from queue....", temp);
            break;

        case 3:
            displayq();
            break;
        }
        printf("\n-----------------------------------------------------");
        printf("\nDo you want to continue? Press 1 to continue: ");
        scanf("%d", &ch);
    } while (ch == 1);

    return 0;
}

void insertq(int n)
{
    if (rear == M)
    {
        printf("\nQueue is full...");
    }
    else
    {
        que[rear] = n;
        rear++;
        printf("\n%d is successfully inserted into the queue", n);
    }
}

int deleteq()
{
    int temp;

    if (front == rear)
    {
        printf("\nQueue is empty...");
        return -1; // Returning -1 to indicate that the queue is empty
    }
    else
    {
        temp = que[front];
        front++;
        return temp;
    }
}

void displayq()
{
	int i;
    if (front == rear)
    {
        printf("\nQueue is empty...");
    }
    else
    {
        for (i = front; i < rear; i++)
        {
        	
            printf("%5d", que[i]);
        }
    }
}

