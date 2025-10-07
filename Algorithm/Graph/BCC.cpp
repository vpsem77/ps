const int NMAX = 10005;
int v, e, dcnt, dfsn[NMAX], vis[NMAX];
vector<int> adj[NMAX];
stack<pair<int,int>> S;
vector<vector<pair<int,int>>> bcc;

int dfs(int cur, int par = -1){
    int res = dfsn[cur] = ++dcnt;
    for(int nxt : adj[cur]){
        if(nxt == par) continue;
        if(dfsn[cur] > dfsn[nxt]) S.push({cur, nxt});
        if(dfsn[nxt] > 0) res = min(res, dfsn[nxt]);
        else{
            int tmp = dfs(nxt, cur);
            res = min(res, tmp);
            if(tmp >= dfsn[cur]){
                vector<pair<int,int>> curbcc;
                while(!S.empty() && S.top() != make_pair(cur, nxt)){
                    curbcc.push_back(S.top());
                    S.pop();
                }
                curbcc.push_back(S.top());
                S.pop();
                bcc.push_back(curbcc);
            }
        }
    }
    return res;
}

for(int i = 0; i < v; i++){
    if(dfsn[i] == 0) dfs(i);
}
