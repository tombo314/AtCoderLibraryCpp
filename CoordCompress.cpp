vector<ll> coord_compress(vector<ll> l){
    /* 座標圧縮 O(len(l)) */
    vector<ll> l2(l.size());
    copy(l, l2);
    srt(l2);
    map<ll, ll> rank;
    rep(i, l2.size()) rank[l2[i]] = i;
    vector<ll> compressed;
    vrep(x, l) compressed.pb(rank[x]);
    return compressed;
}