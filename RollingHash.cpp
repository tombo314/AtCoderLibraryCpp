/*
S: 文字列
b: 基底
m: mod
*/
class RollingHash{
public:
    vector<ll> prefix;
    vector<ll> power;
    ll n;
    ll base;
    ll mod;

    RollingHash(string S, ll b=3491, ll m=998244353){
        n = S.size();
        base = b;
        mod = m;
        prefix.resize(n+1);
        power.resize(n+1, 1);
        rep(i, 0, n){
            ll c = S[i];
            prefix[i+1] = (prefix[i]*base+c)%mod;
            power[i+1] = (power[i]*base)%mod;
        }
    }

    /*
    S[l, r)のハッシュを求める
    */
    ll get(ll l, ll r){
        return (prefix[r]-power[r-l]*prefix[l])%mod;
    }

    /*
    つなげる文字列をS1、自身の連続する部分文字列をS2として、
    S1+S2のハッシュを求める
    h1: S1のハッシュ
    h2: S2のハッシュ
    l2: S2の長さ
    */
    ll concat(ll h1, ll h2, ll l2){
        return (power[l2]*h1+h2)%mod;
    }

    /*
    S[l1, r1)とS[l2, r2)の最大共通接頭辞を求める
    */
    ll lcp(ll l1, ll r1, ll l2, ll r2){
        ll low = 0;
        ll high = min({r1-l1, r2-l2})+1;
        while (high-low>1){
            ll mid = (high+low)/2;
            if (get(l1, l1+mid)==get(l2, l2+mid)) low = mid;
            else high = mid;
        }
        return low;
    }
};