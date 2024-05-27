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

int s[200001][20], s1[200001][20]; //maxN=1e6, then maxK=19
int lg2[1000001]; //precomputed log floors
int n, a[200001], b[200001];

void setupLog(){
  lg2[1]=0;
  for (int x=2; x<=200000; x++) lg2[x]=lg2[x/2]+1;
}

void setup(){ //set up sparse table
  for (int i=1; i<=n; i++) s[i][0]=b[i];
  for (int k=1; k<=lg2[n]; k++){
    for (int i=1; i<=n; i++){
      int tk=1<<k;
      if (i+tk-1<=n) s[i][k]=min(s[i][k-1], s[i+tk/2][k-1]);
    }
  }

  for (int i=1; i<=n; i++) s1[i][0]=a[i];
  for (int k=1; k<=lg2[n]; k++){
    for (int i=1; i<=n; i++){
      int tk=1<<k;
      if (i+tk-1<=n) s1[i][k]=max(s1[i][k-1], s1[i+tk/2][k-1]);
    }
  }
}

int min_range_b(int L, int R){ //range min query; modify for range max query
  int j=lg2[R-L+1];
  int tj=1<<j;
  int m1=s[L][j], m2=s[R-(tj-1)][j];
  return min(m1, m2);
}

int max_range_a(int L, int R){
  int j=lg2[R-L+1];
  int tj=1<<j;
  int m1=s1[L][j], m2=s1[R-(tj-1)][j];
  return max(m1, m2);
}


int prevx[200001], nextx[200001], previndex[200001]; //prevx[i]=last index of b[i] in a, before i

bool solve(){
    setup();
    for (int i=1; i<=n; i++){
        if (a[i]>b[i]) return false;
    } //so a[i]<=b[i] for all i
    for (int x=1; x<=n; x++) previndex[x]=-1;
    for (int i=1; i<=n; i++) previndex[a[i]]=i, prevx[i]=previndex[b[i]];
    for (int x=1; x<=n; x++) previndex[x]=n+1;
    for (int i=n; i>=1; i--) previndex[a[i]]=i, nextx[i]=previndex[b[i]];
    for (int i=1; i<=n; i++){
        if (a[i]<b[i]){
            int j=prevx[i], k=nextx[i], x=b[i];
            bool check=false;
            if ((j>=1)&&(max_range_a(j+1, i)<x)&&(min_range_b(j+1, i)>=x)) check=true;
            if ((k<=n)&&(max_range_a(i, k-1)<x)&&(min_range_b(i, k-1)>=x)) check=true;
            if (!check) return false;
        }
    }
    return true;
}

int main(){
    setupLog();
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        cin>>n;
        for (int i=1; i<=n; i++) cin>>a[i];
        for (int i=1; i<=n; i++) cin>>b[i];
        if (solve()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
