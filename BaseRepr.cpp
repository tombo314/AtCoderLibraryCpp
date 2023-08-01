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

string base_repr(ll n, ll base){
    /*
    10進数のnをbase進数に変換する
    O(logn)
    */
    ll exp = 0;
    while (pow_(base, exp)<n) exp++;
    string ret;
    while (exp>=0){
        ll m = n/pow_(base, exp);
        ret += to_string(m);
        n -= m*pow_(base, exp);
        exp--;
    }
    return ret;
}