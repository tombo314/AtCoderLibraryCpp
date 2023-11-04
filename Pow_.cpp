ll pow_(ll x, ll n, ll mod=9e18){
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