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
        cin>>n;
        ll a[n+1], s[n+1];
        int num_odds[n+1];
        for (int i=1; i<=n; i++) cin>>a[i];
        s[0]=0, num_odds[0]=0;
        for (int i=1; i<=n; i++) s[i]=s[i-1]+a[i];
        for (int i=1; i<=n; i++) num_odds[i]=num_odds[i-1]+(a[i]%2);

        ll final_num[n+1];
        final_num[1]=s[1];
        for (int i=2; i<=n; i++){
            int k=num_odds[i];
            if (k%3==1) final_num[i]=s[i]-(ll)(k/3+1);
            else final_num[i]=s[i]-(ll)(k/3);
        }
        for (int i=1; i<=n; i++) cout<<final_num[i]<<" ";
        cout<<"\n";
    }
}
