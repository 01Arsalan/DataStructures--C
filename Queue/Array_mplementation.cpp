#include <iostream> // behaves as a circular  // needs more work
using namespace std;

#define MAX 10
class Queue {
public:
    int num[MAX];
    int front, rear;
};
Queue *que = new Queue();
Queue *create() {
    que->front = -1;
    que->rear = -1;
    return que;
}
void enQue(int n) {
    if (que->rear == MAX) {
        cout << "Over Flow\n";
        exit(0);
    }
    que->rear++;
    que->num[que->rear] = n;
    if (que->rear == 0) {
        que->front++;
    }
}
int deQue() {
    int t = que->num[que->front];
    que->front++;
    if (que->front == que->rear + 1) {
        que->front = -1;
        que->rear = -1;
    }
    return t;
}

int main() {
    create();

    enQue(12);
    enQue(14);
    enQue(15);
    enQue(17);
    enQue(12);

    cout << deQue();
    cout << deQue();
    cout << deQue();
    cout << deQue();
    enQue(11);
    enQue(11);
    enQue(10);
    cout << deQue();
    cout << deQue();
    cout << deQue();
    cout << deQue();
    cout << deQue();
    cout << deQue();

    return 0;
}