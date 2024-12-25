struct info {
    // all the data required
    // for merging and answering queries
    int sum, minPrefL, maxPrefL, minPrefR, maxPrefR, minSeg, maxSeg;

    info(int el = 0) {
        sum = el;
        minSeg = minPrefL = minPrefR = min(el, 0LL);
        maxSeg = maxPrefL = maxPrefR = max(el, 0LL);
    }
};

info merge(info &a, info &b) {
    // a's ending node is same as b's starting node
    // however info doesn't include ending node's value
    info res;
    res.sum = a.sum + b.sum;
    res.minPrefL = min(a.minPrefL, a.sum + b.minPrefL);
    res.maxPrefL = max(a.maxPrefL, a.sum + b.maxPrefL);
    res.minPrefR = min(a.minPrefR + b.sum, b.minPrefR);
    res.maxPrefR = max(a.maxPrefR + b.sum, b.maxPrefR);
    res.minSeg = min({a.minSeg, b.minSeg, a.minPrefR + b.minPrefL});
    res.maxSeg = max({a.maxSeg, b.maxSeg, a.maxPrefR + b.maxPrefL});
    return res;
}

const int MAXN = 2e5 + 5;
const int MAXLOG = 20;

// logCache[2^i] = i
map<int, int> logCache;
// depth of each node
vector<int> lvl(MAXN);
// par[i][0] -> immediate parent of i
vector<vector<int>> par(MAXN, vector<int>(MAXLOG));
// lift[i][j] -> value from i (inclusive) to 2^j th parent (exclusive)
// lift[i][0] -> i node's value only
vector<vector<info>> lift(MAXN, vector<info>(MAXLOG));

int lca(int a, int b) {
    if (lvl[a] < lvl[b]) swap(a, b);

    int diff = lvl[a] - lvl[b];
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if ((diff >> i) & 1) {
            a = par[a][i];
        }
    }

    if (a == b) return b;

    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (par[a][i] != par[b][i]) {
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}

void reverseData(info &u) {
    swap(u.minPrefL, u.minPrefR);
    swap(u.maxPrefL, u.maxPrefR);
}

info segmentData(int a, int b) {
    if (lvl[a] < lvl[b]) swap(a, b);

    info u, v;

    int diff = lvl[a] - lvl[b];
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if ((diff >> i) & 1) {
            u = merge(u, lift[a][i]);
            a = par[a][i];
        }
    }

    if (a == b) {
        u = merge(u, lift[a][0]);
        return u;
    }

    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (par[a][i] != par[b][i]) {
            u = merge(u, lift[a][i]);
            v = merge(v, lift[b][i]);
            a = par[a][i];
            b = par[b][i];
        }
    }
    u = merge(u, lift[a][1]);
    v = merge(v, lift[b][0]);
    reverseData(v);
    return merge(u, v);
}