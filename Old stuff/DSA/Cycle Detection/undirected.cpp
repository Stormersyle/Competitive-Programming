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

//cycle detection for undirected graphs

int n, m; //note: 0-indexed in library checker
vector<int> adj[500000];
int processed[500000]; //0=unprocessed, 1=processing, 2=processed
vector<int> path, cycle; //path=current path in DFS; can view it as a stack
bool found_cycle;

map<pair<int, int>, int> edge_id; //just for library checker
bool edge_repeat=false;
pair<int, int> double_edge;

void dfs(int x, int parent){ //assume unvisited
    processed[x]=1, path.push_back(x);
    for (int y: adj[x]){
        if (processed[y]==0) dfs(y, x);
        else if ((processed[y]==1)&&(y!=parent)){
            found_cycle=true;
            vector<int> slice(find(path.begin(), path.end(), y), path.end());
            cycle=slice;
        }
        if (found_cycle) return;
    }
    processed[x]=2, path.pop_back();
}

void find_cycle(){
    if (found_cycle) return;
    found_cycle=false;
    for (int x=0; x<n; x++) processed[x]=0;
    for (int x=0; x<n; x++){
        if (processed[x]==0) dfs(x, -1);
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
        cin>>a>>b, adj[a].push_back(b), adj[b].push_back(a);
        if (edge_id.count({a, b})>0){
            edge_repeat=true, found_cycle=true;
            double_edge={edge_id[{a, b}], i}, cycle={a, b};
        }
        edge_id[{a, b}]=i, edge_id[{b, a}]=i;
    }
    find_cycle();
    if (found_cycle && edge_repeat){
        cout<<"2\n"<<cycle[0]<<" "<<cycle[1]<<"\n"<<double_edge.first<<" "<<double_edge.second<<"\n";
    }
    else if (found_cycle){
        cout<<cycle.size()<<"\n";
        for (int x: cycle) cout<<x<<" ";
        cout<<"\n";
        for (int i=0; i<=(int)(cycle.size())-2; i++) cout<<edge_id[{cycle[i], cycle[i+1]}]<<" ";
        cout<<edge_id[{cycle.back(), cycle[0]}]<<"\n";
    }
    else cout<<"-1\n";
}
