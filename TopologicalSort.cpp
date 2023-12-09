// 1-indexed
ll n;
vector<ll> l;
vector<vector<ll>> g;
// vector<bool> seen(n+1);
void dfs(ll v){
    if (!seen[v]){
        seen[v] = true;
        vrep(x, g[v]){
            dfs(x);
        }
        l.pb(v);
    }
}
// m: 頂点数
vector<ll> topological_sort(ll m){
    rep(i, 1, m+1) dfs(i);
    rev(l);
    return l;
}