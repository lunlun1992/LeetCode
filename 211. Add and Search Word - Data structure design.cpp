class TrieNode {
public:
    // Initialize your data structure here.
    char ch;
    TrieNode *next[26];
    bool isWordEnd;
    TrieNode()
    {
        ch = 'a';
        isWordEnd = false;
        memset(next, 0, sizeof(next));
    }
    TrieNode(char c)
    {
        ch = c;
        isWordEnd = false;
        memset(next, 0, sizeof(next));
    }
};

class WordDictionary {
public:
    
    TrieNode *root;
    
    WordDictionary()
    {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word)
    {
        int len = word.size();
        if(len == 0)
            return;
        TrieNode *node = root;
        for(int i = 0; i < len; i++)
        {
            int chindex = word[i] - 'a';
            if(node->next[chindex] == NULL)
            {
                TrieNode *n = new TrieNode(word[i]);
                node->next[chindex] = n;
                node = n;
            }
            else
            {
                node = node->next[chindex];
            }
        }
        node->isWordEnd = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search_my(string word, int start, TrieNode *now)
    {
        if(start == word.size())
            return now->isWordEnd;
        
        if(word[start] == '.')
        {
            for(int i = 0; i < 26; i++)
                if(now->next[i] && search_my(word, start + 1, now->next[i]))
                    return true;
            return false;
        }
        else
        {
            int chindex = word[start] - 'a';
            if(now->next[chindex] != NULL)
                return search_my(word, start + 1, now->next[chindex]);
            else
                return false;
        }
        
    }
    
    bool search(string word)
    {
        if(word.empty())
            return false;
        return search_my(word, 0, root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");