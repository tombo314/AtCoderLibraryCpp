vector<vector<ll>> factorization(ll n){
    /*
    素因数分解 O(√n)
    [[素因数, 指数], ...]
    */
    vector<vector<ll>> ret;
    ll tmp = n;
    rep(i, ll(sqrt(n)+1)){
        if (i<=1) continue;
        if (tmp%i==0){
            ll cnt = 0;
            while (tmp%i==0){
                cnt++;
                tmp /= i;
            }
            ret.pb({i, cnt});
        }
    }
    if (tmp!=1) ret.pb({tmp, 1});
    if (ret.empty()) ret.pb({n, 1});
    return ret;
}