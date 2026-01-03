#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if(rear == MAX-1)
        return;
    if(front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if(front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void reverseFirstK(int k) {
    int stack[MAX], top = -1;


    for(int i = 0; i < k; i++)
        stack[++top] = dequeue();
         while(top != -1)
        enqueue(stack[top--]);


    int size = rear - front + 1;
    for(int i = 0; i < size - k; i++)
        enqueue(dequeue());
}

int main() {
    int n, k, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter queue elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    printf("Enter K: ");
    scanf("%d", &k);

    reverseFirstK(k);

 printf("Queue after reversing first %d elements:\n", k);
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

return 0;
}