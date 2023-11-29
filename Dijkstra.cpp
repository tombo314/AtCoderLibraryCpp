/*
(1-indexed) O((V+E)logV)
g: グラフ [[[cost, node], [cost, node]], ...]
n: ノード数
start: スタートするノード (start=1)
*/
struct Dijkstra {

    ll n;
    vector<vector<pair<ll, ll>>> g;
    vector<ll> dist, trace;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> q;

    Dijkstra(vector<vector<pair<ll, ll>>> g_, ll n_, ll start=1){
        g = g_;
        n = n_;
        dist.resize(n+1, inf);
        trace.resize(n+1);
        dist[start] = 0;
        vrep(x, g[start]) q.push({x.first, start, x.second});
    }

    void run(){
        while (!q.empty()){
            ll c, pre, v;
            tie(c, pre, v) = q.top();
            q.pop();
            if (dist[v]!=inf) continue;
            dist[v] = c;
            trace[v] = pre;
            vrep(x, g[v]){
                if (dist[x.second]==inf){
                    q.push({x.first+dist[v], v, x.second});
                }
            }
        }
    }

    vector<ll> get_dist(){
        return dist;
    }

    vector<ll> get_trace(){
        vector<ll> tr;
        ll now = n;
        while (now!=0){
            tr.push_back(now);
            now = trace[now];
        }
        rev(tr);
        return tr;
    }
};