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

    vector<ll> get_trace(ll start, ll goal){

        if (start==goal){
            return {};
        }

        vector<ll> tr;
        ll now = goal;
        while (now!=start){
            tr.push_back(now);
            now = trace[now];
        }
        tr.push_back(start);

        rev(tr);
        return tr;
    }
};