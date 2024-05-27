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

ll E=998244353;
ll factE[1000001], invE[1000001]; //factE[n]= n! (mod E); invE[n] = 1/n! (mod E)

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

ll trinomial(ll n, ll a, ll b, ll c){
    ll T=(factE[n]*invE[a])%E;
    T=(T*invE[b])%E, T=(T*invE[c])%E;
    return T;
}

ll numsols(int n, int x){ //num of solutions to a_1+...+a_n=x, for a_i=0, 1, 2
    ll T=0;
    for (int c=0; c<=x/2; c++){
        int b=x-2*c;
        int a=n-b-c;
        if (min(a, min(b, c))>=0) T=(T+trinomial((ll)(n), (ll)(a), (ll)(b), (ll)(c)))%E;
    }
    return T;
}

void setup(){
  factE[0]=1;
  for (int k=1; k<=1000000; k++) factE[k]=(factE[k-1]*k)%E;
  invE[1000000]=binPow(factE[1000000], E-2, E);
  for (int k=999999; k>=0; k--) invE[k]=(invE[k+1]*(k+1))%E;
}

int main(){
    setup();
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    int ts;
    cin>>ts;
    for (int z=0; z<ts; z++){
        int n, k;
        cin>>n>>k;
        int t=n/(2*k)-1, r=n%(2*k);
        ll M=(ll)(k*t+r)*(ll)(t+1); //min inconvenience
        ll T=0; //number of seatings
        if (n<2*k) T=choose((ll)(k-1), (ll)(n-k-1));
        else{
            for (int a0=0; a0<=1; a0++){
                for (int ak=0; ak<=1; ak++){
                    if ((0<=r-a0-ak)&&(r-a0-ak<=2*k-2)) T=(T+numsols(k-1, r-a0-ak))%E;
                }
            }
        }
        cout<<M<<" "<<T<<"\n";
    }
}
