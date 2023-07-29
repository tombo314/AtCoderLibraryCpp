ll mergecount(vector<ll> a){
    /*
    転倒数 O(nlogn)
    */
    ll cnt = 0;
    ll n = a.size();
    if (n>1){
        vector<ll> a1;
        vector<ll> a2;
        rep(i, n>>1){
            a1.pb(a[i]);
        }
        rep(i, n){
            if (i<(n>>1)) continue;
            a2.pb(a[i]);
        }
        cnt += mergecount(a1);
        cnt += mergecount(a2);
        ll i1 = 0;
        ll i2 = 0;
        rep(i, n){
            if (i2==a2.size()){
                a[i] = a1[i1];
                i1++;
            } else if (i1==a1.size()){
                a[i] = a2[i2];
                i2++;
            } else if (a1[i1]<=a2[i2]){
                a[i] = a1[i1];
                i1++;
            } else {
                a[i] = a2[i2];
                i2++;
                cnt += n/2-i1;
            }
        }
    }
    return cnt;
}