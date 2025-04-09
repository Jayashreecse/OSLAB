#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;  // semaphore initialization

int wait(int);  // Wait operation on semaphore
int signal(int); // Signal operation on semaphore
void producer();  // Producer function
void consumer();  // Consumer function

int main()
{
    int n;

    printf("\n1. Producer\n2. Consumer\n3. Exit");
    
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch(n)
        {
            case 1:
                if((mutex == 1) && (empty != 0))  // Can produce if mutex is 1 and buffer is not full
                    producer();
                else
                    printf("Buffer is full!!\n");
                break;

            case 2:
                if((mutex == 1) && (full != 0))  // Can consume if mutex is 1 and buffer is not empty
                    consumer();
                else
                    printf("Buffer is empty!!\n");
                break;

            case 3:
                exit(0);  // Exit the program
                break;
        }
    }
    return 0;
}

int wait(int s)
{
    return (--s);  // Decrease the value of semaphore
}

int signal(int s)
{
    return (++s);  // Increase the value of semaphore
}

void producer()
{
    mutex = wait(mutex);         // Enter critical section
    full = signal(full);         // Increase the count of full items
    empty = wait(empty);         // Decrease the count of empty slots
    x++;                         // Increase the item count
    printf("\nProducer produces item %d\n", x);
    mutex = signal(mutex);       // Exit critical section
}

void consumer()
{
    mutex = wait(mutex);         // Enter critical section
    full = wait(full);           // Decrease the count of full items
    empty = signal(empty);       // Increase the count of empty slots
    printf("\nConsumer consumes item %d\n", x);
    x--;                         // Decrease the item count
    mutex = signal(mutex);       // Exit critical section
}
