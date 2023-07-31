vector<vector<ll>> warshall_floyd(ll n, vector<vector<ll>> dist){
    /*
    n: 頂点数
    dist: 頂点間のコストが入った2次元vector(infで初期化)
    1-indexed
    */
    rep(k, 1, n+1){
        rep(i, 1, n+1){
            rep(j, 1, n+1){
                dist[i][j] = min({dist[i][j], dist[i][k]+dist[k][j]});
            }
        }
    }
    return dist;
}