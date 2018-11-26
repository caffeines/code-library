const int size = 26;
vector<string> words;
bool ok = true;
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
    Node* search(string &s) {
        Node *node = root;
        for (int i = 0; i < s.size(); i++) {
            int c = getId(s[i]);
            node = node->child[c];
            if (node == NULL){
                ok = false;
                return node;
            }
        }
        return (node);
    }

    
    /* DFS  traverse */
    void DFS(Node *node, string word) {
        if(node->cnt) {
            if(word != "")
                words.push_back(word);
        }

        for(int i = 0; i < 26; i++)
            if(node->child[i] != NULL)
                DFS(node->child[i], word + char(i + 'a'));
    }

} trie;


/*
	Node * n = trie.search(str);
	if(n == trie.root || !ok){
	    puts("No match.");
	} else{
	    trie.DFS(n,"");
	    for (int i = 0; i < words.size(); ++i) {
		printf("%s%s\n",str.c_str(), words[i].c_str());
	    }
	}
*/

