struct TrieNode {
    int ending, holding;
    vector<TrieNode*> next;

    TrieNode() : ending(0), holding(0), next(26, nullptr) {}
};

struct Trie {
    TrieNode* head;

    Trie() { head = new TrieNode(); }

    void insert(string& s) {
        TrieNode* temp = head;
        for (auto& c : s) {
            temp->holding++;
            if (temp->next[c - 'a'] == nullptr) {
                temp->next[c - 'a'] = new TrieNode();
            }
            temp = temp->next[c - 'a'];
        }
        temp->holding++;
        temp->ending++;
    }

    int findPrefixes(string& s) {
        TrieNode* temp = head;
        for (auto& c : s) {
            if (temp->next[c - 'a'] == nullptr) return 0;
            temp = temp->next[c - 'a'];
        }
        return temp->holding;
    }
};