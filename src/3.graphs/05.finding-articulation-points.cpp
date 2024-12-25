int n;                    // number of nodes
vector<vector<int>> adj;  // adjacency list of graph

vector<bool> visited;
vector<int> inTime, lowTime;
int timer;

void processCutpoint(int v) {
    // problem-specific logic goes here
    // it can be called multiple times for the same v
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    inTime[v] = lowTime[v] = timer++;
    int children = 0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            lowTime[v] = min(lowTime[v], inTime[to]);
        } else {
            dfs(to, v);
            lowTime[v] = min(lowTime[v], lowTime[to]);
            if (lowTime[to] >= inTime[v] && p != -1) processCutpoint(v);
            ++children;
        }
    }
    if (p == -1 && children > 1) processCutpoint(v);
}

void findCutpoints() {
    timer = 0;
    visited.assign(n, false);
    inTime.assign(n, -1);
    lowTime.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) dfs(i);
    }
}