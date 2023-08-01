vector<ll> dijkstra(vector<vector<vector<ll>>> g, ll n, ll start=1){
    /*
    (1-indexed) O((V+E)logV)
    g: グラフ [[[cost, node], [cost, node]], ...]
    n: ノード数
    start: スタートするノード
    */
    vector<ll> dist(n+1, inf);
    dist[start] = 0;
    vector<bool> used(n+1, 0);
    used[start] = 1;
    spq(q, vector<ll>);
    vrep(x, g[start]) q.push(x);
    while (!q.empty()){
        ll c = q.top()[0];
        ll v = q.top()[1];
        q.pop();
        if (used[v]) continue;
        dist[v] = c;
        used[v] = 1;
        vrep(x, g[v]){
            if (!used[x[1]]) q.push({x[0]+dist[v], x[1]});
        }
    }
    return dist;
}