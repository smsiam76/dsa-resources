#include <bits/stdc++.h>

using namespace std;

int m = 4;
int coins[] = {1, 4, 7,13};
int memo[100];
int coinChange(int n){
    if(n == 0) return 0;
    if(n < 0) return INT_MAX;
    if(memo[n] != -1) return memo[n];

    int minimum = INT_MAX;
    for(int i = 0; i < m; i++){
        minimum = min(minimum, coinChange(n-coins[i]));
        memo[n] = 1 + minimum;
    }
    return memo[n];

}
int main() {

    memset(memo, -1, sizeof(memo));

    int n;
    cin >> n;
    cout << coinChange(n);
    return 0;
}