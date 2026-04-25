#include <bits/stdc++.h>
using namespace std;

// int climbStairs(int n){
//     if(n == 1 || n == 2) return n;

//     return climbStairs(n-1) + climbStairs(n-2);
// }


int dp[1005];

// int fib(int n){
//     if(n == 1 || n == 2) return n;
//     if(dp[n] != -1) return dp[n];

//     dp[n] = fib(n-1) + fib(n-2);
//     return dp[n];
// }

// int climbStairs(int n){
//     int ans = fib(n);
//     return ans;
// }

int climbStairs(int n){
    if(n == 1 || n == 2) return n;

    if(dp[n] != -1) return dp[n];

    dp[n] = climbStairs(n-1) + climbStairs(n-2);
    return dp[n];
}

int main() {

    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));

    cout << climbStairs(n) << endl;
    return 0;
}