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

//cycle detection for directed graphs
//validation: https://judge.yosupo.jp/problem/cycle_detection

int n, m; //note: 0-indexed in library checker
vector<int> out[500000];
int processed[500000]; //0=unprocessed, 1=processing, 2=processed
vector<int> path, cycle; //path=current path in DFS; can view it as a stack
bool found_cycle;

map<pair<int, int>, int> edge_id; //just for library checker

void dfs(int x){
    if (found_cycle) return; //if found cycle: done with everything
    if (processed[x]==2) return;
    if (processed[x]==1){
        found_cycle=true;
        // int ix=find(path.begin(), path.end(), x)-path.begin();
        // for (int i=ix; i<path.size(); i++) cycle.push_back(path[i]);
        vector<int> slice(find(path.begin(), path.end(), x), path.end()); //both these ways work
        cycle=slice;
        return;
    }
    processed[x]=1, path.push_back(x);
    for (int y: out[x]) dfs(y);
    processed[x]=2, path.pop_back();
}

void find_cycle(){
    found_cycle=false;
    for (int x=0; x<n; x++) processed[x]=0;
    for (int x=0; x<n; x++){
        if (processed[x]==0) dfs(x);
    }
}


int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i=0; i<m; i++){
        int a, b;
        cin>>a>>b, out[a].push_back(b), edge_id[{a, b}]=i;
    }
    find_cycle();
    if (found_cycle){
        cout<<cycle.size()<<"\n";
        for (int i=0; i<=cycle.size()-2; i++) cout<<edge_id[{cycle[i], cycle[i+1]}]<<"\n";
        cout<<edge_id[{cycle.back(), cycle[0]}]<<"\n";
    }
    else cout<<"-1\n";
}
