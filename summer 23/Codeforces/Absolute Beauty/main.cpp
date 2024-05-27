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

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        int n;
        cin>>n;
        int a[n], b[n];
        for (int i=0; i<n; i++) cin>>a[i];
        for (int i=0; i<n; i++) cin>>b[i];
        vector<pair<int, int>> segs; //pairs of (start, end)
        for (int i=0; i<n; i++) segs.push_back({min(a[i], b[i]), max(a[i], b[i])});
        ll T=0;
        for (pair<int, int> seg: segs) T+=(ll)(seg.second-seg.first);
        int maxStart=segs[0].first, minEnd=segs[0].second;
        for (pair<int, int> seg: segs) maxStart=max(maxStart, seg.first), minEnd=min(minEnd, seg.second);
        if (maxStart>minEnd) T+=(ll)(2*(maxStart-minEnd));
        cout<<T<<"\n";
    }
}
