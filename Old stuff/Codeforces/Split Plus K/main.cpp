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
ll k, a[200001];

// ll GCD(ll x, ll y){
//     if (y == 0) return x;
//     return GCD(y, x%y);
// }

ll solve(){
    bool gr_k=false, le_k=false, eq_k=false;
    for (int i=1; i<=n; i++){
        if (a[i]>k) gr_k=true;
        if (a[i]<k) le_k=true;
        if (a[i]==k) eq_k=true;
    }
    if (eq_k){ //if one equal, need all equal
        if (gr_k || le_k) return -1;
        return 0;
    }
    if (gr_k && le_k) return -1;
    vector<ll> diffs;
    for (int i=1; i<=n; i++) diffs.push_back(abs(a[i]-k));
    ll d=diffs[0], T=0;
    for (ll x: diffs) d=__gcd(d, x);
    for (ll x: diffs) T+=(x/d-1);
    // for (int x: diffs) cout<<x<<" ";
    // cout<<"\n"<<d<<" "<<T<<"\n";
    return T;
}

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        cin>>n>>k;
        for (int i=1; i<=n; i++) cin>>a[i];
        cout<<solve()<<"\n";
    }
}
