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

int n, a[100001];
vector<int> mult_list[100001]; //mult_list[x]=list of of indexes of multiples of x; in increaseing order
ll T[100001]; //T[x]=number of triples with val=x

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        cin>>n;
        for (int i=1; i<=n; i++) cin>>a[i];
        sort(a+1, a+n+1);
        int A=*max_element(a+1, a+n+1);
        for (int x=1; x<=A; x++) mult_list[x].clear();
        for (int i=1; i<=n; i++){ //make mult_list
            vector<int> factors;
            for (int x=1; x*x<=a[i]; x++){
                if (a[i]%x==0) factors.push_back(x), factors.push_back(a[i]/x);
                if (x*x==a[i]) factors.pop_back();
            }
            for (int x: factors) mult_list[x].push_back(i);
        }
        for (int x=A; x>=1; x--){
            T[x]=0; //next: cases on midddle element
            for (int j=1; j<mult_list[x].size(); j++) T[x]+=(ll)(j)*(ll)(n-mult_list[x][j]);
            for (int y=2*x; y<=A; y+=x) T[x]-=T[y];
        }
        // for (int x=1; x<=A; x++) cout<<x<<" "<<T[x]<<"\n";
        ll S=0;
        for (int x=1; x<=A; x++) S+=(ll)(T[x])*(ll)(x);
        cout<<S<<"\n";
    }
}
