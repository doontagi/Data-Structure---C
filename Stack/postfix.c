#include  <stdio.h>
#include  <stdlib.h>
#include  "STACKADT.h"
#include  <string.h>

static char OPERATORS[] = "+-*/";
Stack operand_stack;
int is_operator(char ch) {
	int strsize = strlen(OPERATORS);
	for (int i = 0; i < strsize ; i++)
		if (OPERATORS[i] == ch)
			return i;
	return -1;
}
int eval(char *expr) {
	operand_stack = create();
	char *token = strtok(expr, " ");
	while (token != NULL) {
		if (token[0] >= '0' && token[0] <= '9') {
			int value = atoi(token);
			push(operand_stack, value);
		}
		else if (is_operator(token[0]) > -1) {
			int result = eval_op(token[0]);
			push(operand_stack, result);
		}
		else {
			handle_exception("syntax error1");
		}
		token = strtok(NULL, " ");
	}
	if (is_empty(operand_stack))
		handle_exception("syntax error");
	int answer = pop(operand_stack);
	if (is_empty(operand_stack))
		return answer;
	else {
		handle_exception("Syntax error");
		return -1;
	}
}

void handle_exception(const char *err_msg) {
	printf("%s\n", err_msg);
	exit(1);
}
int eval_op(char op) {
	if (is_empty(operand_stack))
		handle_exception("error");
	int rhs = pop(operand_stack);
	if (is_empty(operand_stack))
		handle_exception("error");
	int lhs = pop(operand_stack);
	int result = 0;
	switch (op) {
	case '+':result = lhs + rhs; break;
	case '-':result = lhs - rhs; break;
	case '*':result = lhs * rhs; break;
	case '/':result = lhs / rhs; break;
	}
	return result;
}
int main() {
	char s[] = "2 2 *";
	printf("%d",eval(s));
}
