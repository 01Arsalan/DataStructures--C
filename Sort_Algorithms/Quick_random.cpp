#include <iostream>
#include <stdlib.h>
using namespace std;

void print(int *arr, int n) { // using this function to print the array.
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void swap(int *a, int *b) { // this functin will swap the values at different indexes
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int lb, int ub) { // this will partition the array into two parts and between them,
    int i = lb - 1;                        // it will place the pivot between them and one side will contain
    int pivot = arr[ub];                   // elements smaller than pivot and another side will contain elements
    for (int j = lb; j < ub; j++) {        // greater than pivot.
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[ub]);
    return i + 1;
}
int partition_random(int arr[], int lb, int ub) { // this will give us a random element as pivot and relace it
    srand(time(NULL));                            // with the last element of upper-bound
    int random = lb + rand() % (ub - lb);
    swap(&arr[random], &arr[ub]);
    return partition(arr, lb, ub);
}
void quick(int *arr, int start, int end) { // this function will be used for recursion till start is
    if (start < end) {                     // greater than end
        int p = partition_random(arr, start, end);
        quick(arr, start, p - 1);
        quick(arr, p + 1, end);
    }
}

int main() {
    int arr[] = {5, 7, 7, 4, 2, 5, 7, 8, 3, 2, 8, 0, 9};
    int size = sizeof(arr) / sizeof(int);

    cout << "Before sorting : ";
    print(arr, size);
    quick(arr, 0, size - 1);
    cout << "\nAfter sorting : ";
    print(arr, size);
}