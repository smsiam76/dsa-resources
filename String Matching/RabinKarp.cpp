#include <bits/stdc++.h>
using namespace std;

int main(){

    string text, pattern;
    cin >> text >> pattern;

    int n = text.length();
    int m = pattern.length();

    int currentHash = 0, patternHash = 0, prod = 1;

    for(int i = m-1; i >= 0; i--){
        currentHash += text[i]*prod;
        patternHash += pattern[i]* prod;
        prod *= 26;
    }
    prod /= 26;
    if(currentHash == patternHash){
        cout << "pattern found at position 0" << endl;

        for(int i = 1; i <=n-m; i++){
            currentHash = (currentHash - text[i-1]*prod)*26+ text[i+m-1];
            if(currentHash == patternHash){
                cout << "pattern found at position " << i << endl;
            }
        }
    }


    return 0;
}