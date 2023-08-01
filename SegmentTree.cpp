class SegTree{
public:
    ll n;
    ll ide;
    ll num;
    vector<ll> tree;
    function<ll(ll, ll)> func;

    SegTree(vector<ll> init_val, function<ll(ll, ll)> segfunc, ll ide_ele){
        /*
        init_val: vector
        segfunc: 区間への演算
        ide_ele: 単位元
        */
        n = init_val.size();
        ide = ide_ele;
        func = segfunc;
        ll bit_len = 0;
        while ((n-1)>>bit_len) bit_len++;
        num = 1 << bit_len;
        tree.resize(2*num, ide);
        rep(i, 0, n){
            tree[num+i] = init_val[i];
        }
        rrep(i, num-1, 0){
            tree[i] = func(tree[2*i], tree[2*i+1]);
        }
    }

    void update(ll k, ll x){
        /*
        k番目の値をxに更新
        k: index(0-indexed)
        x: update value
        */
        k += num;
        tree[k] = x;
        while (k>1){
            tree[k>>1] = func(tree[k], tree[k^1]);
            k >>= 1;
        }
    }

    ll query(ll l, ll r){
        /*
        [l, r)のsegfuncしたものを得る
        l: index(0-indexed)
        r: index(0-indexed)
        */
        ll res = ide;
        l += num;
        r += num;
        while (l<r){
            if (l&1){
                res = func(res, tree[l]);
                l++;
            }
            if (r&1){
                res = func(res, tree[r-1]);
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }

    ll get(ll k){
        /*
        k番目の値を得る
        k: index(0-indexed)
        */
        return query(k, k+1);
    }
};