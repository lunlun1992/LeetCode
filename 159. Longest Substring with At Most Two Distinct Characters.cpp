//记住套路
//1.先前进e，注意停止点的细节
//2.最优化
//3.前进s
//4.最后看要不要前进一步e
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
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
                if(count == 3)
                    break;
                e++;
            }
            ret = max(ret, e - b);
            
            cout << e << " " << b << endl;
            while(b < e && count == 3)
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