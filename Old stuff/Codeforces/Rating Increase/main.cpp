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
        int j=-1; //first nonzero char, after first one.
        for (int i=1; i<s.size(); i++){
            if ((int)(s[i])>(int)('0')){
                j=i;
                break;
            }
        }
        if ((s[0]=='0') || (j==-1)) cout<<"-1\n";
        else{
            int a=stoi(s.substr(0, j)), b=stoi(s.substr(j));
            if (a<b) cout<<a<<" "<<b<<"\n";
            else cout<<"-1\n";
        }
    }
}
