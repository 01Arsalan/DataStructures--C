#include <iostream>
using namespace std;

class stack {
public:
    string name;
    stack *prew;
};
stack *top;

void push(string n) {
    stack *temp = new stack();
    if (!temp) {
        cout << "Memory Allocation Failed.\n";
        exit(1);
    } else {
        temp->name = n;
        temp->prew = top;
        top = temp;
    }
}
void pop() {
    if (top == NULL) {
        cout << "Nothing to pop, Stack is Empty\n";
    } else {
        top = top->prew;
        cout << "Item Popped\n";
    }
}
void display() {
    if (!top) {
        cout << "Nothing to show, Stack is Empty\n";
    } else {
        stack *temp = top;
        while (temp) {
            cout << temp->name << endl;
            temp = temp->prew;
        }
        free(temp);
    }
}
void peek() {
    if (!top) {
        cout << "Nothing to show, Stack is Empty\n";
    } else
        cout << top->name << endl; // return value
}
void is_Empty() {
    if (!top) {
        cout << "Stack is Empty\n";
    } else
        cout << "Stack not Empty\n";
}
int main() {
    push("arsalan");
    push("adil");
    push("asif");
    push("aakil");

    display();
    cout << "\n\n";
    pop();
    pop();

    display();

    cout << "\n\n";
    peek();
    is_Empty();

    return 0;
}