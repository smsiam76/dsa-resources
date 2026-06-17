#include <bits/stdc++.h>
using namespace std;

int main(){

    string text;
    string pattern;
    cin >> text >> pattern;
    int n = text.length();
    int m = pattern.length();
    for(int i = 0; i < n-m; i++){
        int j = 0;
        while(j < m and pattern[j] == text[j+i]){
            j++;
        }
       if(j == m)cout << "pattern found at position " << i << endl;
    }

    return 0;
}
