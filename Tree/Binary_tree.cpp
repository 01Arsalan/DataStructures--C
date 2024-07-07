#include <iostream>
using namespace std;

class ll {
public:
    int n;
    ll *left, *right;
};
ll *root = NULL, *current = NULL;
void create_tree(string s) {
    if (root == NULL) {
        root = new ll();
        cout << "Enter values for Root Node" << endl;
        current = root;
    }
    cout << "Node " << s << " : " << endl;
    cin >> current->n;
    int c;
    cout << "Right || Enter 2 : Left || Enter 0 : back\n: ";
    cin >> c;
    if (c == 0) {
        return;
    } else if (c == 2) {
        ll *temp = new ll();
        current->left = temp;
        current = current->left;
        create_tree("Left");
    }
    ll *temp = new ll();
    current->right = temp;
    current = current->right;
    create_tree("Right");

    current = root;
    return;
}
int traverse() {
    if (current == NULL) {
        cout << "Tree Empty\n";
        return 0;
    }
    cout << current->n << endl;
    if (current->left != NULL) {
        current = current->left;
        traverse();
    } else if (current->right != NULL) {
        current = current->right;
        traverse();
    }
    return 1;
}

int main() {
    create_tree("Root");
    traverse();
}