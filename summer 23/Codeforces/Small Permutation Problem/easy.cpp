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

int n, a[200001];
ll E=998244353;

ll solve(){
    for (int i=0; i<=n; i++){
        if (a[i]>i) return 0; //need a[i]<=i for all i
    }
    if (a[n]!=n) return 0;
    ll T=1;
    for (int i=1; i<=n; i++){
        if (a[i]<a[i-1]) return 0;
        else if (a[i]==a[i-1]) T*=1;
        else if (a[i]==a[i-1]+1) T=(T*(ll)(2*i-1-2*a[i-1]))%E;
        else if (a[i]==a[i-1]+2) T=(T*(((ll)(i-1-a[i-1])*(ll)(i-1-a[i-1]))%E))%E;
        else return 0;
    }
    return T;
}

int main(){
    a[0]=0;
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        cin>>n;
        for (int i=1; i<=n; i++) cin>>a[i];
        cout<<solve()<<"\n";
    }
}
