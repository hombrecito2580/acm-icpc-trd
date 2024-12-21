struct DSU {
    vector<int> parent, rank, size;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0); 
        size.resize(n, 1); 
        rep(i, 0, n) parent[i] = i;
    }
    
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {  
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY]; 
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX]; 
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY]; 
                rank[rootX]++; 
            }
        }
    }
};