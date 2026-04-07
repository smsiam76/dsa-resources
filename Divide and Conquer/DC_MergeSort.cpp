#include <bits/stdc++.h>

using namespace std;

void mergeSort(int arr[], int low, int high)
{
    if (low == high)  
        return; //If the array has only one element, it's already sorted → stop recursion

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid); //left
    mergeSort(arr, mid + 1, high); //right

    int temp[high - low + 1]; //temporary array to store sorted result
    int left = low, right = mid + 1, i = 0;

    // left → pointer for left half || right → pointer for right half
    // i → index for temp array

    while (left <= mid && right <= high) //Compare elements from both halves
    {
        if (arr[left] < arr[right])
        {
            temp[i] = arr[left];
            left++;
            i++;
        }
        else
        {
            temp[i] = arr[right];
            right++;
            i++;
        }
    }
    while (left <= mid)
    {
        temp[i] = arr[left];
        left++;
        i++;
    }
    
    while (right <= high)
    {
        temp[i] = arr[right];
        right++;
        i++;
    }

    // Copy Back to Original Array
    for (int j = low; j <= high; j++)
    {
        arr[j] = temp[j - low];
    }
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    mergeSort(arr, 0, n - 1);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}