

/*
//Stack with Push

#include <stdlib.h>

#define MAX_SIZE 100
struct Stack {
    int array[MAX_SIZE];
    int top;
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    stack->top = -1;
    return stack;
}
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
int main() {
    struct Stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    return 0;
}
*/



/*
//Stack with Pop

#include <stdlib.h>
#define MAX_SIZE 100
struct Stack {
    int array[MAX_SIZE];
    int top;
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    stack->top = -1;
    return stack;
}
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->array[stack->top--];
}
int main() {
    struct Stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));
    printf("%d popped from stack\n", pop(stack));
    return 0;
}
*/


/*
//Stack with Top

#include <stdlib.h>
#define MAX_SIZE 100
struct Stack {
    int array[MAX_SIZE];
    int top;
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    stack->top = -1;
    return stack;
}
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->array[stack->top--];
}
int top(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->array[stack->top];
}
int main() {
    struct Stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("Top element of stack: %d\n", top(stack));
    printf("%d popped from stack\n", pop(stack));
    printf("Top element of stack: %d\n", top(stack));
    printf("%d popped from stack\n", pop(stack));
    printf("Top element of stack: %d\n", top(stack));
    printf("%d popped from stack\n", pop(stack));
    return 0;
}
*/



/*
//Circular Queue with Enqueue
#include <stdlib.h>
#define MAX_SIZE 5
struct CircularQueue {
    int array[MAX_SIZE];
    int front, rear;
    int size;
};
struct CircularQueue* createCircularQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = queue->rear = -1;
    queue->size = 0;
    return queue;
}
int isFull(struct CircularQueue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}
int isEmpty(struct CircularQueue* queue) {
    return queue->size == 0;
}
void enqueue(struct CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(queue))
        queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to the queue\n", item);
}

int main() {
    struct CircularQueue* queue = createCircularQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    return 0;
}
*/



/*
//Circular Queue with Dequeue

#include <stdlib.h>
#define MAX_SIZE 5
struct CircularQueue {
    int array[MAX_SIZE];
    int front, rear;
    int size;
};
struct CircularQueue* createCircularQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = queue->rear = -1;
    queue->size = 0;
    return queue;
}
int isFull(struct CircularQueue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}
int isEmpty(struct CircularQueue* queue) {
    return queue->size == 0;
}
void enqueue(struct CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(queue))
        queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to the queue\n", item);
}
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        exit(1);
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return item;
}
int main() {
    struct CircularQueue* queue = createCircularQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    return 0;
}
*/


/*

//Circular Queue with Peek

#include <stdlib.h>
#define MAX_SIZE 5
struct CircularQueue {
    int array[MAX_SIZE];
    int front, rear;
    int size;
};
struct CircularQueue* createCircularQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = queue->rear = -1;
    queue->size = 0;
    return queue;
}
int isFull(struct CircularQueue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}
int isEmpty(struct CircularQueue* queue) {
    return queue->size == 0;
}
void enqueue(struct CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(queue))
        queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to the queue\n", item);
}
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        exit(1);
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    }
    else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    queue->size--;
    return item;
}
int peek(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    return queue->array[queue->front];
}
int main() {
    struct CircularQueue* queue = createCircularQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    printf("Front element of queue: %d\n", peek(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("Front element of queue after dequeue: %d\n", peek(queue));
    return 0;
}
*/


/*

//Binary Max Heap with Insert
#include <stdlib.h>
#define MAX_HEAP_SIZE 100
struct MaxHeap {
    int array[MAX_HEAP_SIZE];
    int size;
};
struct MaxHeap* createMaxHeap() {
    struct MaxHeap* maxHeap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
    if (maxHeap == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    maxHeap->size = 0;
    return maxHeap;
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int parent(int i) {
    return (i - 1) / 2;
}
void insert(struct MaxHeap* maxHeap, int item) {
    if (maxHeap->size >= MAX_HEAP_SIZE) {
        printf("Heap Overflow\n");
        return;
    }
    int i = maxHeap->size;
    maxHeap->array[i] = item;
    maxHeap->size++;
    while (i != 0 && maxHeap->array[parent(i)] < maxHeap->array[i]) {
        swap(&maxHeap->array[i], &maxHeap->array[parent(i)]);
        i = parent(i);
    }
    printf("%d inserted into max heap\n", item);
}
void printMaxHeap(struct MaxHeap* maxHeap) {
    printf("Max Heap: ");
    for (int i = 0; i < maxHeap->size; i++) {
        printf("%d ", maxHeap->array[i]);
    }
    printf("\n");
}

int main() {
    struct MaxHeap* maxHeap = createMaxHeap();
    insert(maxHeap, 10);
    insert(maxHeap, 20);
    insert(maxHeap, 15);
    insert(maxHeap, 30);
    printMaxHeap(maxHeap);
    return 0;
}
*/


