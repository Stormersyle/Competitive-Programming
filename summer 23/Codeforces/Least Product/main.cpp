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
        int a[n+1];
        for (int i=1; i<=n; i++) cin>>a[i];
        int sign=1;
        for (int i=1; i<=n; i++){
            if (a[i]<0) sign*=(-1);
            else if (a[i]==0) sign=0;
        }
        if (sign==1) cout<<"1\n"<<"1 0\n";
        else cout<<"0\n";
    }
}
