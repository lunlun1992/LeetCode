//找若干数组，存每一行，模拟即可。
class Solution {
public:
    string convert(string s, int numRows)
    {
        if(numRows < 2)
            return s;
        int len = s.size();
        string strs[numRows];
        int j = 0;
        int nn = numRows * 2 - 2;
        for(int i = 0; i < len; i++)
        {
            strs[j] += s[i];
            if(i % nn < numRows - 1)
                j++;
            else
                j--;
        }
        string &ret = strs[0];
        for(int i = 1; i < numRows; i++)
            ret += strs[i];
        return ret;
        
    }
};