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

int n, a[1001], b[1001];
int prevx[1001], nextx[1001], previndex[1001]; //prevx[i]=last index of b[i] in a, before i

int min_range(int i, int j, char c){
    if (c=='a') return *min_element(a+i, a+j+1);
    if (c=='b') return *min_element(b+i, b+j+1);
    return -1;
}

int max_range(int i, int j, char c){
    if (c=='a') return *max_element(a+i, a+j+1);
    if (c=='b') return *max_element(b+i, b+j+1);
    return -1;
}


bool solve(){
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
            if ((j>=1)&&(max_range(j+1, i, 'a')<x)&&(min_range(j+1, i, 'b')>=x)) check=true;
            if ((k<=n)&&(max_range(i, k-1, 'a')<x)&&(min_range(i, k-1, 'b')>=x)) check=true;
            if (!check) return false;
        }
    }
    return true;
}

int main(){
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
