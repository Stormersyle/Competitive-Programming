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

int n, m;
string s, t;
deque<int> pos[26]; //pos of each character

bool solve(){
    for (int c=0; c<26; c++) pos[c].clear();
    for (int i=0; i<n; i++) pos[(int)(s[i]-'a')].push_back(i);
    for (char ch: t){
        int c=(int)(ch-'a');
        if (pos[c].size()==0) return false;
        int j=pos[c][0];
        pos[c].pop_front();
        for (int c1=0; c1<c; c1++){
            while ((pos[c1].size()>0)&&(pos[c1][0]<j)) pos[c1].pop_front();
        }
    }
    return true;
}

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ts;
    cin>>ts;
    for (int z=0; z<ts; z++){
        cin>>n>>m>>s>>t;
        if (solve()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
