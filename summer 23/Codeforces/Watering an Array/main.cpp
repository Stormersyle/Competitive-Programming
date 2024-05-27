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

int n, k, d, a[2001], v[100001];

void add(int x){ //simulate, add on day x
    int i=x%k; //index in v
    if (i==0) i=k;
    for (int j=1; j<=v[i]; j++) a[j]++;
}

int count(){
    int T=0;
    for (int i=1; i<=n; i++){
        if (a[i]==i) T+=1;
    }
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
        cin>>n>>k>>d;
        for (int i=1; i<=n; i++) cin>>a[i];
        for (int i=1; i<=k; i++) cin>>v[i];
        vector<int> results;
        for (int x=1; x<=min(d, 2*n+1); x++) results.push_back(count()+(d-x)/2), add(x);
        // results when we first count on day x
        // for (int m: results) cout<<m<<" ";
        // cout<<"\n";
        int M=*max_element(results.begin(), results.end());
        cout<<M<<"\n";
    }
}
