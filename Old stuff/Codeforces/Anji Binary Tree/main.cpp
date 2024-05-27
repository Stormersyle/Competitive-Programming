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

int n, L[300001], R[300001], f[300001];
char s[300001];

void dp(int x){
    if (x==0) return;
    if ((L[x]==0)&&(R[x]==0)){
        f[x]=0;
        return;
    }
    dp(L[x]), dp(R[x]);
    if (s[x]=='U') f[x]=1+min(f[L[x]], f[R[x]]);
    else if (s[x]=='L') f[x]=min(f[L[x]], 1+f[R[x]]);
    else f[x]=min(f[R[x]], 1+f[L[x]]);
}

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        string s0;
        cin>>n>>s0;
        for (int i=1; i<=n; i++) s[i]=s0[i-1];
        for (int x=1; x<=n; x++) cin>>L[x]>>R[x];
        f[0]=n+1;
        dp(1);
        cout<<f[1]<<"\n";
    }
}
