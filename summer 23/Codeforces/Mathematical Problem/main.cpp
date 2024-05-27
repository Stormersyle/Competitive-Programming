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

vector<string> ans[100];

void precompute_answers(){
    ans[1].push_back("1");
    ans[3].push_back("169"), ans[3].push_back("196"), ans[3].push_back("961");
    for (int n=5; n<=99; n+=2){
        for (string s: ans[n-2]) ans[n].push_back(s+"00");
        string zeros((n-3)/2, '0');
        ans[n].push_back('1'+zeros+'6'+zeros+'9'), ans[n].push_back('9'+zeros+'6'+zeros+'1');
    }
}

int main(){
    precompute_answers();
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        int n;
        cin>>n;
        for (string s: ans[n]) cout<<s<<" ";
        cout<<"\n";
    }
}
