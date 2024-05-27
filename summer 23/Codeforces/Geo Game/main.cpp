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

unordered_set<int> ind_set[2]; //ind_set[x]=set of indexes of points with parity x

int parity(pair<int, int> p){
    return (((p.first+p.second)%2)+2)%2;
}

void remove_index(int j){
    ind_set[0].erase(j), ind_set[1].erase(j);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int z=0; z<t; z++){
    int n;
    scanf("%d", &n);
    int xs, ys; //start at (xs, ys)
    scanf("%d", &xs), scanf("%d", &ys);
    pair<int, int> points[n+1];
    for (int i=1; i<=n; i++){
        int x, y;
        scanf("%d", &x), scanf("%d", &y);
        points[i]={x, y};
    }
    ind_set[0].clear(), ind_set[1].clear();
    int p1_parity=parity({xs, ys}), p2_parity=1-parity({xs, ys}); //parity of last point for p1/p2 to win
    for (int i=1; i<=n; i++) ind_set[parity(points[i])].insert(i);

    int winning_parity, player;
    if (ind_set[p1_parity].size()>=ind_set[p2_parity].size()) winning_parity=p1_parity, player=1;
    else winning_parity=p2_parity, player=2;
    int bad_parity=1-winning_parity;

    if (player==1) printf("First\n"), fflush(stdout);
    else printf("Second\n"), fflush(stdout);
    int j;
    if (player==2) scanf("%d", &j), remove_index(j);
    while ((ind_set[0].size()>0)||(ind_set[1].size()>0)){
        int i;
        if (ind_set[bad_parity].size()>0) i=*ind_set[bad_parity].begin();
        else i=*ind_set[winning_parity].begin();
        printf("%d\n", i), fflush(stdout);
        remove_index(i);
        // for (int x: ind_set[0]) printf("(%d 0) ", x);
        // for (int x: ind_set[1]) printf("(%d 1) ", x);
        // printf("\n"), fflush(stdout);
        if ((ind_set[0].size()==0)&&(ind_set[1].size()==0)) break;
        scanf("%d", &j), remove_index(j);
    }
  }
}
