struct FenwickTree2D {
    vector<vector<int>> bit;
    int n, m;
    
    FenwickTree2D(int n, int m) {
        this->n = n;
        this->m = m;
        bit.assign(n + 1, vector<int>(m + 1, 0)); 
    }
    
    void update(int x, int y, int val) {
        for (int i = x; i <= n; i += i & -i) {
            for (int j = y; j <= m; j += j & -j) {
                bit[i][j] += val;
            }
        }
    }
    
    int prefixQuery(int x, int y) {
        int sum = 0;
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                sum += bit[i][j];
            }
        }
        return sum;
    }
    
    int rangeQuery(int x1, int y1, int x2, int y2) {
        return prefixQuery(x2, y2) - prefixQuery(x1 - 1, y2) - prefixQuery(x2, y1 - 1) + prefixQuery(x1 - 1, y1 - 1);
    }
};