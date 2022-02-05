#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 150

char stack[size];
int top = -1;

int empty();
int full();
int operand(char c);
int precedence(char c);
void push(char c);
char pop();
char *infixtopostfix(char *exp);
char *postfixtoinfix(char *exp);
char *prefixtoinfix(char *exp);

int main()
{
	char exp[100];
	char *rev;
	int choice;
	choice = 0;
	while (choice != 7)
	{
		printf("The Menu choice is: \n");
		printf("Press 1 for infix to postfix \n");
		printf("Press 2 for infix to prefix \n");
		printf("Press 3 for prefix to infix \n");
		printf("Press 4 for postfix to infix \n");
		printf("Press 5 for prefix to postfix \n");
		printf("Press 6 for postfix to prefix \n");
		printf("Press 7 to exit \n");
		printf("Enter your choice \n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the infix expression \n");
			scanf("%s", exp);
			printf("The postfix expression is: %s \n", infixtopostfix(exp));
			break;
		case 2:
			printf("Enter the infix expression \n");
			scanf("%s", exp);
			rev = strrev(exp);
			rev = infixtopostfix(rev);
			printf("The prefix expression is: %s \n", strrev(rev));
			break;
		case 3:
			printf("Enter the prefix expression \n");
			scanf("%s", exp);
			printf("The  infix expression is:%s \n", prefixtoinfix(exp));
			break;
		case 4:
			printf("Enter the postfix expression \n");
			scanf("%s", exp);
			printf("The infix expression is: %s \n", postfixtoinfix(exp));
			break;
		case 5:
			printf("Enter the prefix expression \n");
			scanf("%s", exp);
			rev = prefixtoinfix(exp);
			printf("The postfix expression is:%s \n", infixtopostfix(rev));
			break;
		case 6:
			printf("Enter the postfix expression \n");
			scanf("%s", exp);
			rev = postfixtoinfix(exp);
			rev = strrev(rev);
			rev = infixtopostfix(rev);
			printf("The prefix expression is: %s \n", strrev(rev));
			break;
		default:
			if (choice > 7)
				printf("enter the valid choice \n");
			break;
		}
	}
}

int empty()
{
	if (top == -1)
		return 1;

	return 0;
}

int full()
{
	if (top == size - 1)
		return 1;

	return 0;
}

int operand(char c)
{
	if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
		return 1;
	else
		return 0;
}

int precedence(char c)
{
	if (c == '+' || c == '-')
		return 1;
	else if (c == '/' || c == '*')
		return 2;

	return 0;
}

void push(char c)
{
	top++;
	stack[top] = c;
}

char pop()
{
	char val = stack[top];
	top--;
	return val;
}

char *infixtopostfix(char *exp)
{
	char *pos;
	top = -1;
	pos = (char *)malloc(size * (sizeof(char)));
	int i = 0, j = 0;

	while (exp[i] != '\0')
	{
		if (operand(exp[i]))
		{
			pos[j] = exp[i];
			j++;
			i++;
		}
		else
		{
			if (precedence(exp[i]) > precedence(stack[top]))
			{
				push(exp[i]);
				i++;
			}
			else
			{
				pos[j] = pop();
				j++;
			}
		}
	}
	while (empty() != 1)
	{
		pos[j] = pop();
		j++;
	}
	pos[j] = '\0';
	return pos;
}

char *postfixtoinfix(char *exp) // right to left logic
{								// postfix to infix
	int i, j;
	i = 0, j = 0;
	top = -1;
	char *x;
	fflush(stdin);
	x = (char *)malloc(size * (sizeof(char)));
	strrev(exp);

	for (i = 0; i < strlen(exp); i++)
	{
		if (operand(exp[i]))
		{
			x[j] = exp[i];
			j++;
			x[j] = pop();
			j++;
		}
		else
			push(exp[i]);
	}
	x[j] = '\0';
	strrev(x);
	return x;
}

char *prefixtoinfix(char *exp) // prefix to infix
{
	int i, j;
	i = 0, j = 0;
	top = -1;
	char *x;

	x = (char *)malloc(size * (sizeof(char)));

	for (i = 0; i < strlen(exp); i++)
	{
		if (operand(exp[i]))
		{
			x[j] = exp[i];
			j++;
			x[j] = pop();
			j++;
		}
		else
			push(exp[i]);
	}
	x[j] = exp[top--];
	j++;
	x[j] = '\0';
	return x;
}
