// Program for input without Spaces..

#include <iostream>
using namespace std;

#define MAX 10
int size = -1;
struct stack {
    int num[MAX];
    int top;
};
stack *create() {
    stack *temp = new stack();
    temp->top = -1;
    return temp;
}
void push(stack *s, int c) {
    s->top++;
    s->num[s->top] = c;
    size++;
}
int pop(stack *s) {
    int t = s->num[s->top];
    s->num[s->top] = 0;
    s->top--;
    size--;
    return t;
}

int eval_pf(string str, stack *s) {
    int size = sizeof(str) / sizeof(int); // it should be char. and problem with sizeof(string)
    for (int i = 0; i <= size; i++) {
        if (isdigit(str[i])) {
            int t = str[i] - '0';
            push(s, t);
            cout << "item pushed\n";
        } else {
            int a, b;
            switch (str[i]) {
            case '+':
                a = pop(s);
                b = pop(s);
                push(s, b + a);
                break;

            case '-':
                a = pop(s);
                b = pop(s);
                push(s, b - a);
                break;

            case '*':
                a = pop(s);
                b = pop(s);
                push(s, b * a);
                break;

            case '/':
                a = pop(s);
                b = pop(s);
                push(s, b / a);
                break;
            }
            cout << "eval done\n";
        }
    }
    return s->num[s->top];
}

int main() {
    stack *s = create();
    string a = "231*+9-";
    cout << eval_pf(a, s);

    return 0;
}






// Program for input with Spaces..

// #include <iostream>
// #include <string>
// using namespace std;

// #define MAX 10
// int size = -1;

// struct Stack {
//     int num[MAX];
//     int top;
// };
// Stack *create() {
//     Stack *temp = new Stack();
//     if (!temp) {
//         cout << "Memory allocation failed.";
//         exit(1);
//     }
//     temp->top = -1;
//     return temp;
// }
// void push(Stack *s, int n) {
//     s->top++;
//     s->num[s->top] = n;
//     size++;
// }
// int pop(Stack *s) {
//     s->top--;
//     int t = s->num[size];
//     size--;
//     return t;
// }

// int eval_pf(Stack *s, string str) {

//     int flag = 0, n, flag1 = 0;
//     for (char c : str) {
//         if (c == ' ' && flag1 == 1) {
//             flag = 0;
//             push(s, n);
//             n = 0;
//         } else if (isdigit(c)) {
//             if (flag > 0) {
//                 int t = c - '0';
//                 t = (n * 10) + t;
//                 n = t;
//             } else {
//                 n = c - '0';
//                 flag++;
//             }
//             flag1 = 1;
//         } else {
//             int a, b;
//             switch (c) {
//             case '+':
//                 a = pop(s);
//                 b = pop(s);
//                 push(s, b + a);
//                 break;

//             case '-':
//                 a = pop(s);
//                 b = pop(s);
//                 push(s, b - a);
//                 break;

//             case '*':
//                 a = pop(s);
//                 b = pop(s);
//                 push(s, b * a);
//                 break;

//             case '/':
//                 a = pop(s);
//                 b = pop(s);
//                 push(s, b / a);
//                 break;
//             }
//             flag1 = 0;
//         }
//     }
//     return s->num[s->top];
// }

// int main() {
//     string str = "100 200 + 2 / 5 * 7 +";
//     Stack *s = create();
//     cout << eval_pf(s, str);
// }