#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;              
    struct Node *left;     
    struct Node *right;    
    struct Node *parent;   
} Node;

typedef struct MaxHeap {
    Node *root;            
} MaxHeap;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

MaxHeap* createMaxHeap() {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap)); 
    if (heap == NULL) {
        exit(EXIT_FAILURE);
    }
    heap->root = NULL; 
    return heap;
}

typedef struct Queue {
    Node** data;  
    int front;    
    int rear;     
    int capacity; 
} Queue;

Queue* newQueue(int num) {
    Queue* queue = (Queue*)malloc(sizeof(Queue)); 
    if (queue == NULL) {
        exit(EXIT_FAILURE);
    }
    queue->data = (Node**)malloc(sizeof(Node*) * num); 
    if (queue->data == NULL) {
        exit(EXIT_FAILURE);
    }
    queue->front = 0; 
    queue->rear = 0;  
    queue->capacity = num; 
    return queue;
}

void full_queue(Queue* queue) {
    int sum = queue->capacity * 2; 
    queue->data = (Node**)realloc(queue->data, sizeof(Node*) * sum); 
    if (queue->data == NULL) {
        exit(EXIT_FAILURE);
    }
    queue->capacity = sum; 
}


void enqueue(Queue* queue, Node* node) {
    if (queue->rear == queue->capacity) { 
        full_queue(queue); 
    }
    queue->data[queue->rear++] = node; 
}


Node* dequeue(Queue* queue) {
    if (queue->front == queue->rear) { 
        return NULL;
    }
    return queue->data[queue->front++]; 
}


int Empty(Queue* queue) {
    return queue->front == queue->rear;
}

Node* find(MaxHeap* heap) {
    if (!heap->root) return NULL;

    Queue* queue = newQueue(10000); 
    enqueue(queue, heap->root); 

    Node* current = NULL;
    while (!Empty(queue)) {
        current = dequeue(queue); 
        if (!current->left || !current->right) { 
            free(queue->data);
            free(queue);
            return current;
        }
        if (current->left) enqueue(queue, current->left); 
        if (current->right) enqueue(queue, current->right);
    }
    free(queue->data);
    free(queue);
    return NULL;
}

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void insertMaxHeap(MaxHeap* heap, int data) {
    Node* newNode = createNode(data); 
    if (!heap->root) { 
        heap->root = newNode;
        return;
    }

    Node* insert = find(heap); 
    newNode->parent = insert;
    if (!insert->left) {
        insert->left = newNode; 
    } else {
        insert->right = newNode; 
    }

    Node* current = newNode;
    while (current->parent && current->parent->data < current->data) {
        swap(current, current->parent);
        current = current->parent;
    }
}

int Max(MaxHeap* heap) {
    if (!heap->root) {
        return -1;
    }

    int maxValue = heap->root->data;
    Node* lastNode = heap->root;

    Queue* queue = newQueue(10000);
    enqueue(queue, heap->root);

    while (!Empty(queue)) {
        lastNode = dequeue(queue);
        if (lastNode->left) enqueue(queue, lastNode->left);
        if (lastNode->right) enqueue(queue, lastNode->right);
    }

    if (lastNode == heap->root) { 
        free(lastNode);
        heap->root = NULL;
    } else {
        heap->root->data = lastNode->data; 
        Node* parent = lastNode->parent;
        if (parent->left == lastNode) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(lastNode);

        Node* current = heap->root;
        while (1) {
            Node* left = current->left;
            Node* right = current->right;
            Node* largest = current;

            if (left && left->data > largest->data) largest = left;
            if (right && right->data > largest->data) largest = right;

            if (largest != current) {
                swap(current, largest);
                current = largest;
            } else {
                break;
            }
        }
    }
    free(queue->data);
    free(queue);
    return maxValue;
}


void File(MaxHeap* heap, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return;
    }

    int data;
    while (fscanf(file, "%d", &data) != EOF) {
        insertMaxHeap(heap, data); 
    }
    fclose(file);
}


void print(MaxHeap* heap) {
    while (heap->root) {
        printf("%d ", Max(heap)); 
    }
    printf("\n");
}

int main() {
    MaxHeap* heap = createMaxHeap(); 
    File(heap, "test.txt"); 
    print(heap); 
    return 0;
}
