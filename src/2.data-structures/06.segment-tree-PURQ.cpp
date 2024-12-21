struct SegmentTreePURQ {
    int n;
    vector<int> tree;

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

    int query(int node, int start, int end, int l, int r) {
        if (end < l || start > r) return 0;

        if (start >= l && end <= r) return tree[node];

        return (query(left, start, mid, l, r) +
                query(right, mid + 1, end, l, r));
    }

    void update(int node, int start, int end, int ind, int val) {
        if (ind < start || ind > end) return;

        if (start == end) {
            tree[node] = val;
            return;
        }

        update(left, start, mid, ind, val);
        update(right, mid + 1, end, ind, val);
        tree[node] = tree[left] + tree[right];
    }

    SegmentTreePURQ(vector<int> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    int query(int l, int r) { return query(0, 0, n - 1, l, r); }

    void update(int ind, int val) { update(0, 0, n - 1, ind, val); }

#undef left
#undef right
#undef mid
};