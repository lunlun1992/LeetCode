class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2)
    {
        int len = words.size();
        int i1 = -1;
        int i2 = -1;
        int ret = INT_MAX;
        bool bsame = false;
        if (word1 == word2)
            bsame = true;
        for (int i = 0; i < len; i++) {
            if (word1 == words[i]) {
                i1 = i;
                if(bsame) {
                    int temp = i1;
                    i1 = i2;
                    i2 = temp;
                }
            }
            else if (word2 == words[i])
                i2 = i;
            if(i1 != -1 && i2 != -1)
                ret = min(ret, abs(i1 - i2));
        }
        return ret;
    }
};