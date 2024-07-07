#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int lb, int ub) {
    int pivot = arr[ub];
    int i = lb - 1;

    for (int j = lb; j < ub ; j++) {
        if (arr[j] < pivot) {          //to reverse sort use this :  <
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[ub]);

    return i + 1;
}
void quicksort(int arr[], int start, int end) {
    if (start < end) {
        int p = partition(arr, start, end);
        quicksort(arr, start, p - 1);
        quicksort(arr, p + 1, end);
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {10, 0, 5, 3, 5, 1, 7, 9, 5, 4};
    int size = sizeof(arr) / sizeof(int);

    print(arr, size);

    quicksort(arr, 0, size - 1);

    print(arr, size);

    return 0;
}
