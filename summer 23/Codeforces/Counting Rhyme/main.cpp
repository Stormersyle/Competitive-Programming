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
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        int n;
        cin>>n;
        int a[n+1], fr[n+1];
        for (int x=1; x<=n; x++) fr[x]=0;
        for (int i=1; i<=n; i++) cin>>a[i], fr[a[i]]++;
        int mults[n+1];
        ll gcd_cnt[n+1];
        for (int x=1; x<=n; x++) mults[x]=0;
        for (int x=1; x<=n; x++){
            for (int y=x; y<=n; y+=x) mults[x]+=fr[y];
        }
        for (int x=n; x>=1; x--){
            gcd_cnt[x]=((ll)(mults[x])*(ll)(mults[x]-1))/2;
            for (int y=2*x; y<=n; y+=x) gcd_cnt[x]-=gcd_cnt[y];
        }
        bool has_factor[n+1]; //whether x has factor in array
        for (int x=1; x<=n; x++) has_factor[x]=false;
        set<int> vals;
        for (int i=1; i<=n; i++) vals.insert(a[i]);
        for (int x: vals){
            for (int y=x; y<=n; y+=x) has_factor[y]=true;
        }
        ll T=0;
        for (int x=1; x<=n; x++){
            if (!has_factor[x]) T+=gcd_cnt[x];
        }
        cout<<T<<"\n";
    }
}