/*
//Binary Max Heap with Delete
#include <stdlib.h>

#define MAX_HEAP_SIZE 100
struct MaxHeap {
    int array[MAX_HEAP_SIZE];
    int size;
};
struct MaxHeap* createMaxHeap() {
    struct MaxHeap* maxHeap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
    if (maxHeap == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    maxHeap->size = 0;
    return maxHeap;
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int leftChild(int i) {
    return 2 * i + 1;
}
int rightChild(int i) {
    return 2 * i + 2;
}
void maxHeapify(struct MaxHeap* maxHeap, int i) {
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);
    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest])
        largest = left;
    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest])
        largest = right;
    if (largest != i) {
        swap(&maxHeap->array[i], &maxHeap->array[largest]);
        maxHeapify(maxHeap, largest);
    }
}
void insert(struct MaxHeap* maxHeap, int item) {
    if (maxHeap->size >= MAX_HEAP_SIZE) {
        printf("Heap Overflow\n");
        return;
    }
    int i = maxHeap->size;
    maxHeap->array[i] = item;
    maxHeap->size++;
    while (i != 0 && maxHeap->array[(i - 1) / 2] < maxHeap->array[i]) {
        swap(&maxHeap->array[i], &maxHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    printf("%d inserted into max heap\n", item);
}
int extractMax(struct MaxHeap* maxHeap) {
    if (maxHeap->size <= 0) {
        printf("Heap Underflow\n");
        return -1;
    }
    if (maxHeap->size == 1) {
        maxHeap->size--;
        return maxHeap->array[0];
    }
    int max = maxHeap->array[0];
    maxHeap->array[0] = maxHeap->array[maxHeap->size - 1];
    maxHeap->size--;
    maxHeapify(maxHeap, 0);
    return max;
}
void printMaxHeap(struct MaxHeap* maxHeap) {
    printf("Max Heap: ");
    for (int i = 0; i < maxHeap->size; i++) {
        printf("%d ", maxHeap->array[i]);
    }
    printf("\n");
}
int main() {
    struct MaxHeap* maxHeap = createMaxHeap();
    insert(maxHeap, 10);
    insert(maxHeap, 20);
    insert(maxHeap, 15);
    insert(maxHeap, 30);
    printMaxHeap(maxHeap);
    printf("Extracted Max: %d\n", extractMax(maxHeap));
    printMaxHeap(maxHeap);
    return 0;
}
*/



/*
//Binary Max Heap with Peek (Maximum)
#include <stdlib.h>

#define MAX_HEAP_SIZE 100
struct MaxHeap {
    int array[MAX_HEAP_SIZE];
    int size;
};
struct MaxHeap* createMaxHeap() {
    struct MaxHeap* maxHeap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
    if (maxHeap == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    maxHeap->size = 0;
    return maxHeap;
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int leftChild(int i) {
    return 2 * i + 1;
}
int rightChild(int i) {
    return 2 * i + 2;
}
void maxHeapify(struct MaxHeap* maxHeap, int i) {
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);
    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest])
        largest = left;
    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest])
        largest = right;
    if (largest != i) {
        swap(&maxHeap->array[i], &maxHeap->array[largest]);
        maxHeapify(maxHeap, largest);
    }
}
void insert(struct MaxHeap* maxHeap, int item) {
    if (maxHeap->size >= MAX_HEAP_SIZE) {
        printf("Heap Overflow\n");
        return;
    }
    int i = maxHeap->size;
    maxHeap->array[i] = item;
    maxHeap->size++;
    while (i != 0 && maxHeap->array[(i - 1) / 2] < maxHeap->array[i]) {
        swap(&maxHeap->array[i], &maxHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    printf("%d inserted into max heap\n", item);
}
int extractMax(struct MaxHeap* maxHeap) {
    if (maxHeap->size <= 0) {
        printf("Heap Underflow\n");
        return -1;
    }
    if (maxHeap->size == 1) {
        maxHeap->size--;
        return maxHeap->array[0];
    }
    int max = maxHeap->array[0];
    maxHeap->array[0] = maxHeap->array[maxHeap->size - 1];
    maxHeap->size--;
    maxHeapify(maxHeap, 0);

    return max;
}
int peek(struct MaxHeap* maxHeap) {
    if (maxHeap->size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }
    return maxHeap->array[0];
}
void printMaxHeap(struct MaxHeap* maxHeap) {
    printf("Max Heap: ");
    for (int i = 0; i < maxHeap->size; i++) {
        printf("%d ", maxHeap->array[i]);
    }
    printf("\n");
}

int main() {
    struct MaxHeap* maxHeap = createMaxHeap();
    insert(maxHeap, 10);
    insert(maxHeap, 20);
    insert(maxHeap, 15);
    insert(maxHeap, 30);
    printMaxHeap(maxHeap);
    printf("Peek (Maximum): %d\n", peek(maxHeap));
    return 0;
}
*/


