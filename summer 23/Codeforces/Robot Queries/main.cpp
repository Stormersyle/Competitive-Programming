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

int n, q;
string s0;
char s[200001];
map<char, pair<int, int>> dir={{'U', make_pair(0, 1)}, {'D', make_pair(0, -1)}, {'R', make_pair(1, 0)}, {'L', make_pair(-1, 0)}};
pair<int, int> pre[200001], suf[200002]; //prefix and suffix sums
map<pair<int, int>, vector<int>> inPref, inSuf; //inPref[c]= list of all prefix sums = c; in ascending order

pair<int, int> sum(pair<int, int> p1, pair<int, int> p2){
    return {p1.first+p2.first, p1.second+p2.second};
}

pair<int, int> subtract(pair<int, int> p1, pair<int, int> p2){
    return {p1.first-p2.first, p1.second-p2.second};
}

bool checkSuf(pair<int, int> x, int L, int R){ //check if x is in a suffix sum in [L, R]
    auto it=lower_bound(inSuf[x].begin(), inSuf[x].end(), L);
    if (it==inSuf[x].end()) return false;
    return ((*it)<=R);
}

bool checkPref(pair<int, int> x, int L, int R){ //check if x is in a prefix sum in [L, R]
    if (L==0) return ((inPref[x].size()>0)&&(inPref[x][0]<=R));
    if (R==n) return ((inPref[x].size()>0)&&(inPref[x].back()>=L));
    auto it=lower_bound(inPref[x].begin(), inPref[x].end(), L);
    if (it==inPref[x].end()) return false;
    return ((*it)<=R);
}

bool check(int x, int y, int L, int R){
    pair<int, int> c={x, y};
    if (checkPref(c, 0, L-1)) return true;
    if (checkPref(c, R+1, n)) return true;
    pair<int, int> c1=sum(subtract(c, pre[L-1]), suf[R+1]);
    return checkSuf(c1, L, R);
}

void setup(){
    pre[0]={0, 0};
    for (int i=1; i<=n; i++) pre[i]=sum(pre[i-1], dir[s[i]]);
    suf[n+1]={0, 0};
    for (int i=n; i>=1; i--) suf[i]=sum(suf[i+1], dir[s[i]]);
    for (int i=0; i<=n; i++){
        if (inPref.count(pre[i])==0) inPref[pre[i]]={i};
        else inPref[pre[i]].push_back(i);
    }
    for (int i=1; i<=n+1; i++){
        if (inSuf.count(suf[i])==0) inSuf[suf[i]]={i};
        else inSuf[suf[i]].push_back(i);
    }
}


int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    cin>>n>>q>>s0;
    for (int i=1; i<=n; i++) s[i]=s0[i-1];
    setup();
    // for (auto x: dir) cout<<x.first<<"->"<<x.second.first<<" "<<x.second.second<<"\n";
    for (int z=0; z<q; z++){
        int x, y, L, R;
        cin>>x>>y>>L>>R;
        if (check(x, y, L, R)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
