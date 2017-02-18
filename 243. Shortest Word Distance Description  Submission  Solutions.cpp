class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2)
    {
        int len = words.size();
        int i1 = -1;
        int i2 = -1;
        int ret = INT_MAX;
        if(word1 == word2)
            return 0;
        for(int i = 0; i < len; i++)
        {
            if(word1 == words[i])
                i1 = i;
            else if(word2 == words[i])
                i2 = i;
            if(i1 != -1 && i2 != -1)
                ret = min(ret, abs(i1 - i2));
        }
        return ret;
    }
};