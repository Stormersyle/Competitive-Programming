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

int n, M[1001][1001], a[1001];

// vector<int> bits(int x){ //returns array of bits, from left to right
//     vector<int> b;
//     for (int i=0; i<=29; i++) b.push_back(x%2), x/=2;
//     reverse(b.begin(), b.end());
//     return b;
// }

// void make_arr(){
//     // for (int i=1; i<=n; i++){
//     //     // int one[30];
//     //     // for (int b=0; b<=29; b++) one[b]=1;
//     //     a[i]=(1<<30)-1;
//     //     for (int j=1; j<=n; j++){ //make guaranteed 0s; rest 1s
//     //         if (j!=i){
//     //             // vector<int> bitsij=bits(M[i][j]);
//     //             // for (int b=0; b<=29; b++){
//     //             //     if (bitsij[b]==0) one[b]=0;
//     //             // }
//     //             a[i]&=M[i][j];
//     //         }
//     //     }
//     //     // a[i]=0;
//     //     // for (int b=0; b<=29; b++) a[i]+=one[b]*(1<<(29-b));
//     // }
//     for(int i = 1;i <=n;i++){
//         a[i] = (1<<30) - 1;
//     }
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= n;j++){
//             if(i != j){
//                 a[i] &= M[i][j];
//                 a[j] &= M[i][j];
//             }
//         }
//     }
// }

// bool check(){
//     // for (int i=1; i<=n; i++){
//     //     for (int j=i+1; j<=n; j++){
//     //         if ((a[i]|a[j])!=M[i][j]) return false;
//     //     }
//     // }
//     // return true;
//     bool ok = true;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= n;j++){
//             if(i != j && (a[i] | a[j]) != M[i][j]){
//                 ok = false;
//             }
//         }
//     }
//     return ok;
// }

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for (int z=0; z<t; z++){
        cin>>n;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++) cin>>M[i][j];
        }
        for(int i = 1;i <=n;i++){
            a[i] = (1<<30) - 1;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(i != j){
                    a[i] &= M[i][j];
                    a[j] &= M[i][j];
                }
            }
        }
        bool ok = true;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(i != j && (a[i] | a[j]) != M[i][j]){
                    ok = false;
                }
            }
        }
        if (ok){
            cout<<"YES\n";
            for (int i=1; i<=n; i++) cout<<a[i]<<" ";
            cout<<"\n";
        }
        else cout<<"NO\n";
    }
}
