//贪心法做题
class Solution {
public:
    string rearrangeString(string s, int k) 
    {
        int len = s.size();
        unordered_map<char, int> count;
        unordered_map<char, int> valid;
        for(char c : s)
        {
            count[c]++;
            valid[c] = 0;
        }
        
        string ret = "";
        for(int i = 0; i < len; i++)
        {
            bool found = false;
            char now = 'a';
            int maxi = INT_MIN;
            for(auto it : count)
            {
                if(maxi < it.second && valid[it.first] <= i)
                {
                    found = true;
                    now = it.first;
                    maxi = it.second;
                }
            }
            if(!found)
                return "";
            
            ret += now;
            count[now]--;
            if(count[now] == 0)
                count.erase(now);
            valid[now] += k;
        }
        return ret;
        
    }
};