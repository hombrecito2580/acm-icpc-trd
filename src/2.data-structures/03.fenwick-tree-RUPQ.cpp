struct FenwickTreeRUPQ {
    vector<int> bit, arr; 
    int n;
    
    FenwickTreeRUPQ(int n, const vector<int>& initialArray) {
        this->n = n;
        arr = initialArray;
        bit.assign(n + 1, 0);  
        
        for (int i = 1; i <= n; i++) {
            pointUpdate(i, arr[i - 1]); 
        }
    }
    
    void rangeUpdate(int l, int r, int val) {
        pointUpdate(l, val);      
        pointUpdate(r + 1, -val); 
    }
    
    void pointUpdate(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }
    
    int pointQuery(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }
    
    int getValue(int idx) {
        return arr[idx - 1] + pointQuery(idx);
    }

    void setValue(int idx, int newValue) {
        int diff = newValue - arr[idx - 1];  
        arr[idx - 1] = newValue;             
        pointUpdate(idx, diff);              
    }
};