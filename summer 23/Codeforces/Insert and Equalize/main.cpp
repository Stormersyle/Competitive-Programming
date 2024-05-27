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

int n;
ll a[200001];

ll solve(){
    ll M=*max_element(a+1, a+n+1);
    vector<ll> diffs;
    for (int i=1; i<=n-1; i++){
        if (a[i]!=a[i+1]) diffs.push_back(abs(a[i+1]-a[i]));
    }
    if (diffs.size()==0) return 1;
    ll x=diffs[0];
    for (ll d: diffs) x=__gcd(x, d);
    ll T=0;
    for (int i=1; i<=n; i++) T+=((M-a[i])/x);
    ll k;
    set<ll> A;
    for (int i=1; i<=n; i++) A.insert(a[i]);
    for (ll i=1; i<=(ll)(n); i++){
        if (A.find(M-i*x)==A.end()){
            k=i;
            break;
        }
    }
    T+=k;
    return T;
}

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        cin>>n;
        for (int i=1; i<=n; i++) cin>>a[i];
        cout<<solve()<<"\n";
    }
}
