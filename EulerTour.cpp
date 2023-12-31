// 0-indexed
vector<ll> euler_tour(vector<vector<ll>> g, ll root=0){
    ll n = g.size();
    vector<ll> euler;
    vector<ll> q1 = {root};
    vector<ll> q2;
    vector<ll> visited(n, false);
    while (!q1.empty()){
        ll u = q1[q1.size()-1];
        q1.pop_back();
        euler.push_back(u);
        if (visited[u]) continue;
        vrep(x, g[u]) {
            if (visited[x]){
                q1.push_back(x);
            }
            else{
                q2.push_back(x);
            }
        }
        q1.insert(q1.end(), q2.begin(), q2.end());
        q2.clear();
        visited[u] = true;
    }
    return euler;
}