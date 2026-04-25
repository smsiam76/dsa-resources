#include <bits/stdc++.h>

using namespace std;

const long long N = 1e6+5;
long long dp[N];



int fib(long long n){
    if(n < 2) return n;

    if(dp[n] != -1) return dp[n];
    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];
}
int main() {

    memset(dp, -1, sizeof(dp));
    long long n;
    cin >> n;

    cout << fib(n);
    // cout << "Hello World";

    return 0;
}