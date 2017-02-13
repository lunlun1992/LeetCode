//这道题就是递归找划分点
class Solution {
public:
    vector<vector<string>> ret;
    vector<string> vec;

    bool isPalindrome(string s, int start, int end)
    {
        if(start == end)
            return true;
        while(start < end && s[start] == s[end])
        {
            start++;
            end--;
        }
        if(start >= end)
            return true;
        else
            return false;
    }

    void part(string s, int start)
    {
        if(start == s.size())
        {
            ret.push_back(vec);
            return;
        }
        for(int i = start; i < s.size(); i++)
        {
            if(isPalindrome(s, start, i))
            {
                vec.push_back(s.substr(start, i - start + 1));
                part(s, i + 1);
                vec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        if(s.empty())
            return ret;
        part(s, 0);
        return ret;
    }
};