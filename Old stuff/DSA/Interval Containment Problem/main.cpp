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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag,
tree_order_statistics_node_update> indexed_multiset;

int main(){
    // ifstream cin("test_input.txt");
    // ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y;
    cin>>n;
    vector<pair<int, int>> ranges0, ranges;
    for (int i=0; i<n; i++) cin>>x>>y, ranges0.push_back({x, y}), ranges.push_back({x, -y});
    sort(ranges.begin(), ranges.end()); //sort first by increasing start, then by decreasing end
    for (int i=0; i<n; i++) ranges[i].second*=(-1);

    map<pair<int, int>, int> contains; //how many ranges each range contains
    indexed_multiset ends; //indexed multiset of ends so far
    for (int i=n-1; i>=0; i--){
        int start=ranges[i].first, end=ranges[i].second;
        ends.insert({end, n-i});
        contains[ranges[i]]=ends.order_of_key({end, n-i});
    }

    map<pair<int, int>, int> contained_in; //how many ranges each range is contained in
    indexed_multiset ends1;
    for (int i=0; i<n; i++){
        int start=ranges[i].first, end=ranges[i].second;
        contained_in[ranges[i]]=i-ends1.order_of_key({end, -1});
        ends1.insert({end, i});
    }

    for (pair<int, int> r: ranges0) cout<<contains[r]<<" ";
    cout<<"\n";
    for (pair<int, int> r: ranges0) cout<<contained_in[r]<<" ";
    // cout<<"\n";
    // for (pair<int, int> r: ranges) cout<<r.first<<" "<<r.second<<" | ";
}
