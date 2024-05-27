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
        string s;
        cin>>n>>s;
        int T=0; //identity move sequence; leave as is
        set<char> chars;
        for (int i=0; i<n; i++) chars.insert(s[i]), T+=chars.size();
        cout<<T<<"\n";
    }
}
