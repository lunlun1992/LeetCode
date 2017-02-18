class Solution {
public:
    bool isStrobogrammatic(string num) 
    {
        vector<vector<bool>> map(10, vector<bool>(10, false));
        map[6][9] = map[9][6] = true;
        map[1][1] = map[8][8] = map[0][0] = true;
        int i = 0;
        int j = num.size() - 1;
        while(i <= j)
        {
            if(!map[num[i] - '0'][num[j] - '0'])
                return false;
            i++;
            j--;
        }
        return true;
    }
};