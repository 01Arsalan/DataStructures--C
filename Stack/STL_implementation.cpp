#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> name;
    name.push("arsalan");
    name.push("adil");
    name.push("asif");

    string t = name.top();
    cout << t << endl;
    name.pop();
    t = name.top();
    cout << t << endl;
    name.pop();
    t = name.top();
    cout << t;
    name.pop();

    return 0;
}