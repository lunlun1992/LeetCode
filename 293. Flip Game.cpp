class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) 
    {
        vector<string> ret;
        int len = s.size();
        for(int i = 0; i < len - 1; i++)
        {
            if(s[i] == '+' && s[i + 1] == '+')
            {
                string now = s;
                now[i] = '-';
                now[i + 1] = '-';
                ret.push_back(now);
            }
        }
        return ret;
    }
};