//manacher solution
class Solution {
public:
    string longestPalindrome(string s)
    {
        if(s.empty())
            return NULL;
        int len = s.size() * 2 + 1;
        string manacher = "";
        manacher += '#';
        for(int i = 0; i < s.size(); i++)
        {
            manacher += s[i];
            manacher += '#';
        }

        vector<int> p(len, 0);
        int mx = 0;
        int id = 1;
        //printf("here\n");
        int maxnum = -1;
        int maxarg = 0;

        for(int i = 1; i < len; i++)
        {
            if(mx > i)
                p[i] = p[2 * id - i] < mx - i ? p[2 * id - i] : mx - i; //如果是
            else
                p[i] = 1;
            while(i - p[i] >= 0 && i + p[i] < len && manacher[i - p[i]] == manacher[i + p[i]])
                p[i]++;
            if(i + p[i] > mx)
            {
                mx = i + p[i];
                id = i;
            }
        }

        for(int i = 1; i < len; i++)
        {
            if(p[i] > maxnum)
            {
                maxnum = p[i];
                maxarg = i;
            }
        }


        printf("%d %d\n", maxnum, maxarg);
        string ans = manacher.substr(maxarg - maxnum + 1, 2 * maxnum - 1);
        string ret = "";
        for(int i = 0; i < ans.size(); i++)
        {
            if(ans[i] != '#')
                ret += ans[i];
        }
        return ret;
    }
};


//O(n^2) Solution
class Solution {
public:
    string longestPalindrome(string s) 
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start) 
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int expandAroundCenter(string s, int left, int right) 
    {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
};