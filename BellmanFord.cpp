vector<ll> bellman_ford(vector<vector<ll>> g, ll n, ll start = 0){
    /*
    ベルマンフォード法 O(VE) (0-indexed)
    g: グラフ [[始点, 終点, コスト], ...]
    n: 頂点数
    start: 開始する頂点
    */
    vector<ll> dist(n, inf);
    dist[start] = 0;
    rep(i, 0, n){
        bool update = 0;
        vrep(v, g){
            ll x,y,c;
            x = v[0];
            y = v[1];
            c = v[2];
            if (dist[y]>dist[x]+c){
                dist[y] = dist[x]+c;
                update = 1;
            }
        }
        if (!update) break;
        if (i==n-1) { return {-1}; }
    }
    return dist;
}