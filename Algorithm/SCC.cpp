const int MAX = 10005;
int v, e, cnt, sn[MAX], SN, dfsn[MAX];
vector<int> adj[MAX];
bool finished[MAX];
stack<int> S;
vector<vector<int>> SCC;

int dfs(int cur){
    dfsn[cur] = ++cnt;
    S.push(cur);

    int res = dfsn[cur];
    for(int nxt : adj[cur]){
        if(dfsn[nxt] == 0) res = min(res, dfs(nxt));
        else if(!finished[nxt]) res = min(res, dfsn[nxt]);
    }

    if(res == dfsn[cur]){
        vector<int> cSCC;
        while(true){
            int t = S.top();
            S.pop();
            cSCC.push_back(t);
            finished[t] = true;
            sn[t] = SN;
            if(t == cur) break;
        }
        SCC.push_back(cSCC);
        SN++;
    }
    return res;
}

for(int i=0; i<V; i++)
    if(dfsn[i] == 0) dfs(i);
