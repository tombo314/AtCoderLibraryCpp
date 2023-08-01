class UnionFind {
public:
    ll n;
    vector<ll> par;
    vector<ll> siz;

    UnionFind(ll k){
        /*
        UnionFind (1-indexed)
        k: 頂点数
        */
        n = k;
        par.resize(n+1, -1);
        siz.resize(n+1, 1);
    }

    ll find(ll x){
        while (par[x]!=-1) x = par[x];
        return x;
    }

    void unite(ll u, ll v){
        ll ru = find(u);
        ll rv = find(v);
        if (ru==rv) { return; }
        
        if (siz[ru]<siz[rv]){
            par[ru] = rv;
            siz[rv] += siz[ru];
        }
        else {
            par[rv] = ru;
            siz[ru] += siz[rv];
        }
    }

    bool same(ll u, ll v){
        if (find(u)==find(v)) {return 1;}
        return 0;
    }

    ll get_size(ll u){ return siz[find(u)]; }
};