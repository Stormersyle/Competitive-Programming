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

//single digit case: 3 things sum to n: (n+2\choose 2)
map<int, int> triples;

int main(){
    for (int n=0; n<=9; n++) triples[n]=((n+2)*(n+1))/2;
    ifstream cin("file.in");
    ofstream cout("output.out");
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        int n;
        cin>>n;
        vector<int> digits;
        int n1=n;
        for (int i=0; i<=7; i++) digits.push_back(n1%10), n1/=10;
        ll T=1;
        for (int d: digits) T*=(ll)(triples[d]);
        cout<<T<<"\n";
    }
}
