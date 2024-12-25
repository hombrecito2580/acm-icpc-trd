int n;                    // number of nodes
vector<vector<int>> adj;  // adjacency list of graph

vector<bool> visited;
vector<int> inTime, lowTime;
int timer;

void processBridge(int u, int v) {
    // do something with the found bridge
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    inTime[v] = lowTime[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;;
        if (visited[to]) {
            lowTime[v] = min(lowTime[v], inTime[to]);
        } else {
            dfs(to, v);
            lowTime[v] = min(lowTime[v], lowTime[to]);
            if (lowTime[to] > inTime[v]) processBridge(v, to);
        }
    }
}

// Doesn't work with multiple edges
// But multiple edges are never bridges, so it's easy to check
void findBridges() {
    timer = 0;
    visited.assign(n, false);
    inTime.assign(n, -1);
    lowTime.assign(n, -1);
    bridges.clear();
    FOR(i, 0, n) {
        if (!visited[i]) dfs(i);
    }
}