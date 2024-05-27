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

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        int n;
        cin>>n;
        ll a[n+1], b[n+1], M[n+1], m[n+1]; //M=max array, m=min array
        for (int i=1; i<=n; i++) cin>>a[i];
        for (int i=1; i<=n; i++) cin>>b[i];
        for (int i=1; i<=n; i++) M[i]=max(a[i], b[i]), m[i]=min(a[i], b[i]);

        //case 1: sum of 2 disjoint subarrays in max array
        ll pre[n+1], suf[n+2];
        pre[0]=0, suf[n+1]=0;
        for (int i=1; i<=n; i++) pre[i]=pre[i-1]+M[i];
        for (int i=n; i>=1; i--) suf[i]=suf[i+1]+M[i];
        ll max_before[n+1], max_after[n+2]; //max subarray sum ending at <=i, and starting at >=i
        ll min_pre, min_suf;
        max_before[0]=0, min_pre=0;
        for (int i=1; i<=n; i++){
            min_pre=min(min_pre, pre[i]);
            max_before[i]=max(max_before[i-1], pre[i]-min_pre);
        }
        max_after[n+1]=0, min_suf=0;
        for (int i=n; i>=1; i--){
            min_suf=min(min_suf, suf[i]);
            max_after[i]=max(max_after[i+1], suf[i]-min_suf);
        }
        ll T1=0;
        for (int i=0; i<=n; i++) T1=max(T1, max_before[i]+max_after[i+1]);

        //case 2: subarrays overlap; sum of interval in max array + sub-interval in min array
        //again: iterate through middle point
        ll leftsum_max[n+1], rightsum_max[n+2]; //best sum in max array at <=i / >=i (but ending at i)
        ll leftsum_min[n+1], rightsum_min[n+2];
        leftsum_max[0]=0, leftsum_min[0]=0, rightsum_max[n+1]=0, rightsum_min[n+1]=0;
        min_pre=0, min_suf=0;
        for (int i=1; i<=n; i++) min_pre=min(min_pre, pre[i]), leftsum_max[i]=pre[i]-min_pre;
        for (int i=n; i>=1; i--) min_suf=min(min_suf, suf[i]), rightsum_max[i]=suf[i]-min_suf;
        for (int i=1; i<=n; i++) pre[i]=pre[i-1]+m[i]; //redefine prefix/suffix sums for min array
        for (int i=n; i>=1; i--) suf[i]=suf[i+1]+m[i];
        min_pre=0, min_suf=0;
        for (int i=1; i<=n; i++) min_pre=min(min_pre, pre[i]), leftsum_min[i]=pre[i]-min_pre;
        for (int i=n; i>=1; i--) min_suf=min(min_suf, suf[i]), rightsum_min[i]=suf[i]-min_suf;
        ll T2=0;
        for (int i=0; i<=n; i++) T2=max(T2, leftsum_max[i]+leftsum_min[i]+rightsum_max[i+1]+rightsum_min[i+1]);

        cout<<max(T1, T2)<<"\n";
    }
}
