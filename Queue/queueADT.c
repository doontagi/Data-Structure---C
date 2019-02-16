#include  <stdio.h>
#include  <stdlib.h>
#include  "queueADT.h"
struct  node {
	Item data;
	struct node *next;
};
struct  queue_type {
	struct  node  *front;
	struct  node  *rear;
	int  size;
};
void  terminate(const  char  *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}
int  get_size(Queue  q) {
	return  q->size;	
}
Queue  create() {
	Queue  q = malloc(sizeof(struct  queue_type));
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
	return  q;
}
void  destroy(Queue  q) {
	make_empty(q);
	free(q);
}
void  make_empty(Queue  q) {
	while (!is_empty(q))
		dequeue(q);
	q->size = 0;
}
bool  is_empty(Queue  q) {
	return  q->front == NULL;
}
void  enqueue(Queue  q, Item  i) {
	struct  node  *new_node = malloc(sizeof(struct  node));
	if (new_node == NULL)
		terminate("Error  in  push:  queue  is  full.");
	new_node->data = i;
	new_node->next = NULL;
	if (q->front == NULL) {
		q->front = new_node;
		q->rear = new_node;
	}
	else {
		q->rear->next = new_node;
		q->rear = new_node;
	}
	q->size++;
}
Item  dequeue(Queue  q) {
	struct  node  *old_front;
	Item i;
	if (is_empty(q))
		terminate("Error  in  dequeue:  queue  is  empty.");
	old_front = q->front;
	i = old_front->data;
	q->front = old_front->next;
	if (q->front == NULL)
		q->rear = NULL;
	free(old_front);
	q->size--;
	return  i;
}
Item  peek(Queue  q) {
	if (is_empty(q))
		terminate("Error  in  peek:  queue  is  empty.");
	return  q->front->data;
}
int main() {
	Queue a = create();
	enqueue(a, 1);
	printf("%d",peek(a));

}
