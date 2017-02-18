//把字符串反过来然后比较
class Solution {
public:
    string strrev(string &str)
    {
        string ret(str);
        int len = ret.size();
        int s = 0;
        int e = len - 1;
        while(s < e)
        {
            char temp = ret[s];
            ret[s] = ret[e];
            ret[e] = temp;
            s++;
            e--;
        }
        return ret;
    }

    string shortestPalindrome(string s)
    {
        int i;
        int len = s.size();
        if(len == 0) return s;
        string v = strrev(s);  //Reverse s.
        for(i = len; i >= 1; --i)
            if(s.substr(0, i) == v.substr(len - i)) 
                break;    //palindrome?
        for(; i < s.size(); i += 2)
            s = s[i] + s;   //Construct
        return s;
    }
};