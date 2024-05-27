#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <numeric>
using namespace std;
using ll=long long;
using ld=long double;

int main(){
    ifstream cin("file.in");
    ofstream cout("output.out");
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        int n;
        cin>>n;
        char s[3][n+1];
        s[1][0]='.', s[2][0]='.';
        for (int i=1; i<=2; i++){
            for (int j=1; j<=n; j++) cin>>s[i][j];
        }
        vector<pair<int, int>> bars;
        int start;
        for (int i=1; i<=2; i++){
            for (int j=1; j<=n+1; j++){
                if (s[i][j]=='*' && s[i][j-1]!='*') start=j;
                if (s[i][j]=='*' && ((j==n)||(s[i][j+1]!='*'))) bars.push_back({start, j});
            }
        }
        // for (pair<int, int> p: bars) cout<<p.first<<" "<<p.second<<"\n";
        cout<<n-bars.size()<<"\n";
    }
    // vector<int> v{1, 2, 3, 4};
    // cout<<v[10]<<"\n";
}
