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
//use indexed set:
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

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
        int a[n+1];
        for (int i=1; i<=n; i++) cin>>a[i];
        vector<int> s={-1}; //list of bad VALUES
        for (int i=1; i<=n; i++){
            if (a[i]!=i) s.push_back(a[i]);
        }
        int k=s.size()-1; //# of bad values
        int ind[n+1], path_length[k+1];
        for (int i=1; i<=k; i++) ind[s[i]]=i; //ind[x]=index of x in unsorted list of bad values
        sort(s.begin(), s.end());
        for (int i=1; i<=k; i++) path_length[i]=(i-ind[s[i]]+k)%k;

        //now, reduces to interval containment problem
        vector<pair<int, int>> ranges; //each interval: i-->s[i]
        for (int i=1; i<=k; i++){
            if (ind[s[i]]<i) ranges.push_back({ind[s[i]], i}), ranges.push_back({k+ind[s[i]], k+i});
            else ranges.push_back({ind[s[i]], k+i});
        }
        sort(ranges.begin(), ranges.end()); //all start/end points distinct
        map<pair<int, int>, int> contains;
        indexed_set ends;
        for (int i=ranges.size()-1; i>=0; i--){
            int start=ranges[i].first, end=ranges[i].second;
            ends.insert(end);
            contains[ranges[i]]=ends.order_of_key(end);
        }

        int total_steps[n+1];
        for (int i=1; i<=n; i++) total_steps[i]=0;
        for (int i=1; i<=k; i++){
            if (ind[s[i]]<i) total_steps[s[i]]=path_length[i]-contains[{ind[s[i]], i}];
            else total_steps[s[i]]=path_length[i]-contains[{ind[s[i]], i+k}];
        }
        for (int i=1; i<=n; i++) cout<<total_steps[i]<<" ";
        cout<<"\n";

        // cout<<k<<" k\n";
        // for (int i=1; i<=k; i++) cout<<s[i]<<" ";
        // cout<<"s\n";
        // for (pair<int, int> r: ranges) cout<<r.first<<" "<<r.second<<" | "<<contains[r]<<"\n";
    }
}
