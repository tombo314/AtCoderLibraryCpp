bool is_prime(ll n){
    /*
    nが素数なら1、そうでないなら0を返す
    O(√n)
    */
    if (n<=1) return false;
    ll i = 2;
    while (i*i<=n){
        if (n%i==0) return false;
        i++;
    }
    return true;
}