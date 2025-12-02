#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

int priority(char c) {
    if (c=='+' || c=='-') return 1;
    if (c=='*' || c=='/') return 2;
    return 0;
}

int main() {
    char in[50], out[50]; 
    int i, j = 0;
    
    printf("Enter Infix: ");
    scanf("%s", in);

    for (i = 0; in[i] != '\0'; i++) {
        char c = in[i];

        if (isalnum(c)) {
            out[j++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                out[j++] = pop();
            pop(); 
        }
        else {
            while (top != -1 && priority(stack[top]) >= priority(c))
                out[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        out[j++] = pop();

    out[j] = '\0';

    printf("Postfix: %s\n", out);

    return 0;
}

