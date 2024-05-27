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

int n, a[200001];
ll factE[1000001], invE[1000001],E=998244353; //factE[n]= n! (mod E); invE[n] = 1/n! (mod E)

ll binPow(ll a, ll b, ll m){ //a^b (mod m)
  ll P=1, Pa=(a%m);
  while (b>0){
    if (b&1) P=(P*Pa)%m;
    Pa=(Pa*Pa)%m;
    b=b>>1;
  }
  return P;
}

ll choose(ll a, ll b){ //{a\choose b} (mod E)
  if (a<b) return 0;
  ll coeff=(((factE[a]*invE[b])%E)*invE[a-b])%E;
  return coeff;
}

void setup(){
  factE[0]=1;
  for (int k=1; k<=1000000; k++) factE[k]=(factE[k-1]*k)%E;
  invE[1000000]=binPow(factE[1000000], E-2, E);
  for (int k=999999; k>=0; k--) invE[k]=(invE[k+1]*(k+1))%E;
}

ll fill_SIP(ll i, ll j){ //fill SIP(i) upon finish filling SIP(j)
    ll k=(ll)(a[i]-a[j]);
    ll T=0;
    for (ll x=0; x<=k; x++){
        ll P1=(((choose(j-(ll)(a[j]), x)*choose(i-j,  x))%E)*factE[x])%E;
        ll P2=(((choose(i-j, k-x)*choose(i-(ll)(a[j])-x, k-x))%E)*factE[k-x])%E;
        T=(T+((P1*P2)%E))%E;
    }
    return T;
}

ll solve(){
    a[0]=0;
    if ((a[n]!=-1)&&(a[n]!=n)) return 0;
    a[n]=n;
    for (int i=1; i<=n; i++){
        if (a[i]>i) return 0;
    }
    vector<int> s; //indexes where we have restrictions
    for (int i=0; i<=n; i++){
        if (a[i]>=0) s.push_back(i);
    }
    int m=s.size()-1; //m>=1
    for (int i=1; i<=m; i++){
        if (a[s[i]]-a[s[i-1]]>2*(s[i]-s[i-1])) return 0;
    }
    //now, valid sequence.
    ll T=1;
    for (int t=1; t<=m; t++){
        ll i=(ll)(s[t]), j=(ll)(s[t-1]);
        T=(T*fill_SIP(i, j))%E;
    }
    return T;
}

int main(){
    setup();
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin>>tests;
    for (int z=0; z<tests; z++){
        cin>>n;
        for (int i=1; i<=n; i++) cin>>a[i];
        cout<<solve()<<"\n";
    }
}
