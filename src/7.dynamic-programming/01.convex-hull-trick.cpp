class CHT {
    // slope in increasing order
    deque<pair<Line, int>> dq;
public:
    void insert(int m, int c) {
        Line newLine(m, c);
        if(dq.empty()) {
            dq.push_back({newLine, INT_MN});
            return;
        }

        while(dq.size() > 1 && dq.back().second >= dq.back().first.intersect(newLine)) {
            dq.pop_back();
        }

        dq.push_back({newLine, dq.back().first.intersect(newLine)});
    }

    int query1(int x) {
        while(dq.size() > 1) {
            if(dq[1].second <= x) dq.pop_front();
            else break;
        }
        return dq[0].first.getVal(x);
    }

    int query2(int x) {
        auto it = upper_bound(dq.begin(), dq.end(), make_pair(Line(0,0), x), 
                              [&](const pair<Line, int> &a, const pair<Line, int> &b) {
                                    return a.second < b.second;
                            });
        it--;
        return (*it).first.getVal(x);
    }

};
