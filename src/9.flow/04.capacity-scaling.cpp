// TC: O(E^2 logCm)

class CapacityScalingSolver : public NetworkFlowSolverBase {
private:
    long long delta;

    long long dfs(int node, long long flow) {
        if (node == t) return flow;
        visit(node);
        for (Edge* edge : graph[node]) {
            long long cap = edge->remainingCapacity();
            if (cap >= delta && !visited(edge->to)) {
                long long bottleNeck = dfs(edge->to, min(flow, cap));
                if (bottleNeck > 0) {
                    edge->augment(bottleNeck);
                    return bottleNeck;
                }
            }
        }
        return 0;
    }

public:
    CapacityScalingSolver(int n, int s, int t) : NetworkFlowSolverBase(n, s, t), delta(0) {}

    void solve() override {
        delta = 1;
        while (delta <= INF) delta <<= 1;
        delta >>= 1;

        while (delta > 0) {
            long long f = 0;
            do {
                markAllNodesAsUnvisited();
                f = dfs(s, INF);
                maxFlow += f;
            } while (f != 0);
            delta >>= 1;
        }
    }
};