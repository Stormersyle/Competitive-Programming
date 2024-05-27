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

int A[2000001], B[2000001], X[6000001], Y[6000001], n;

bool checkReverse(int k){
  for (int i=1; i<=n; i++){
    if (X[k+i]!=Y[k+(n+1-i)]) return false;
  }
  return true;
}

int main() {
  ifstream cin("meta_game_input.txt");
  ofstream fout("output.txt");
  ios_base::sync_with_stdio(false); 
  cin.tie(0);
  int t;
  cin>>t;
  for (int z=1; z<=t; z++){
    cin>>n;
    for (int i=1; i<=n; i++) cin>>A[i];
    for (int i=1; i<=n; i++) cin>>B[i];
    for (int i=1; i<=n; i++) X[i]=A[i], X[n+i]=B[i], X[2*n+i]=A[i], Y[i]=B[i], Y[n+i]=A[i], Y[2*n+i]=B[i];
    int k=0, first=0, last=0, ans=-1; //shift; number of x<y in first half, number of x<y in last half
    for (int i=1; i<=n/2; i++){
      if (X[i]<Y[i]) first++;
      if (X[n+1-i]<Y[n+1-i]) last++;
    }
    while (k<2*n){
      // cout<<k<<" "<<first<<" "<<last<<"\n";
      if ((first==n/2) && (last==0)){
        if (checkReverse(k)){
          ans=k;
          break;
        }
      }
      //now update, and move k along
      if (X[k+1]<Y[k+1]) first--;
      if (X[k+n/2+1]<Y[k+n/2+1]) first++;
      if (X[k+n+1-n/2]<Y[k+n+1-n/2]) last--;
      if (X[k+n+1]<Y[k+n+1]) last++;
      k++;
    }
    fout<<"Case #"<<z<<": "<<ans<<"\n";
  }
}