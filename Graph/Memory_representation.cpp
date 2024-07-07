#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // n and m represents nodes and edges.

    int adj_m[n][n];

    for (int i = 0; i < n; i++) // intializing matrix with 0.
        for (int j = 0; j < n; j++) {
            adj_m[i][j] = 0;
        }

    for (int i = 0; i < m; i++) { // taking input & and linking input into adj matrix.
        int x, y;
        cin >> x >> y;
        adj_m[x - 1][y - 1] = 1;
        adj_m[y - 1][x - 1] = 1;
    }

    cout << "Adjacency matrix of given graph is givn by : " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj_m[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Adjacency list of given graph is givn by : " << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < n; j++) {
            if (adj_m[i][j] == true) {
                cout << "-> " << j + 1 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}