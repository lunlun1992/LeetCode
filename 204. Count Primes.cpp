class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is(n, false);
        for (int i = 2; i < n; i++)
            is[i] = true;
        for (int i = 2; i * i < n; i++) {
            if(!is[i])
                continue;
            for(int j = 2; j * i < n; j++)
                is[j * i] = false;
        }
        int count = 0;
        for (int i = 2; i < n; i++)
            if (is[i])
                count++;
        return count;    
    }
};