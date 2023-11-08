struct BIT {
    vector<ll> dat;
    /* [1, n] */
    BIT(ll n) : dat(n+1, 0) {}
    void init(ll n) { dat.assign(n+1, 0); }
    /* a is 1-indexed */
    inline void add(ll a, ll x) {
        for (ll i=a; i<(ll)dat.size(); i+=i & -i)
            dat[i] = dat[i] + x;
    }
    /* [1, a], a is 1-indexed */
    inline ll sum(ll a) {
        ll res = 0;
        for (ll i=a; i>0; i-=i & -i)
            res = res + dat[i];
        return res;
    }
    /* [a, b), a and b are 1-indexed */
    inline ll sum(ll a, ll b) {
        return sum(b-1) - sum(a-1);
    }
};