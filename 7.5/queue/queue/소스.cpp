#include <iostream>

typedef struct queue
{
	int data;
	struct queue* link;
} Queue;
typedef struct 
{
	Queue *front, *rear;
}Queue_link;
void push(Queue_link* head);
void make(Queue* head);
int pop(Queue_link* head);
int main()
{
	Queue head;
	Queue_link link;
	head.data = 5;
	head.link = NULL;
	link.front = &head;
	link.rear = &head;
	push(&link);
	std::cout << pop(&link);
}
void push(Queue_link* head)
{
	int data;
	head->front->link = new Queue;
	std::cin >> data;
	head->front->link->data = data;
	head->front->link->link = NULL;
	head->front = head->front->link;
}
int pop(Queue_link* head)
{
	int temp;
	temp = head->rear->data;
	head->rear = head->rear->link;
	return temp;
}
void make(Queue* head)
{
	int data;
	head = new Queue;
	std::cin >> data;
	head->data = data;
	head->link = NULL;
}
