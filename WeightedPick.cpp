ll weighted_pick(vector<ll> v) {
    ll total_weight = 0;
    ll pick = 0;
    
    // トータルの重みを計算する
    for(ll i=0; i<v.size(); i++) {
        total_weight += v[i];
    }
    
    // 抽選する
    ll rnd = rand(0, total_weight);
    
    for(ll i=0; i<v.size(); i++) {
        if(rnd<v[i]) {
            // 抽選対象決定
            pick = i;
            break;
        }
        
        // 次の対象を調べる
        rnd -= v[i];
    }
    
    return pick;
}