#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int low, int high)
{
    if (low == high)
        return arr[low];

    // divide
    int mid = (low + high) / 2;

    // conquer
    int leftMaxSum = maxSum(arr, low, mid);
    int rightMaxSum = maxSum(arr, mid + 1, high);

    // combine
    int sum = 0, lmax = INT_MIN, rmax = INT_MIN, i = mid;
    while (i >= low)
    {
        sum += arr[i];
        lmax = max(lmax, sum);
        i--;
    }
    sum = 0;
    i = mid + 1;
    while (i <= high)
    {
        sum += arr[i];
        rmax = max(rmax, sum);
        i++;
    }
    int corssingSum = lmax + rmax;
    return max(corssingSum, max(leftMaxSum, rightMaxSum));
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxSum(arr, 0, n - 1) << endl;

    return 0;
}


// 8
// -3 -4 5 -1 2 -4 6 -1