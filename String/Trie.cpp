const int size = 26;

struct Node {
    Node *child[size] = {NULL};
    int cnt = 0, pre = 0;

    Node() {}
};

struct Trie {
    Node *root;

    Trie() {
        root = new Node();
    }

    /* Return integer value of alphabet and number */
    int getId(const char &c) {
        if (isalpha(c)) {
            if (islower(c))
                return c - 'a';
            return c - 'A';
        }
        return c - '0';
    }

    /* String insertion in trie */
    void add_String(string &s) {
        Node *node = root;
        for (int i = 0; i < s.size(); i++) {
            int c = getId(s[i]);
            if (node->child[c] == NULL) node->child[c] = new Node();
            node = node->child[c];
            node->pre++;
        }
        node->cnt++;

    }

    /* Search a string in trie*/
    bool search(string &s) {
        Node *node = root;
        for (int i = 0; i < s.size(); i++) {
            int c = getId(s[i]);
            node = node->child[c];
            if (node == NULL)
                return false;
        }
        return (node->cnt > 0);
    }

    /* Delete string from trie */
    void remove(string &s) {
        int n = s.size();
        Node *node = root;
        for (int i = 0; i < n; i++) {
            int c = getId(s[i]);
            if (node->child[c] == NULL) return;
            node = node->child[c];
        }
        node->cnt--;
    }

    /* Prefix query */
    int query(string &s) {
        int n = s.size();
        Node *node = root;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int c = getId(s[i]);
            if (node->child[c] == NULL) return ans;
            node = node->child[c];
            ans = node->pre;
        }
        return ans;
    }

    /* Destruct all trie */
    void clear() {
        clean(root);
        root = new Node();
    }

    void clean(Node *node) {
        if (node == NULL) return;
        for (int i = 0; i < size; i++) {
            if (node->child[i] != NULL) clean(node->child[i]);
        }
        delete (node);
    }

    /* dont forget to clear memory */
} trie;

