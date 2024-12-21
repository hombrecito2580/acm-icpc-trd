struct SegmentTreeRURQ {
    int n;
    vector<int> tree, lazy;

#define left 2 * node + 1
#define right 2 * node + 2
#define mid (start + end) / 2

    void build(int node, int start, int end, vector<int> &arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        build(left, start, mid, arr);
        build(right, mid + 1, end, arr);
        tree[node] = tree[left] + tree[right];
    }

    void pushdown(int node, int start, int end) {
        if (lazy[node]) {
            tree[node] += lazy[node] * (end - start + 1);
            if (start != end) {
                lazy[left] += lazy[node];
                lazy[right] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int inc) {
        pushdown(node, start, end);

        if (end < l || start > r) return;

        if (start >= l && end <= r) {
            lazy[node] += inc;
            pushdown(node, start, end);
            return;
        }

        update(left, start, mid, l, r, inc);
        update(right, mid + 1, end, l, r, inc);
        tree[node] = tree[left] + tree[right];
    }

    int query(int node, int start, int end, int ind) {
        pushdown(node, start, end);

        if (ind < start || ind > end) return 0;

        if (start == end) return tree[node];

        return (query(left, start, mid, ind) + query(right, mid + 1, end, ind));
    }

    SegmentTreeRURQ(vector<int> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.assign(4 * n, 0);

        build(0, 0, n - 1, arr);
    }

    void update(int l, int r, int inc) { update(0, 0, n - 1, l, r, inc); }

    int query(int ind) { return query(0, 0, n - 1, ind); }

#undef left
#undef right
#undef mid
};