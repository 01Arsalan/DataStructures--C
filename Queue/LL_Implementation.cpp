#include <iostream>
using namespace std;

class queue {
public:
    int num;
    queue *next;
};
queue *front = NULL, *rear = NULL;

void enque(int n) {
    queue *temp = new queue();
    if (!temp) {
        cout << "Memory Allocation Failed";
        exit(1);
    }
    if (rear == NULL) {
        rear = temp;
        rear->num = n;
        rear->next = NULL;
        front = rear;
    } else {
        rear->next = temp;
        temp->num = n;
        rear = rear->next;
        rear->next=NULL;
    }
}
int deque() {
    if (front == NULL) {
        cout << "\nQueue is Empty ";
        return 0;
    }
    int n = front->num;
    front = front->next;
    if (front == NULL)                  // if queue becomes empty, (rear==NULL) will be used to insert values into queue again.
        rear = NULL;
    return n;
}

int main() {
    enque(1);
    enque(2);
    enque(3);
    cout << deque();
    cout << deque();
    cout << deque();
    cout << deque();
    cout<<endl;
    enque(6);
    cout << deque();
    return 0;
}
