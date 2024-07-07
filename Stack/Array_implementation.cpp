#include <iostream>
using namespace std;

int size = -1;
#define MAX 10

class stac {
public:
    string name[MAX];
    int top;
};

stac *create() {
    stac *s = (stac *)(malloc(sizeof(stac) * 1));
    s->top = -1;
    cout << "Stack Created Sucessfully.\n";
    return s;
}
void push(stac *s, string n) {
    s->top++;
    s->name[s->top] = n;
    size++;
}
void pop(stac *s) {
    if (s->top < 0) {
        cout << "Stack Is Empty.\n";
        size = 0;
    } else {
        s->name[s->top] = "...";
        s->top--;
        cout << "Item Popped\n";
        size--;
    }
}
void print(stac *s) {
    if (s->top < 0) {
        cout << "Nothing To Print. Stack Is Empty.\n";
    } else {
        for (int i = size; i >= 0; i--) {
            cout << s->name[i] << "\n";
        }
    }
}

int main() {
    stac *S = create();

    push(S, "Arsalan");
    push(S, "asif");
    push(S, "Adil");

    print(S);

    pop(S);

    print(S);

    pop(S);
    pop(S);

    print(S);

    return 0;
}