struct FenwickTreeRURQ {
    int n;
    FenwickTreePURQ bit1, bit2;

    FenwickTreeRURQ(int n) : n(n), bit1(n), bit2(n) {}

    void rangeUpdate(int l, int r, int val) {
        bit1.update(l, val);
        bit1.update(r + 1, -val);
        bit2.update(l, val * (l - 1));
        bit2.update(r + 1, -val * r);
    }

    int rangeQuery(int l, int r) {
        return bit1.rangeSum(l, r) * r - bit2.rangeSum(l, r) -
               (bit1.rangeSum(1, l - 1) * (l - 1) - bit2.rangeSum(1, l - 1));
    }
};