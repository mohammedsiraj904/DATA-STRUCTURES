#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++)
    {
        ch = infix[i];

        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9'))
        {
            postfix[j++] = ch;
        }

        else if (ch == '(')
        {
            stack[++top] = ch;
        }

        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            top--;
        }

        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = stack[top--];
            }

            stack[++top] = ch;
        }
    }

    while (top != -1)
    {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}