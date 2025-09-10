const int NMAX = 3005;

vector<int> adj[NMAX];

ll n, m, A[NMAX], B[NMAX];
bool vis[NMAX];

bool dfs(int cur){
    vis[cur] = true;
    for(int nxt : adj[cur]){
        if(B[nxt] == -1 || (!vis[B[nxt]] && dfs(B[nxt]))){
            A[cur] = nxt;
            B[nxt] = cur;
            return true; 
        }
    }
    return false;
}

memset(A, -1, sizeof(A));
memset(B, -1, sizeof(B));
ll res = 0;
for(int i = 1; i <= 2 * n; i++){
    if(A[i] == -1){
        memset(vis, 0, sizeof(vis));
        if(dfs(i)) res++;
    }
}
cout << res;
