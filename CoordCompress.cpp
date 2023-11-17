// 座標圧縮 O(len(l))
vector<ll> coord_compress(vector<ll> l){
    set<ll> s;
    vrep(x, l) s.insert(x);
    map<ll, ll> rank;
    ll i = 0;
    vrep(x, s){ rank[x] = i; i++; }
    vector<ll> compressed;
    vrep(x, l) compressed.pb(rank[x]);
    return compressed;
}