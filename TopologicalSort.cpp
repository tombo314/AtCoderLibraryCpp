// 1-indexed
// N: 頂点数
// G: 隣接リスト
class TopologicalSort {
    ll N;
    vector<vector<ll>> G;
    vector<ll> l;
    vector<bool> seen;
public:
    TopologicalSort(ll N_, vector<vector<ll>> G_){
        N = N_;
        G = G_;
    }

    void dfs(ll v){
        if (!seen[v]){
            seen[v] = true;
            vrep(x, G[v]){
                dfs(x);
            }
            l.push_back(v);
        }
    }

    vector<ll> run(){
        rep(i, 1, N+1) dfs(i);
        rev(l);
        return l;
    }
};