/*
//Binary Max Heap with IncreaseKey
#include <stdlib.h>

#define MAX_HEAP_SIZE 100
struct MaxHeap {
    int array[MAX_HEAP_SIZE];
    int size;
};
struct MaxHeap* createMaxHeap() {
    struct MaxHeap* maxHeap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
    if (maxHeap == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    maxHeap->size = 0;
    return maxHeap;
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int parent(int i) {
    return (i - 1) / 2;
}
void maxHeapify(struct MaxHeap* maxHeap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest])
        largest = left;
    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest])
        largest = right;
    if (largest != i) {
        swap(&maxHeap->array[i], &maxHeap->array[largest]);
        maxHeapify(maxHeap, largest);
    }
}
void insert(struct MaxHeap* maxHeap, int item) {
    if (maxHeap->size >= MAX_HEAP_SIZE) {
        printf("Heap Overflow\n");
        return;
    }
    int i = maxHeap->size;
    maxHeap->array[i] = item;
    maxHeap->size++;
    while (i != 0 && maxHeap->array[parent(i)] < maxHeap->array[i]) {
        swap(&maxHeap->array[i], &maxHeap->array[parent(i)]);
        i = parent(i);
    }
    printf("%d inserted into max heap\n", item);
}
int extractMax(struct MaxHeap* maxHeap) {
    if (maxHeap->size <= 0) {
        printf("Heap Underflow\n");
        return -1;
    }
    if (maxHeap->size == 1) {
        maxHeap->size--;
        return maxHeap->array[0];
    }
    int max = maxHeap->array[0];
    maxHeap->array[0] = maxHeap->array[maxHeap->size - 1];
    maxHeap->size--;
    maxHeapify(maxHeap, 0);
    return max;
}
void increaseKey(struct MaxHeap* maxHeap, int index, int newValue) {
    if (index >= maxHeap->size || index < 0) {
        printf("Invalid index\n");
        return;
    }
    maxHeap->array[index] = newValue;
    while (index != 0 && maxHeap->array[parent(index)] < maxHeap->array[index]) {
        swap(&maxHeap->array[index], &maxHeap->array[parent(index)]);
        index = parent(index);
    }
    printf("Key at index %d increased to %d\n", index, newValue);
}

void printMaxHeap(struct MaxHeap* maxHeap) {
    printf("Max Heap: ");
    for (int i = 0; i < maxHeap->size; i++) {
        printf("%d ", maxHeap->array[i]);
    }
    printf("\n");
}

int main() {
    struct MaxHeap* maxHeap = createMaxHeap();
    insert(maxHeap, 10);
    insert(maxHeap, 20);
    insert(maxHeap, 15);
    insert(maxHeap, 30);
    printMaxHeap(maxHeap);
    increaseKey(maxHeap, 2, 25);
    printMaxHeap(maxHeap);
    return 0;
}
*/



/*
//Double Linked list with Insert
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void printList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    printList(head);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    printList(head);
    return 0;
}
*/




/*
//Double Linked list with Delete
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prevNode = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        printf("Node with data %d deleted from the list.\n", key);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prevNode = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key %d not found in the list. No deletion performed.\n", key);
        return;
    }
    prevNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = prevNode;
    free(temp);
    printf("Node with data %d deleted from the list.\n", key);
}
void printList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    printList(head);
    deleteNode(&head, 30);
    printList(head);
    deleteNode(&head, 10);
    printList(head);
    deleteNode(&head, 50);
    printList(head);
    deleteNode(&head, 60);
    return 0;
}
*/



/*

//Double Linked list with Search
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prevNode = NULL;
    while (current != NULL && current->data != key) {
        prevNode = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with key %d not found. Cannot delete.\n", key);
        return;
    }
    if (prevNode == NULL)
        *head = current->next;
    else
        prevNode->next = current->next;

    if (current->next != NULL)
        current->next->prev = prevNode;

    free(current);
    printf("Node with key %d deleted successfully.\n", key);
}
struct Node* search(struct Node* head, int key) {
    while (head != NULL) {
        if (head->data == key)
            return head;
        head = head->next;
    }
    return NULL;
}
void printList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    printList(head);
    int keyToSearch = 20;
    struct Node* foundNode = search(head, keyToSearch);
    if (foundNode != NULL)
        printf("Node with key %d found.\n", keyToSearch);
    else
        printf("Node with key %d not found.\n", keyToSearch);
    int keyToDelete = 20;
    deleteNode(&head, keyToDelete);
    printList(head);
    return 0;
}
*/







/*
//Binary Search Tree with Insert
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder Traversal of Binary Search Tree: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}

*/


/*
//Binary Search Tree with Delete

#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
int main() {
    struct Node* root = NULL;
    root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);
    printf("Inorder Traversal of Binary Search Tree before deletion: ");
    inorderTraversal(root);
    printf("\n");
    root = deleteNode(root, 30);
    printf("Inorder Traversal of Binary Search Tree after deletion: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}
*/



/*
//Binary Search Tree with Search

#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder Traversal of Binary Search Tree: ");
    inorderTraversal(root);
    printf("\n");
    int key = 40;
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("Key %d found in Binary Search Tree\n", key);
    }
    else {
        printf("Key %d not found in Binary Search Tree\n", key);
    }

    return 0;
}

*/


