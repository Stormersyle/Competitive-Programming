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

int n, m, k;
int right_seg[17][17], down_seg[17][17]; //right_seg[x][y]=right segment from point (x, y)
map<int, char> color={{0, 'R'}, {1, 'B'}};

bool solve(){
    if (k<n+m-2) return false;
    if ((k-n-m)%2!=0) return false;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++) right_seg[i][j]=-1, down_seg[i][j]=-1;
    }
    if ((k%4)==((n+m-2)%4)){ //R=0, B=1
        right_seg[1][1]=0, down_seg[1][2]=1, right_seg[2][1]=0, down_seg[1][1]=1;
        for (int j=2; j<=m-1; j++) right_seg[1][j]=1-right_seg[1][j-1];
        down_seg[1][m]=1-right_seg[1][m-1];
        for (int i=2; i<=n-1; i++) down_seg[i][m]=1-down_seg[i-1][m];
    }
    else{
        right_seg[1][1]=0, down_seg[1][2]=1, right_seg[2][1]=0, down_seg[2][1]=1, right_seg[3][1]=0, down_seg[2][2]=1;
        for (int j=2; j<=m-1; j++) right_seg[3][j]=1-right_seg[3][j-1];
        down_seg[3][m]=1-right_seg[3][m-1];
        for (int i=4; i<=n-1; i++) down_seg[i][m]=1-down_seg[i-1][m];
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (right_seg[i][j]==-1) right_seg[i][j]=0;
            if (down_seg[i][j]==-1) down_seg[i][j]=0;
        }
    }
    return true;
}

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        cin>>n>>m>>k;
        if (solve()){
            cout<<"YES\n";
            for (int i=1; i<=n; i++){
                for (int j=1; j<=m-1; j++) cout<<color[right_seg[i][j]]<<" ";
                cout<<"\n";
            }
            for (int i=1; i<=n-1; i++){
                for (int j=1; j<=m; j++) cout<<color[down_seg[i][j]]<<" ";
                cout<<"\n";
            }
        }
        else cout<<"NO\n";
    }
}
