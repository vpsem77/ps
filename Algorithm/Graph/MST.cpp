const int NMAX = 100005
int n, m;
tuple<int, int, int> adj[NMAX];
int par[NMAX];
int find(int x) {
    if (par[x] == -1) return x;
    return par[x] = find(par[x]);
}
void merge(int x, int y) {
    int u = find(x), v = find(y);
    if (u == v) return;
    par[v] = u;
}

memset(par, -1, sizeof(par));
cin >> n >> m;
for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[i] = {c, a, b};
}

sort(adj, adj + m);
ll res = 0;
for (int i = 0; i < m; i++) {
    int a, b, cost;
    tie(cost, a, b) = adj[i];
    if (find(a) != find(b)) {
        res += cost;
        merge(a, b);
    }
}
