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
    int ts;
    cin>>ts;
    for (int z=0; z<ts; z++){
        int n;
        string s;
        cin>>n>>s;
        s="0"+s;
        char max_char='a';
        vector<char> a; //chars in max subseq
        vector<int> t; //indexes of max subseq
        for (int i=n; i>=1; i--){
            max_char=max(max_char, s[i]);
            if (s[i]==max_char) a.push_back(s[i]), t.push_back(i);
        }
        reverse(a.begin(), a.end()), reverse(t.begin(), t.end());
        int k=a.size(), lastpos;
        for (int i=0; i<k; i++){
            if (a[i]==max_char) lastpos=i;
        }

        int r=k-1-lastpos; //amount we shift by
        sort(a.begin(), a.end());
        for (int i=0; i<k; i++) s[t[i]]=a[i];
        bool check=true; //check sorted
        for (int i=1; i<=n-1; i++){
            if (s[i]>s[i+1]) check=false;
        }
        if (check) cout<<r<<"\n";
        else cout<<"-1\n";
    }
}
