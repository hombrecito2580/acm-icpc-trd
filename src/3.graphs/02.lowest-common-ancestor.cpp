int timer;
vector<vector<int>> adj;
vector<int> tin, tout;

void dfs(int v, int p) {
    tin[v] = ++timer;

    for (int u : adj[v]) {
        if (u != p) dfs(u, v);
    }

    tout[v] = ++timer;
}

bool isAncestor(int u, int v) { 
    return tin[u] <= tin[v] && tout[v] <= tout[u]; 
}