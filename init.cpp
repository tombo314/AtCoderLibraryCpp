#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i=0; i<n; i++)
#define rrep(i, n) for (ll i=n-1; i>=0; i--)
#define vrep(v, a) for (auto v: a)
using namespace std;

ll pow_(ll x, ll n, ll mod=1e18){
    ll ret = 1;
    while (n>0){
        if (n&1){
            ret = ret*x%mod;
        }
        x = x*x%mod;
        n >>= 1;
    }
    return ret;
}

int main(){
    
}