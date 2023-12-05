// G, N, start=1
// 1-indexed
struct BFS {
    
    queue<ll> q;
    vector<ll> dist, trace;

    BFS(vector<vector<ll>> G, ll N, ll start=1){
        dist.resize(N+1, inf);
        trace.resize(N+1, start);
        dist[start] = 0;
        q.push(start);
        while (q.size()){
            ll n = q.front();
            q.pop();
            vrep(v, G[n]){
                if (dist[v]!=inf) continue;
                dist[v] = dist[n]+1;
                trace[v] = n;
                q.push(v);
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
        tr.push_back(now);
        rev(tr);
        return tr;
    }
};