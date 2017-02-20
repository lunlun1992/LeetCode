class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        if(k == 0)
            return 0;
        int map[256];
        memset(map, 0, sizeof(map));
        int len = s.size();
        int b = 0;
        int e = 0;
        int ret = 0;
        int count = 0;
        while(e < len)
        {
            while(e < len)
            {
                if(map[s[e]]++ == 0)
                    count++;
                if(count == k + 1)
                    break;
                e++;
            }
            ret = max(ret, e - b);
            
            //cout << e << " " << b << endl;
            while(b < e && count == k + 1)
            {
                if(--map[s[b]] == 0)
                    count--;
                b++;
            }
            e++;
        }
        return ret;
    }
};