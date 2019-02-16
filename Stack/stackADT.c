#include  <stdio.h>
#include  <stdlib.h>
#include  "STACKADT.h"
#include  <string.h>
struct node {
	Item data;
	struct node *next;
};
struct stack_type {
	struct node *top;
};
void terminate(const char *message) {
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}
Stack create() {
	Stack s = malloc(sizeof(struct stack_type));
	if (s == NULL)
		terminate("no stack");
	s->top = NULL;
	return s;
}
void destroy(Stack s) {
	make_empty(s);
	free(s);
}
void make_empty(Stack s) {
	while (!is_empty(s))
		pop(s);
}
bool is_empty(Stack s) {
	return s->top == NULL;
}
void push(Stack s, Item i) {
	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		terminate("Error");
	}
	new_node->data = i;
	new_node->next = s->top;
	s->top = new_node;
}
Item pop(Stack s) {
	struct node *old_pop;
	Item i;
	old_pop = s->top;
	i = old_pop->data;
	s->top = old_pop->next;
	free(old_pop);
	return i;
}
Item peek(Stack s) {
	return s->top->data;
}
