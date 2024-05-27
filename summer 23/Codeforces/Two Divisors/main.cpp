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

ll solve(ll a, ll b){
    if (b%a==0) return b*b/a;
    return (a*b)/(__gcd(a, b));
}

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        ll a, b;
        cin>>a>>b;
        cout<<solve(a, b)<<"\n";
    }
}
