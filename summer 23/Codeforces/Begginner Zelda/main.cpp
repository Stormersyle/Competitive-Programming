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
        int deg[n+1];
        for (int x=1; x<=n; x++) deg[x]=0;
        for (int i=1; i<=n-1; i++){
            int u, v;
            cin>>u>>v, deg[u]++, deg[v]++;
        }
        int leaves=0;
        for (int x=1; x<=n; x++){
            if (deg[x]==1) leaves++;
        }
        cout<<(leaves+1)/2<<"\n";
    }
}
