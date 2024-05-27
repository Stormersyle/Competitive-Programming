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

//Paste the following code to import indexed_set
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//end paste

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    indexed_set s;
    for (int x=1; x<=6; x++) s.insert(x);
    s.erase(5);
    s.erase(7);
    cout<<s.size()<<" size\n";
    for (int x: s) cout<<x<<" ";
    cout<<"\n\n";

    auto it=s.find_by_order(3);
    cout<<"s[3] "<<*it<<"\n";
    it=s.find_by_order(7);
    if (it==s.end()) cout<<"if can't find element, s.find_by_order(x) returns s.end()\n";
    auto it1=s.find(5);
    if (it1==s.end()) cout<<"s.find(x) still works\n";
    cout<<"order(3) "<<s.order_of_key(3)<<"\n";
    cout<<"order(8) "<<s.order_of_key(8)<<"\n\n";

    int first=*s.begin();
    cout<<first<<"\nif that was 1, indexed_set.begin() works\n\n";

    auto it2=s.upper_bound(4);
    cout<<*it2<<" value corresponding to upper_bound(4)\n";
    auto it3=s.lower_bound(4);
    cout<<*it3<<" value corresponding to lower_bound(4)\n";

    s.clear();
    if (s.size()==0) cout<<"s.clear() works too";
}
