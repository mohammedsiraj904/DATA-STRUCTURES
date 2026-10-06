#include <stdio.h>

#define MAX 3


int main()
{
    int queue[MAX];
    int front = -1, rear = -1;
    int choice, x, i;

    choice = 0;

    while (choice != 4)
    {
        printf(" QUEUE OPERATIONS\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (rear == MAX - 1)
                {
                    printf("Queue Overflow\n");
                }
                else
                {
                    printf("Enter the element: ");
                    scanf("%d", &x);

                    if (front == -1)
                    {
                        front = 0;
                    }

                    rear++;
                    queue[rear] = x;

                    printf("%d inserted into queue\n", x);
                }
                break;

            case 2:
                if (front == -1 || front > rear)
                {
                    printf("Queue underflow\n");
                }
                else
                {
                    x = queue[front];

                    printf("Deleted element: %d\n", x);

                    front++;

                    if (front > rear)
                    {
                        front = -1;
                        rear = -1;
                    }
                }
                break;

            case 3:
                if (front == -1)
                {
                    printf("Queue is Empty\n");
                }
                else
                {
                    printf("Queue elements are: ");

                    for (i = front; i <= rear; i++)
                    {
                        printf("%d ", queue[i]);
                    }

                    printf("\n");
                }
                break;

            case 4:
                printf("Exit\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}