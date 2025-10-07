// lazy segment tree
// 구간합 기준 구현

const int b = 1 << 18;
ll seg[b * 2], lazy[b * 2];

void upd_lazy(int ix, int l, int r){
    if(!lazy[ix]) return;
    seg[ix] += lazy[ix] * (r - l + 1);
    if(l != r){
        lazy[ix * 2] += lazy[ix];
        lazy[ix * 2 + 1] += lazy[ix];
    }
    lazy[ix] = 0;
    return;
}

void upd(int ix, int s, int e, int l, int r, ll v){
    upd_lazy(ix, s, e);
    if(s > r || e < l) return;
    if(s >= l && e <= r){
        lazy[ix] += v;
        upd_lazy(ix, s, e);
        return;
    }
    int m = (s + e) / 2;
    upd(ix * 2, s, m, l, r, v);
    upd(ix * 2 + 1, m + 1, e, l, r, v);
    // modify here
    seg[ix] = seg[ix * 2] + seg[ix * 2 + 1];
    return;
}

ll qry(int ix, int s, int e, int l, int r){
    upd_lazy(ix, s, e);
    // 더미값 return
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return seg[ix];
    int m = (s + e) / 2;
    // modify here
    return qry(ix * 2, s, m, l, r) + qry(ix * 2 + 1, m + 1, e, l, r);
}
