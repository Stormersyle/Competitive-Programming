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
        string s;
        cin>>s;
        int n=s.length();
        s="0"+s;
        int zeros[n+1], ones[n+1], min_del=n;
        zeros[0]=0, ones[0]=0;
        for (int i=1; i<=n; i++) ones[i]=ones[i-1]+(int)(s[i]-'0'), zeros[i]=i-ones[i];
        for (int i=1; i<=n; i++){
            int x=zeros[n], y=ones[n], a=zeros[i], b=ones[i];
            if ((b<=x) && (a<=y)) min_del=x-b+y-a;
        }
        cout<<min_del<<"\n";
    }
}
