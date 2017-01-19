//简单的递归
class Solution {
public:
const string tele[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    void dfs(string &digits, int first, string last, vector<string> &ret)
    {
        int len = digits.size();
        if(first == len)
        {
            ret.push_back(last);
            return;
        }
        int num = digits[first] - '0';
        for(int i = 0; i < tele[num].size(); i++)
        {
            last += tele[num][i];
            dfs(digits, first + 1, last, ret);
            last.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ret;
        if(digits.empty())
            return ret;
        string last = "";
        dfs(digits, 0, last, ret);
        return ret;
    }
};