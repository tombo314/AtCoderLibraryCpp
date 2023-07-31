ll n;
vector<ll> l;
vector<vector<ll>> g;
vector<bool> seen(n+1);
void dfs(ll v){
    if (!seen[v]){
        seen[v] = 1;
        vrep(x, g[v]){
            dfs(x);
        }
        l.pb(v);
    }
}
vector<ll> topological_sort(vector<vector<ll>> g, ll m){
    /*
    g: グラフ
    m: 頂点数
    */
    n =  m;
    rep(i, 1, n+1) dfs(i);
    rev(l);
    return l;
}