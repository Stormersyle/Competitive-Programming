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

int m, fr[30]; //fr[i]=frequency of ith bit

bool check(int x){
    int x1=x;
    for (int k=29; k>=0; k--){
        int tk=(1<<k);
        if (tk>x1) continue;
        int t=min(fr[k], x1/tk); //how many we take
        x1-=(t*tk);
    }
    return (x1==0);
}

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i=0; i<=29; i++) fr[i]=0;
    cin>>m;
    for (int t=0; t<m; t++){
        int type, x;
        cin>>type>>x;
        if (type==1) fr[x]++;
        else{
            if (check(x)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
