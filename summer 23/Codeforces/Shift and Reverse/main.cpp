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

int min_Rs(){
    int f=n+1;
    for (int i=1; i<=n-1; i++){
        if (a[i]>a[i+1]){
            f=i;
            break;
        }
    }
    if (f==n+1) return 0;
    for (int i=f+1; i<=f+n-1; i++){
        if (a[i]>a[i+1]) return n+1;
    }
    return min(n-f, f+2); //Rshift by n-f; or Lshift by f, and +2 Is
}

int min_RsI(){
    int f=n+1;
    for (int i=1; i<=n-1; i++){
        if (a[i]<a[i+1]){
            f=i;
            break;
        }
    }
    if (f==n+1) return 1; //if all equal: min_Rs will take care of it
    for (int i=f+1; i<=f+n-1; i++){
        if (a[i]<a[i+1]) return n+1;
    }
    return min(n-f, f)+1;
}


int main(){
    ifstream cin("x_input.txt");
    ofstream cout("x_output.txt");
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        cin>>n;
        for (int i=1; i<=n; i++) cin>>a[i];
        for (int i=n+1; i<=2*n; i++) a[i]=a[i-n];
        int min_moves=min(min_Rs(), min_RsI());
        if (min_moves==n+1) cout<<"-1\n";
        else cout<<min_moves<<"\n";
    }
}
