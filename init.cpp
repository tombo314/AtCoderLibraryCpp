#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, b) for (ll i=a; i<b; i++)
#define rrep(i, a, b) for (ll i=a; i>b; i--)
#define vrep(x, v) for (auto x: v)
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.begin(), v.end(), greater<ll>())
#define copy(v1, v2) copy(v1.begin(), v1.end(), v2.begin())
#define pb push_back
#define inf ll(1e18)
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