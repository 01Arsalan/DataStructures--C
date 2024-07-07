#include<iostream>
using namespace std;

int main(){

int d1,d2;
cout<<"Enter Array Dimentions : ";
cin>>d1>>d2;

int arr[d1][d2];
int min[d2];
int max[d2];

cout<<"Input into array : \n";
for(int i=0;i<d1;i++){
    for(int j=0;j<d2;j++){
        cin>>arr[i][j];
    } 
}      
for(int i=0;i<d1;i++){
    for(int j=0;j<d2;j++){
        if(arr[i][0]<arr[i][j]){
            int temp=arr[i][0];
            arr[i][0]=arr[i][j];
            arr[i][j]=temp;
        }
        max[i]=arr[i][0];
    } 
    
}   
cout<<"Maximum values in array are : ";
for(int i=0;i<d1;i++){
    cout<<max[i]<<',';
}
cout<<endl;
for(int i=0;i<d1;i++){
    for(int j=0;j<d2;j++){
        if(arr[i][0]>arr[i][j]){
            int temp=arr[i][0];
            arr[i][0]=arr[i][j];
        }
        min[i]=arr[i][0];
    } 
    
} 
cout<<"Minimum values in array are : ";
for(int i=0;i<d1;i++){
    cout<<min[i]<<',';
}
cout<<"\n\n\n";
    return 0;
}