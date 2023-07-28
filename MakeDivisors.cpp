vector<ll> make_divisors(ll n){
    /*
    約数を列挙する
    O(√n)
    */
    vector<ll> lower_divisors;
    vector<ll> upper_divisors;
    ll i = 1;
    while (i*i<=n){
        if (n%i==0){
            lower_divisors.pb(i);
            if (i!=n/i) upper_divisors.pb(n/i);
        }
        i++;
    }
    reverse(upper_divisors.begin(), upper_divisors.end());
    lower_divisors.insert(lower_divisors.end(), upper_divisors.begin(), upper_divisors.end());
    return lower_divisors;
}