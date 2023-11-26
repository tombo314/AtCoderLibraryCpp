// indexとvalueはどちらも0-indexed
struct Doubling {

    vector<vector<ll>> dp;

    Doubling(vector<ll> A){
        ll N = A.size();
        dp.resize(61);
        rep(i, 0, 61){
            dp[i].resize(N);
        }
        rep(i, 0, N){
            dp[0][i] = A[i];
        }
        rep(i, 1, 61){
            rep(j, 0, N){
                dp[i][j] = dp[i-1][dp[i-1][j]];
            }
        }
    }

    ll get(ll now, ll move_num){
        ll n = now;
        rrep(i, 60, -1){
            if ((move_num/(1LL<<i))%2!=0) n = dp[i][n];
        }
        return n;
    }
};