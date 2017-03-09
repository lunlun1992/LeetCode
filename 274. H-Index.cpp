//首先要确定每一个的个数
//然后累加，O(n)
class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        int len = citations.size();
        vector<int> counts(len + 1, 0);
        for(int i = 0; i < len; i++)
            counts[min(len, citations[i])]++;
        for(int i = len; i > 0; i--)
        {
            if(counts[i] >= i)
                return i;
            else
                counts[i - 1] += counts[i];
        }
        return 0;
    }
};