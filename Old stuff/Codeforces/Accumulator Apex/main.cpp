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

deque<ll> lists[100001];
ll A;
int k;
set<tuple<ll, ll, int, int>> fpp_set; //(trough, sum, index, list_number)

tuple<ll, ll, int, int> fpp(int L){ //first positive prefix of list L; return (trough, sum, index, list_number)
    ll s=0, m=0;
    for (int i=0; i<lists[L].size(); i++){
        s+=lists[L][i], m=min(m, s);
        if (s>0) return make_tuple(m, s, i, L);
    }
    return make_tuple(-1, -1, -1, -1);
}

void remove_prefix(int L, int i){ //remove prefix 0-->i from list L
    for (int j=0; j<=i; j++) lists[L].pop_front();
}

void solve(){
    for (int i=1; i<=k; i++){
        tuple<ll, ll, int, int> t=fpp(i);
        if (get<3>(t)!=-1) fpp_set.insert(t);
    }
    while (fpp_set.size()>0){
        auto it=fpp_set.end();
        it--;
        tuple<ll, ll, int, int> t=*it;
        if (get<0>(t)<-A) return;
        fpp_set.erase(it);
        remove_prefix(get<3>(t), get<2>(t));
        A+=get<1>(t);
        tuple<ll, ll, int, int> t1=fpp(get<3>(t));
        if (get<3>(t1)!=-1) fpp_set.insert(t1);
    }
}

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    cin>>A>>k;
    for (int i=1; i<=k; i++){
        int sz; ll num;
        cin>>sz;
        for (int j=1; j<=sz; j++) cin>>num, lists[i].push_back(num);
    }
    solve();
    cout<<A;
}
