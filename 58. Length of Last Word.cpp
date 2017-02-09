//这个题就不要使用库函数了
class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int len = 0;
        int tail = s.size() - 1;
        while(tail >= 0 && s[tail] == ' ')
            tail--;
        while(tail >= 0 && s[tail] != ' ')
        {
            len++;
            tail--;
        }
        return len;
        
    }
};