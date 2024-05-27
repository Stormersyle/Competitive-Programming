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

map<int, vector<int>> minPartition; //minPartition[x]=min size partition of 41 that makes product x

vector<vector<int>> S[42][42][42]; //S[x][k][a]=set of sorted partitions of x with size k, last element a
vector<vector<int>> partitions;

void make_partitions(int n){
  S[1][1][1].push_back({1});
  for (int x=2; x<=n; x++){
    S[x][1][x].push_back({x});
    for (int k=2; k<=x; k++){
      for (int a=1; a<=x-1; a++){
        //compute S[x][k][a]
        for (int L=1; L<=a; L++){
          for (vector<int> part: S[x-a][k-1][L]){
            vector<int> newPart=part;
            newPart.push_back(a), S[x][k][a].push_back(newPart);
          }
        }
        //end computation of S[x][k][a]
      }
    }
  }
  for (int k=1; k<=n; k++){ //partitions are sorted by size
    for (int a=1; a<=n; a++){
      for (vector<int> part: S[n][k][a]) partitions.push_back(part);
    }
  }
  return;
}

void precompute(){
  for (vector<int> part: partitions){
    int P=1;
    for (int x: part) P*=x;
    if (minPartition.count(P)==0) minPartition[P]=part;
  }
}

int main() {
  make_partitions(41);
  precompute();
  ifstream cin("sum_41_chapter_1_input.txt");
  ofstream fout("output.txt");
  ios_base::sync_with_stdio(false); 
  cin.tie(0);
  int t;
  cin>>t;
  for (int z=1; z<=t; z++){
    int P;
    cin>>P;
    fout<<"Case #"<<z<<": ";
    if (minPartition.count(P)==0) fout<<"-1\n";
    else{
      fout<<minPartition[P].size()<<" ";
      for (int x: minPartition[P]) fout<<x<<" ";
      fout<<"\n";
    }
  }
}