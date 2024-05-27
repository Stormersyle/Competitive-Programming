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

int n;
string s[1000001], r[1000001], prefix_s[1000001], prefix_r[1000001];
vector<int> length_ge_s[1000001], length_ge_r[1000001]; //length_ge[k]=list of all indexes of str with len>=k
map<string, vector<int>> prefix_s_map[1000001], prefix_r_map[1000001];

void make_lenth_ge(){
    for (int i=1; i<=n; i++) length_ge_s[0].push_back(i), length_ge_r[0].push_back(i);
    for (int k=1; k<=1000000; k++){
        for (int i: length_ge_s[k-1]){
            if (s[i].length()>=k) length_ge_s[k].push_back(i);
        }
        for (int i: length_ge_r[k-1]){
            if (r[i].length()>=k) length_ge_r[k].push_back(i);
        }
    }
}

void update_prefix_maps(int k){
    for (int i: length_ge_s[k]) prefix_s[i]+=s[i][k];
    for (pair<string, vector<int>> p: prefix_s_map){
        map<char,
    }
    for (int i: length_ge_s[k]){
        if (prefix_s_map[k].count(prefix_s[i])==0) prefix_s_map[k][prefix_s[i]]={i};
        else
    }
}

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    cin>>n;
    for (int i=1; i<=n; i++) cin>>s[i];
    for (int i=1; i<=n; i++) r[i]=string(s[i].rbegin(), s[i].rend());

}
