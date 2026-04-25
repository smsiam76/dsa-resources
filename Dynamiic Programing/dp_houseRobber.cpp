#include <bits/stdc++.h>
using namespace std;

int dp[100];
int rob(int nums[],int i, int n){
    if(i >= n) return 0;

    if(dp[i] != -1) return dp[i];

    dp[i] = max(nums[i] + rob(nums,i+2, n), rob(nums,i+1, n));
    return dp[i];
}

int main (){

    int n;
    cin >> n;

    int nums[n];
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << rob(nums, 0, n) << endl;
    return 0;
}