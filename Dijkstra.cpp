vector<ll> dijkstra(vector<vector<vector<ll>>> g, ll n, ll start=1){
    /*
    (1-indexed) O((V+E)logV)
    g: グラフ [[[cost, node], [cost, node]], ...]
    n: ノード数
    start: スタートするノード
    */
    vector<ll> dist(n+1, inf);
    dist[start] = 0;
    vector<bool> used(n+1, false);
    used[start] = true;
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q;
    vrep(x, g[start]) q.push(x);
    while (!q.empty()){
        ll c = q.top()[0];
        ll v = q.top()[1];
        cout << c << " " << v << endl;
        q.pop();
        if (used[v]) continue;
        dist[v] = c;
        used[v] = true;
        vrep(x, g[v]){
            if (!used[x[1]]) q.push({x[0]+dist[v], x[1]});
        }
    }
    return dist;
}