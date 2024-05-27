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

int n, a[200001], num[2][200001]; //num[x][i]=number of Xs from a(1-->i)
ll c[2][2][200001], f[2][2][200001], E=998244353;

ll solve(){
    num[0][0]=0, num[1][0]=0;
    for (int i=1; i<=n; i++) num[1][i]=num[1][i-1]+a[i], num[0][i]=i-num[1][i];
    //make c
    for (int x=0; x<=1; x++){
        for (int y=0; y<=1; y++) c[x][y][0]=0, c[x][y][1]=0;
    }
    for (int x=0; x<=1; x++){
        for (int y=0; y<=1; y++){
            for (int k=2; k<=n; k++){
                if (a[k]==y) c[x][y][k]=(c[x][y][k-1]+(ll)(num[x][k-1]))%E;
                else c[x][y][k]=c[x][y][k-1];
            }
        }
    }
    //make f
    for (int x=0; x<=1; x++){
        for (int y=0; y<=1; y++) f[x][y][0]=0, f[x][y][1]=0, f[x][y][2]=0;
    }
    for (int k=3; k<=n; k++){
        for (int x=0; x<=1; x++){
            for (int y=0; y<=1; y++){
                int z=(x+y)%2;
                if (a[k]==y) f[x][y][k]=(f[x][y][k-1]+f[z][x][k-1]+c[z][x][k-1])%E;
                else f[x][y][k]=f[x][y][k-1];
            }
        }
    }
    return ((f[0][0][n]+f[0][1][n]+f[1][0][n]+f[1][1][n])%E);
}

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n; i++) a[i]=(a[i]%2);
    cout<<solve();
}
