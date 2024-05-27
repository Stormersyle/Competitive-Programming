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

int main() {
  ifstream cin("here_comes_santa_claus_validation_input (1).txt");
  ofstream fout("output.txt");
  fout<<fixed<<setprecision(1);
  ios_base::sync_with_stdio(false); 
  cin.tie(0);
  int t;
  cin>>t;
  for (int z=0; z<t; z++){
    int n;
    cin>>n;
    int x[n+1];
    for (int i=1; i<=n; i++) cin>>x[i];
    sort(x+1, x+n+1);
    double d;
    if (n!=5) d=(x[n]+x[n-1]-x[1]-x[2])*0.5;
    else d=min((x[5]+x[3]-x[2]-x[1])*0.5, (x[5]+x[4]-x[3]-x[1])*0.5);
    double intpart;
    if (modf(d, &intpart) == 0.0) fout<<(int)(d)<<"\n";
    else fout<<d<<"\n";
  }
}