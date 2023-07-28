vector<vector<ll>> _mat_mul(vector<vector<ll>> a, vector<vector<ll>> b, ll m){
    ll p = a.size(), q = b[0].size(), r = b.size();
    vector<vector<ll>> c(p, vector<ll>(q));
    rep(i, p){
        rep(j, q){
            rep(k, r){
                c[i][j] += a[i][k]*b[k][j];
                c[i][j] %= m;
            }
        }
    }
    return c;
}

vector<vector<ll>> mat_pow(vector<vector<ll>> x, ll n, ll m=998244353){
    /*
    行列累乗 O(logn)
    x: 行列
    n: 指数
    m: mod
    */
    vector<vector<ll>> y(x.size(), vector<ll>(x.size()));
    rep(i, x.size()) y[i][i] = 1;
    while(n){
        if (n&1) y = _mat_mul(x, y, m);
        x = _mat_mul(x, x, m);
        n >>= 1;
    }
    return y;
}