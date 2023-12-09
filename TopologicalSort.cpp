// 1-indexed
// n: 頂点数
// g: 隣接リスト
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
        l.push_back(v);
    }
}
vector<ll> topological_sort(){
    rep(i, 1, n+1) dfs(i);
    rev(l);
    return l;
}