#include <bits/stdc++.h>
using namespace std;

int m, n;
int grid[100][100];
int memo[100][100];

int maxPath(int i, int j){
    if(i == m-1 && j == n-1)
        return grid[i][j];  //destination = source
    if(i >=m || j >= n )
        return INT_MIN; //grid out of bound
    
    if(memo[i][j] != -1) 
        return memo[i][j];
    memo[i][j] = grid[i][j]+ max(maxPath(i+1, j), maxPath(i, j+1));
    return memo[i][j];
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    memset(memo, -1, sizeof(memo));
    cout << maxPath(0, 0) << endl;
    return 0;
}