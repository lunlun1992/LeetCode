class WordDistance {
public:
    WordDistance(vector<string> words) 
    {
        int len = words.size();
        for(int i = 0; i < len; i++)
        {
            m[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) 
    {
        if(word1 == word2)
            return 0;
        int len1 = m[word1].size();
        int len2 = m[word2].size();
        int ret = INT_MAX;
        for(int i = 0; i < len1; i++)
            for(int j = 0; j < len2; j++)
                ret = min(ret, abs(m[word1][i] - m[word2][j]));
        return ret;
    }
private:
    unordered_map<string, vector<int>> m;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */