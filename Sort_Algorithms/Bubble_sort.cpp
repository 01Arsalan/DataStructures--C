#include <cstdlib>
#include <iostream>
using namespace std;

void Bsort1D(int *arr, int size) {
    
    for (int j = 0; j < size; j++)
        for (int i = 0; i < size; i++) {
            if (arr[j] < arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
}
void Bsort2D(int (*arr)[6], int rows) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < rows; k++) {
                for (int l = 0; l < 6; l++) {
                    if (arr[i][j] < arr[k][l]) {
                        int temp = arr[i][j];
                        arr[i][j] = arr[k][l];
                        arr[k][l] = temp;
                    }
                }
            }
        }
    }
}
void Bsort3D(int (*arr)[4][4], int rows) {

    for (int m = 0; m < 2; m++) {
        for (int n = 0; n < 2; n++) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < rows; k++) {
                        for (int l = 0; l < 4; l++) {
                            if (arr[m][i][j] < arr[n][k][l]) {
                                int temp = arr[m][i][j];
                                arr[m][i][j] = arr[n][k][l];
                                arr[n][k][l] = temp;
                            }
                        }
                    }
                }
            }
        }
    }
}

void display1D(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << "\n\n";
}
void display2D(int arr[][6], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 6; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
}
void display3D(int arr[][4][4], int rows) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < rows; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "\n\n";
}

int main() {
    srand(time(0));

    int arr[20];
    for (int i = 0; i < 20; i++) {
        arr[i] = rand() % 20;
    }

    int arr1[6][6];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            arr1[i][j] = rand() % 100;
        }
    }

    int arr2[2][4][4];
    srand(time(0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                arr2[i][j][k] = rand() % 50;
            }
        }
    }

    cout << "\n1D Array Before and After Sort \n\n";
    display1D(arr, sizeof(arr) / sizeof(int));
    Bsort1D(arr, sizeof(arr) / sizeof(int));
    display1D(arr, sizeof(arr) / sizeof(int));

    cout << "\n2D Array Before and After Sort \n\n";

    display2D(arr1, 6);
    Bsort2D(arr1, 6);
    display2D(arr1, 6);

    cout << "\n3D Array Before and After Sort \n\n";

    display3D(arr2, 4);
    Bsort3D(arr2, 4);
    display3D(arr2, 4);

    return 0;
}