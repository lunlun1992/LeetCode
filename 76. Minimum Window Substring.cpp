//最小值的话，一定要在收缩的时候拿到
//这里收缩之后，会多收缩一个位置，所以要加一。
//模板就是这样。
class Solution {
public:
    string minWindow(string s, string t) 
    {
        int lent = t.size();
        int lens = s.size();
        int hash[256] = {0};
        int b = 0;
        int count = lent;
        int e = 0;
        int optpos = -1;
        int optlen = INT_MAX;
        for(auto c : t)
            hash[c]++;       
        while (e < lens) {     
            while (e < lens && count > 0)
                if (hash[s[e++]]-- > 0)
                    --count;
            while (b < e && count == 0)
                if (hash[s[b++]]++ == 0)
                    ++count;
            if(optlen > e - b + 1) {
                optlen = e - b + 1;
                optpos = b - 1;
            }
        }
        return optpos == -1 ? "" : s.substr(optpos, optlen);
    }
};