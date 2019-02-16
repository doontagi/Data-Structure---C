#ifndef  STACKADT_H
#define  STACKADT_H
#include <stdbool.h>
typedef int Item;
typedef struct stack_type *Stack;
Stack create();
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);
Item peek(Stack s);
void handle_exception(const char *err_msg);
int eval_op(char op);
#endif
