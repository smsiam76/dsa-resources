#include <bits/stdc++.h>
using namespace std;

int n;
int nums[100];
int memo[100];

int LIS(int i)
{

    if(memo[i] != -1) return memo[i];

    int best = 1;
    for (int j = 0; j < i; j++)
    {
        if (nums[j] < nums[i])
        {
            best = max(best, LIS(j) + 1);
        }
    }
    memo[i] = best;
    return memo[i];
}

int main()
{

    cin >> n;
     for(int i = 0; i < n; i++){
        cin >> nums[i];
     }
     memset(memo, -1, sizeof(memo));

     int res = 1;
     for(int i = 0; i < n; i++){
        res = max(res, LIS(i));
     }

     cout << res << endl;


    return 0;
}


// 8
// 10 9 2 5 3 7 101 18

// 6
// 0 1 0 3 2 3

// 7
// 7 7 7 7 7 7 7