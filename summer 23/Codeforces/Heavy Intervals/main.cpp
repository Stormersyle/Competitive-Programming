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

int state[200001]; //+1 means start, -1 means end

int main(){
    for (int x=1; x<=200000; x++) state[x]=0;
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        int n;
        cin>>n;
        int L[n+1], R[n+1], c[n];
        for (int i=1; i<=n; i++) cin>>L[i], state[L[i]]=1;
        for (int i=1; i<=n; i++) cin>>R[i], state[R[i]]=-1;
        for (int i=0; i<n; i++) cin>>c[i];
        vector<int> points;
        for (int i=1; i<=n; i++) points.push_back(L[i]), points.push_back(R[i]);
        sort(points.begin(), points.end());
        vector<int> starts;
        vector<pair<int, int>> segments;
        for (int p: points){
            if (state[p]==1) starts.push_back(p);
            if (state[p]==-1) segments.push_back({starts.back(), p}), starts.pop_back();
        }
        for (int p: points) state[p]=0; //reset

        vector<int> lengths;
        for (pair<int, int> s: segments) lengths.push_back(s.second-s.first);
        sort(lengths.begin(), lengths.end());
        sort(c, c+n);
        ll T=0;
        for (int i=0; i<n; i++) T+=(ll)(c[i])*(ll)(lengths[n-1-i]);
        cout<<T<<"\n";
    }
}
