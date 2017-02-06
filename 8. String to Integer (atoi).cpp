//1.考虑多余空格
//2.考虑符号位
//3.考虑途中遇到非数字的跳出
//4.考虑溢出的跳出
class Solution {
public:
    int myAtoi(string str)
    {
        if(str.empty())
            return 0;
        str.erase(0, str.find_first_not_of(" "));
        str.erase(str.find_last_not_of(" ") + 1);
        int len = str.size();
        int64_t ans = 0;
        bool isnaga = false;
        int startpos = 0;
        if(str[0] == '+')
            startpos = 1;
        if(str[0] == '-')
        {
            isnaga = true;
            startpos = 1;
        }
        for(int i = startpos; i < len; i++)
        {
            if(!isdigit(str[i]))
                break;
            ans *= 10;
            ans += (str[i] - '0');
            if(isnaga && ans > 2147483648)
            {
                ans = INT_MIN;
                break;
            }
            if(!isnaga && ans > 2147483647)
            {
                ans = INT_MAX;
                break;
            }
                
        }
        return (int)(isnaga ? -ans : ans);
    }
};