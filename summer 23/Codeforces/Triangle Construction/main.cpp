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
    ifstream cin("x_input.txt");
    ofstream cout("x_output.txt");
    int n;
    cin>>n;
    ll a[n];
    for (int i=0; i<n; i++) cin>>a[i];
    ll M=*max_element(a, a+n);
    ll sum=0;
    for (ll x: a) sum+=x;
    ll sum_rest=sum-M;
    if (M>2*sum_rest) cout<<sum_rest<<"\n";
    else cout<<sum/3<<"\n";
}
