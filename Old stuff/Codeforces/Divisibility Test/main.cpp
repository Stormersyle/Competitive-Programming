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

int sieve[1000001];

void setup_sieve(){
    for (int x=2; x<=1000000; x++) sieve[x]=0;
    for (int x=2; x<=1000000; x++){
        if (sieve[x]==0){
            for (int y=2*x; y<=1000000; y+=x) sieve[y]=x;
        }
    }
}

set<int> prime_factors(int x){
    int x1=x;
    set<int> primeset;
    while (sieve[x1]!=0) primeset.insert(sieve[x1]), x1/=sieve[x1];
    primeset.insert(x1);
    return primeset;
}

int first_mod0(ll b, ll n){
    set<int> sb=prime_factors((int)(b)), sn=prime_factors((int)(n));
    for (int x: sn){
        if (find(sb.begin(), sb.end(), x)==sb.end()) return -1;
    }
    int k=0;
    ll bk=1;
    while (bk!= 0) bk=(bk*b)%n, k++;
    return k;
}

pair<int, int> first_mod1(ll b, ll n){
    int k=1;
    ll bk=b%n;
    while ((bk!=1)&&(bk!=n-1)) bk=(bk*b)%n, k++;
    int test;
    if (bk==1) test=2;
    else test=3;
    return {k, test};
}

int main(){
    setup_sieve();
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        int b, n;
        cin>>b>>n;
        if (__gcd(b, n)==1){
            pair<int, int> res=first_mod1((ll)(b), (ll)(n));
            cout<<res.second<<" "<<res.first<<"\n";
        }
        else{
            int res=first_mod0((ll)(b), (ll)(n));
            if (res==-1) cout<<"0\n";
            else cout<<"1 "<<res<<"\n";
        }
    }
}
