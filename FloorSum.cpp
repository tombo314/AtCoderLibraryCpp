ll floor_sum(ll n, ll m, ll a, ll b){
    ll ans = 0;
    while (true){
        if (a>=m){
            ans += n*(n-1)*(a/m)/2;
            a %= m;
        }
        if (b>=m){
            ans += n*(b/m);
            b %= m;
        }

        ll y_max = a*n+b;
        if (y_max<m){
            break;
        }
        tie(n, b, m, a) = make_tuple(y_max/m, y_max%m, a, m);
    }
    return ans;
}