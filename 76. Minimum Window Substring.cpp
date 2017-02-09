//分两步，前进以及收缩
//收缩步骤为了最小的窗口，前进步骤为了满足条件。
class Solution {
public:
    string minWindow(string s, string t) 
    {
        int lent = t.size();
        int lens = s.size();
        int hash[256] = {0};
        for(auto c : t)
            hash[(int)c]++;
            
        int b = 0;
        int count = lent;
        int e = 0;
        int optpos = -1;
        int optlen = INT_MAX;
        
        while(e < lens)
        {
            hash[s[e]]--;
            if(hash[s[e]] >= 0)//forward
                count--;
            e++;
            
            while(count == 0)//shrink
            {
                if(optlen > e - b)
                {
                    optlen = e - b;
                    optpos = b;
                }
                
                hash[s[b]]++;
                if(hash[s[b]] > 0)
                    count++;
                b++;
            }
        }
        return optpos == -1 ? "" : s.substr(optpos, optlen);
    }
};