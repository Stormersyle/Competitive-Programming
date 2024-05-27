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
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        int n;
        cin>>n;
        ll a[n+1];
        for (int i=1; i<=n; i++) cin>>a[i];
        ll suf[n+2];
        suf[n+1]=0;
        for (int i=n; i>=1; i--) suf[i]=suf[i+1]+a[i];
        ll T=suf[1];
        for (int i=2; i<=n; i++){
            if (suf[i]>0) T+=suf[i];
        }
        cout<<T<<"\n";
    }
}
