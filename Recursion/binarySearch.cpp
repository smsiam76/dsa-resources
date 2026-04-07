#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int low, int high, int val)
{
    if (high >= low)
    {
        int mid = low + high / 2;

        if (arr[mid] == val)
            return mid;

        if (arr[mid] > val)
        {
            return binarySearch(arr, low, mid - 1, val);
        }
        return binarySearch(arr, mid + 1, high, val);
    }
    return -1;
}

int main()
{

    // cout << "Hello World";
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int x;
    cin >> x;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
    {
        cout << "Value not found";
    }
    else
    {
        cout << arr[result] << " Found";
    }
    return 0;
}