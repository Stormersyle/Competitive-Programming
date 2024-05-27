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

int n, q;
ll a[100001], og[100001], inc[100001];

ll solve(ll x){ //max bitwise AND if total increase<=x
    for (int i=1; i<=n; i++) a[i]=og[i];
    for (int b=59; b>=0; b--){
        for (int i=1; i<=n; i++){
            if ((a[i]>>b)%2==1) inc[i]=0;
            else inc[i]=(1LL<<b)-(a[i]%(1LL<<b));
        }
        ll T=0;
        for (int i=1; i<=n; i++){
            T+=inc[i];
            if (T>x) break; //prevent integer overflow
        }
        if (T<=x){
            x-=T;
            for (int i=1; i<=n; i++) a[i]+=inc[i];
        }
    }
    ll A=(1LL<<60)-1;
    for (int i=1; i<=n; i++) A&=a[i];
    return A;
}

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    cin>>n>>q;
    for (int i=1; i<=n; i++) cin>>og[i];
    for (int z=0; z<q; z++){
        ll x;
        cin>>x;
        cout<<solve(x)<<"\n";
    }
}
