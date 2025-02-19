const int k = 19;

vector<ll> tree[100005], h(100005);
vector<vector<ll>> sps(k, vector<ll>(100005));

void dfs(ll cur, ll par) {
    for (auto nxt : tree[cur]) {
        if (nxt == par) continue;
        h[nxt] = h[cur] + 1;
        sps[0][nxt] = cur;
        dfs(nxt, cur);
    }
}

ll lca(ll u, ll v) {
    if (h[u] > h[v]) swap(u, v);
    ll d = h[v] - h[u];
    if (d > 0) {
        for (int i = k - 1; i >= 0; i--) {
            if (d >= (1 << i)) {
                v = sps[i][v];
                d -= (1 << i);
            }
        }
    }
    if(u == v) return u;

    for(int i = k - 1; i >= 0; i--){
        if(sps[i][u] != sps[i][v]){
            u = sps[i][u];
            v = sps[i][v];
        }
    }

    return sps[0][u];   
}

 dfs(1, 0);
  for (int j = 1; j < k; j++) {
      for (int i = 1; i <= n; i++) {
          sps[j][i] = sps[j - 1][sps[j - 1][i]];
      }
  }
