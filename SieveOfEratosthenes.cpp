vector<ll> sieve_of_eratosthenes(ll n){
    /*
    n 以下の素数を列挙する
    O(nloglogn)
    */
    vector<bool> prime(n+1, 1);
    prime[0] = 0;
    prime[1] = 0;

    ll sqrt_n = sqrt(n)+1;
    rep(i, 2, sqrt_n){
        if (prime[i]){
            ll j = 2*i;
            while(j<n+1){
                prime[j] = 0;
                j += i;
            }
        }
    }
    vector<ll> ret;
    rep(i, 0, n+1){
        if (prime[i]) ret.pb(i);
    }
    return ret;
}