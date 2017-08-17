class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        vector<int> accu(len + 1, 0);
        
        for (auto n : citations) {
            accu[min(len, n)]++;
        }
        
        for (int i = len; i >= 0; i--) {
            if (accu[i] >= i)
                return i;
            else
                accu[i - 1] += accu[i];
        }
        return 0;
    }
};