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
        int n, k;
        cin>>n>>k;
        int a[n+1];
        for (int i=1; i<=n; i++) cin>>a[i];
        if (k>=2) cout<<"YES\n";
        else{
            bool check=true;
            for (int i=1; i<=n-1; i++){
                if (a[i]>a[i+1]) check=false;
            }
            if (check) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
