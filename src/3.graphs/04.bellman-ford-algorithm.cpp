struct Edge {
    int a, b, cost;
};

int n, m, v;
vector<Edge> e;

// To find a negative cycle: perform one more relaxation step.
// If anything changes - a negative cycle exists.
void solve() {
    vector<int> d(n, INT_MAX);
    d[v] = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < m; ++j)
            if (d[e[j].a] < INT_MAX)
                d[e[j].b] = min(d[e[j].b], d[e[j].a] + e[j].cost);
}