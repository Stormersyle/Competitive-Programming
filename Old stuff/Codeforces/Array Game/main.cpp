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

int n, k;
vector<ll> nums;

ll solve(){
    if (k>=3) return 0;
    sort(nums.begin(), nums.end());
    ll mindiff=nums[1]-nums[0], min_num=*min_element(nums.begin(), nums.end());
    for (int i=0; i<=nums.size()-2; i++) mindiff=min(mindiff, nums[i+1]-nums[i]);
    if (k==1) return min(mindiff, min_num);
    ll m=min(mindiff, min_num);
    set<ll> diffs;
    for (int i=0; i<nums.size(); i++){
        for (int j=i+1; j<nums.size(); j++) diffs.insert(nums[j]-nums[i]);
    }
    for (ll diff: diffs){
        auto it0=upper_bound(nums.begin(), nums.end(), diff);
        if (it0!=nums.begin()) it0--, m=min(m, diff-*it0);
        auto it1=lower_bound(nums.begin(), nums.end(), diff);
        if (it1!=nums.end()) m=min(m, *it1-diff);
    }
    return m;
}

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        cin>>n>>k;
        nums.clear();
        for (int i=1; i<=n; i++){
            ll x;
            cin>>x, nums.push_back(x);
        }
        cout<<solve()<<"\n";
    }
}
