class TrieNode {
public:
    // Initialize your data structure here.
    char ch;
    TrieNode *next[26];
    TrieNode()
    {
        ch = 'a';
        memset(next, 0, sizeof(next));
    }
    TrieNode(char c) 
    {
        ch = c;
        memset(next, 0, sizeof(next));
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) 
    {
        int len = word.size();
        TrieNode *node = root;
        int i = 0;
        for(; i < len; i++)
        {
            if(node->next[word[i] - 'a'] != NULL)
                node = node->next[word[i]];
            else
            {
                TrieNode *n = new TrieNode(word[i]);
                node->next[word[i] - 'a'] = n;
            }
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) 
    {
        return startsWith(word);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) 
    {
        int len = prefix.size();
        TrieNode *node = root;
        for(int i = 0; i < len; i++)
        {
            if(node->next[prefix[i] - 'a'] != NULL)
                node = node->next[prefix[i]];
            else
                return false;
        }
        return true; 
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");