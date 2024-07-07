#include <iostream>
using namespace std;

#define MAX 10
int size = -1;

struct stack {
    char op[MAX];
    int top;
};
stack *create() {
    stack *temp = new stack();
    temp->top = -1;
    return temp;
}
void push(stack *s, int n) {
    s->top++;
    s->op[s->top] = n;
    size++;
}
char pop(stack *s) {
    char t = s->op[s->top];
    s->top--;
    size--;
    return t;
}
int precedance(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else
        return -1;
}
void convert(stack *s, string str) {
    for (char c : str) {
        if (isdigit(c)) {
            cout << c;
        } else {
            if (c == '(') {
                push(s, c);
            } else if (c == ')') {
                while (size > -1) {
                    char t = pop(s);
                    if (t == '(')
                        break;
                    else
                        cout << t;
                }
            } else if (precedance(s->op[s->top]) >= precedance(c) && size > -1) {
                while (1) {
                    if (precedance(s->op[s->top]) >= precedance(c)) {
                        cout << pop(s);
                    } else {
                        push(s, c);
                        break;
                    }
                }
            } else {
                push(s, c);
            }
        }
    }
    if (s->top > -1) {
        while (size >= -1) {
            cout << pop(s);
        }
    }
}

int main() {
    string str = "((1+(2*3))-4)";
    stack *s = create();

    convert(s, str);

    return 0;
}
