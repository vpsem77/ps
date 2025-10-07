const int NMAX = 1005;

vector<int> adj[NMAX];
int c[NMAX][NMAX], f[NMAX][NMAX];

int res = 0, s = 0, e = n + m + 2;
while(true){
    int pre[NMAX];
    fill(pre, pre + NMAX, -1);
    queue<int> q;
    q.push(s);
    while(!q.empty() && pre[e] == -1){
        int cur = q.front();
        q.pop();
        for(int nxt : adj[cur]){
            if(c[cur][nxt] - f[cur][nxt] > 0 && pre[nxt] == -1){
                q.push(nxt);
                pre[nxt] = cur;
                if(nxt == e) break;
            }
        }
    }
    if(pre[e] == -1) break;

    int flow = INF;
    for(int i = e; i != s; i = pre[i]){
        flow = min(flow, c[pre[i]][i] - f[pre[i]][i]);
    }
    for(int i = e; i != s; i = pre[i]){
        f[pre[i]][i] += flow;
        f[i][pre[i]] -= flow;
    }
    res += flow;
}
cout << res;
