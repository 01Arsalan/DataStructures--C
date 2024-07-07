// Linear search.

#include <iostream>
using namespace std;

int main() {
    // int arr[2][3][3] = {{1, 1, 1,
    //                      2, 2, 2,
    //                      3, 3, 3},
    //                     {3, 3, 3,
    //                      2, 8, 2,
    //                      1, 1, 9}};

    // int search = 8;
    // int count =0;
    // for (int i = 0; i < 2; i++)
    // for (int j = 0; j < 3; j++)
    // for (int k = 0; k < 3; k++) {
    //     count++;
    //     if (arr[i][j][k] == search) {
    //         cout << "\n\nElement is at Matrix : "<<i << ", Row : " << j << ", Column : " << k;
    //         cout<<"\nLoop Executed "<<count <<" Times.\n";
    //         break;
    //     }
    // }

    // cout << "\n\n";

    //Binary search

    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,89,999};

    int search = 999; 
    int count=0;
    int end = sizeof(arr1) / sizeof(int), start = 0,half;


    for (int i = 0; i < 10; i++) {
        count++;
        half = (start + end) / 2;
        if (search == arr1[half]) {
            cout << "Element is at index : " << half;
            cout<<"\nLoop Executed "<<count <<" Times.\n\n\n";
            break;
        } else if (search > arr1[half]) {
            start = half;
        } else if (search < arr1[half]) {
            end = half;
        }
    }

    return 0;
}
