struct FenwickTreePURQ {
    int n;
    vector<int> bit;

    FenwickTreePURQ(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }
    
    int prefixSum(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

    int rangeSum(int l, int r) {
        return prefixSum(r) - prefixSum(l - 1);
    }
};