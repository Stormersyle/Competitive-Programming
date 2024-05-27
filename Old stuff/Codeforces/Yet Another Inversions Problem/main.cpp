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
//indexed set
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int p[200001], q[200001], n, k;
ll E=998244353;

ll count_inversions(vector<int> v){ //count inversions in a list of distinct elements
    if (v.size()==0) return 0;
    ll T=0;
    indexed_set prev_values;
    for (int x: v) T+=(ll)(prev_values.size()-prev_values.order_of_key(x)), prev_values.insert(x);
    return T%E;
}

ll count(int d){
    indexed_set prev_values;
    ll T=0;
    if (d>=0){
        for (int j=0; j<=n-1; j++){
            if ((1<<d)<=(2*n-1)/p[j]) T+=(ll)(j-prev_values.order_of_key(p[j]*(1<<d)+1));
            prev_values.insert(p[j]);
        }
    }
    else{
        for (int i=n-1; i>=0; i--){
            if ((1<<(-d))>(2*n-1)/p[i]) T+=(ll)(prev_values.size());
            else T+=(ll)(prev_values.order_of_key(p[i]*(1<<(-d))));
            prev_values.insert(p[i]);
        }
    }
    return T%E;
}

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        cin>>n>>k;
        vector<int> q1;
        for (int i=0; i<n; i++) cin>>p[i];
        for (int i=0; i<k; i++) cin>>q[i], q1.push_back(q[i]);
        ll same_row=(ll)(n)*(ll)(count_inversions(q1));
        map<int, int> diff_count, inv_count;
        for (int a=0; a<=k-1; a++) diff_count[a]=k-a, diff_count[-a]=k-a;
        for (int d=0; d<=k-1; d++) inv_count[d]=0;
        for (int d=0; d>=-(k-1); d--) inv_count[d]=((ll)(n)*(ll)(n-1))/2;
        for (int d=0; (1<<d)<=2*n-1; d++) inv_count[d]=count(d);
        for (int d=0; (1<<(-d))<=2*n-1; d--) inv_count[d]=count(d);
        ll T=same_row;
        for (int d=(-k-1); d<=k-1; d++) T=(T+(ll)(diff_count[d])*(ll)(inv_count[d]))%E;
        cout<<T<<"\n";
    }
}
