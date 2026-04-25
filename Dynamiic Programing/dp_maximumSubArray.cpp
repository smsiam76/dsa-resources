#include <bits/stdc++.h>
using namespace std;

int n;
int nums[100];
int dp[100];

int maxValue(int i)
{
    if (i == 0)
        return nums[i];

    if (dp[i] != -1)
        return dp[i];

    // dp[i] = max(nums[i] + maxValue(i + 2), maxValue(i + 1));
    dp[i] = max(nums[i], nums[i] + maxValue(i - 1));
    
    return dp[i];
}

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    
    memset(dp, -1, sizeof dp);
    
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++){
        maxSum = max(maxSum, maxValue(i));
    }


    cout << maxSum << endl;


    return 0;
}

// 9
// -2 1 -3 4 -1 2 1 -5 4