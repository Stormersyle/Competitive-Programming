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

int n, a[100001], sum[100001]; //sum[x]=current sum at x (mod 2)
int out[100001], val[100001]; //val[x]=value of outedge from x
vector<int> inedges[100001];
bool visited[100001];
int processed[100001]; //0=unprocessed, 1=processing, 2=processed
vector<int> ring_reps, ring_nodes, switches; //switch i corresponds to outedge i

void dfs(int x){ //assume unvisited
    if (processed[x]==2) return;
    if (processed[x]==1){
        ring_reps.push_back(x);
        return;
    }
    processed[x]=1;
    dfs(out[x]);
    processed[x]=2;
}

void dfs_back(int x){
    if (visited[x]) return;
    visited[x]=true;
    for (int y: inedges[x]) dfs_back(y);
    val[x]=sum[x], sum[x]=0, sum[out[x]]=(sum[out[x]]+val[x])%2;
    if (val[x]==1) switches.push_back(x);
}

int solve(){
    switches.clear(), ring_reps.clear(), ring_nodes.clear();
    for (int x=1; x<=n; x++) processed[x]=0;
    for (int x=1; x<=n; x++){
        if (processed[x]==0) dfs(x);
    }
    for (int x: ring_reps){
        int y=x;
        do ring_nodes.push_back(y), y=out[y];
        while (y!=x);
    }

    for (int x=1; x<=n; x++) visited[x]=false;
    for (int x: ring_nodes) visited[x]=true;
    for (int x: ring_nodes){
        for (int y: inedges[x]) dfs_back(y);
    }
    for (int x: ring_nodes) visited[x]=false;
    for (int x: ring_reps){
        int y=x;
        vector<pair<int, int>> val_list;
        while (!visited[y]){
            visited[y]=true, val[y]=sum[y], sum[y]=0, sum[out[y]]=(sum[out[y]]+val[y])%2;
            val_list.push_back({val[y], y}), y=out[y];
        }
        if (sum[x]==1) return -1;
        int sum_vals=0, incl;
        for (pair<int, int> p: val_list) sum_vals+=p.first;
        if (sum_vals<=(int)(val_list.size()-sum_vals)) incl=1;
        else incl=0;
        for (pair<int, int> p: val_list){
            if (p.first==incl) switches.push_back(p.second);
        }
    }
    return 1;
}

int main(){
    ifstream cin("x_input.txt");
    ofstream cout("x_output.txt");
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        string s;
        cin>>n>>s;
        for (int i=1; i<=n; i++) a[i]=(int)(s[i-1]-'0'); //a[i]=value of node i
        for (int i=1; i<=n; i++) cin>>out[i];
        for (int x=1; x<=n; x++) inedges[x].clear(), sum[x]=a[x];
        for (int x=1; x<=n; x++) inedges[out[x]].push_back(x);
        int result=solve();
        if (result==-1) cout<<"-1\n";
        else{
            cout<<switches.size()<<"\n";
            for (int x: switches) cout<<x<<" ";
            cout<<"\n";
        }
    }
}
