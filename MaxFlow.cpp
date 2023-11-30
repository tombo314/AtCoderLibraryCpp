struct Edge {
	ll to, cap, rev;
};

// 1-indexed
class MaxFlow {
public:
	ll size_ = 0;
    vector<bool> used;
    vector<vector<Edge>> G;

    MaxFlow(ll N){
        size_ = N;
        used.resize(N+1);
        G.resize(N+1);
    }

	// 頂点 a から b に向かう、上限 c リットル／秒の辺を追加
	void add_edge(ll a, ll b, ll c) {
		ll Current_Ga = G[a].size(); // 現時点での G[a] の要素数
		ll Current_Gb = G[b].size(); // 現時点での G[b] の要素数
		G[a].push_back(Edge{ b, c, Current_Gb });
		G[b].push_back(Edge{ a, 0, Current_Ga });
	}

	// 深さ優先探索（F はスタートから pos に到達する過程での " 残余グラフの辺の容量 " の最小値）
	// 返り値は流したフローの量（流せない場合は 0 を返す）
	ll dfs(ll pos, ll goal, ll F) {
		// ゴールに到着：フローを流せる！
		if (pos == goal) return F;
		used[pos] = true;

		// 探索する
		for (ll i = 0; i < G[pos].size(); i++) {
			// 容量 0 の辺は使えない
			if (G[pos][i].cap == 0) continue;

			// 既に訪問した頂点に行っても意味がない
			if (used[G[pos][i].to] == true) continue;

			// 目的地までのパスを探す
			ll flow = dfs(G[pos][i].to, goal, min(F, G[pos][i].cap));

			// フローを流せる場合、残余グラフの容量を flow だけ増減させる
			if (flow >= 1) {
				G[pos][i].cap -= flow;
				G[G[pos][i].to][G[pos][i].rev].cap += flow;
				return flow;
			}
		}

		// すべての辺を探索しても見つからなかった ･･･
		return 0;
	}

	// 頂点 s から頂点 t までの最大フローの総流量を返す
	ll max_flow(ll s, ll t) {
		ll Total_Flow = 0;
		while (true) {
			for (ll i = 0; i <= size_; i++) used[i] = false;
			ll F = dfs(s, t, 1000000000);

			// フローを流せなくなったら操作終了
			if (F == 0) break;
			Total_Flow += F;
		}
		return Total_Flow;
	}
};