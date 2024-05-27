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

ll reverse(ll x){ //return reversed number (given positive number)
    if (x==0) return 0;
    if (x<0) return -reverse(-x);
    vector<ll> digits;
    ll x1=x;
    while (x1>0) digits.push_back(x1%10), x1/=10;
    reverse(digits.begin(), digits.end());
    ll pow10=1, R=0;
    for (int i=0; i<digits.size(); i++) R+=(pow10*digits[i]), pow10*=10;
    return R;
}

string F(ll p, ll q){ //second part ("F") of expression for (p, q)
    cout<<p<<" "<<q<<" "<<reverse(p)<<" "<<q-reverse(p)<<"\n";
    if (q-reverse(p)>=0){
        ll r=reverse(q-reverse(p));
        string rstr=to_string(r);
        cout<<r<<"\n";
        return "0*"+rstr+"-5*"+rstr+"+5*"+rstr+"+3*7*"+rstr+"-21*"+rstr;
    }
    else{
        ll s=reverse(reverse(p)-q);
        string sstr=to_string(s);
        // cout<<s<<"\n";
        return "0*"+sstr+"-4*"+sstr+"+4*"+sstr+"+3*7*"+sstr+"-21*"+sstr;
    }
}

string E(ll p, ll q){ //return expression for (p, q)
    if (p==0) return F(0, q);
    if (p%10==0){
        if (p>0) return "0-1-0+"+E(p+1, q+1);
        else return "1+"+E(p-1, q-1);
    }
    if ((q-reverse(p))%10==0){
        if (p>0) return "0-1-0+"+E(p+1, q+1);
        else return "1+"+E(p-1, q-1);
    }
    if (p<0) return "0-"+to_string(abs(p))+"-0+"+F(p, q);
    return to_string(p)+"+"+F(p, q);
}

int main(){
    ifstream cin("test_input.txt");
    ofstream cout("test_output.txt");
    ll p, q;
    cin>>p>>q;
    cout<<E(p, q);
}
