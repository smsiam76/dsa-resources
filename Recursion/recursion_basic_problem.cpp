#include <bits/stdc++.h>

using namespace std;

// problem 1
void printNumber(int n){
    if(n == 0) return;
    cout << n << " " ;
    printNumber(n-1);
}

// problem 2
int totalSum(int n){
    if(n == 1) return 1;
    return n + totalSum(n-1);
}

// problem 3
int fact(int n){
    // if(n < 0) return 0;
    if( n == 0) return 1;
    return n * fact(n-1);
}

// problem 4
int sumOfDigits(int n){
    if(n == 0) return 0;
    return n%10 + sumOfDigits(n/10);
}

// problem 5
int countDigits(int n){
    if(n < 10)  return 1;
    return 1 + countDigits(n/10);
}

// problem 6
int fibonacci(int n){
    if( n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

// problem 7
int power(int a, int b){
    if(b == 0) return 1;
    return a * power(a, b-1);
}

// problem 8
void printList(int arr[], int n){
    if( n == 0) return;
    printList(arr, n-1); 
    cout << arr[n-1] << " ";
}

// problem 9
int findMax(int arr[], int n){
    if( n == 1) return arr[n];

    return max(arr[n-1], findMax(arr, n-1));
}

// problem 10
int findMin(int arr[], int n){
    if( n == 1) return arr[n];

    return min(arr[n-1], findMin(arr, n-1));
}
int main() {
     int n;
     cin >> n;
    // printNumber(n);
    // cout << totalSum(n) << endl;
    
    // cout << fact(n) << endl;
    // cout << sumOfDigits(n) << endl;
    // cout << countDigits(n) << endl;
    // cout << fibonacci(n) << endl;
    // int a, b;
    // cin >> a >> b;
    // cout << power(a, b) << endl;

    int marks[n];
    for(int i = 0; i < n; i++){
        cin >> marks[i];
    }
    // for(int i = 0; i < n; i++){
    //     cout << marks[i] << " ";
    // }
    // printList(marks, n);
    // cout <<"max marks : " << findMax(marks, n);
    cout <<"min marks : " << findMin(marks, n);
    return 0;
}