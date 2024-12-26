struct SparseTable {
    vector<vector<int>> st;
    vector<int> logValues;
    int n;
 
    SparseTable(const vector<int>& arr) {
        n = arr.size();
        int maxLog = log2(n) + 1;
        st = vector<vector<int>>(n, vector<int>(maxLog));
        logValues = vector<int>(n + 1);
 
        logValues[1] = 0;
        for (int i = 2; i <= n; i++) logValues[i] = logValues[i / 2] + 1;
 
        for (int i = 0; i < n; i++) st[i][0] = arr[i];
 
        for (int j = 1; j <= maxLog; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
 
    int rangeMinQuery(int l, int r) {
        int j = logValues[r - l + 1];
        return min(st[l][j], st[r - (1 << j) + 1][j]);
    }
    
};