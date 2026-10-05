#include <stdio.h>

void reversePrefix(char word[], char ch)
{
    char stack[250];
    int top = -1;
    int i = 0;

    while (word[i] != '\0')
    {
        stack[++top] = word[i];

        if (word[i] == ch)
            break;

        i++;
    }

    if (word[i] == '\0')
    {
        return;
    }

    i = 0;

    while (top >= 0)
    {
        word[i++] = stack[top--];
    }
}

int main()
{
    char word[250];
    char ch;

    printf("Enter word: ");
    scanf("%s", word);

    printf("Enter character: ");
    scanf(" %c", &ch);

    reversePrefix(word, ch);

    printf("Result: %s\n", word);

    return 0;
}