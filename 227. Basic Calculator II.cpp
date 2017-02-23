//思路如下：将序列用加减号分开
//然后每一个区间，计算一个now值，now值的正负由前置的符号决定
//乘除可以直接使用前一个now值
class Solution {
public:
    int calculate(string s) 
    {
        int len = s.size();
        if(!len)
            return 0;
        int ret = 0;
        int now = 0;
        char op = '+';
        int i = 0;
        while(i < len)
        {
            if(isdigit(s[i]))
            {
                int temp = 0;
                while(i < len && isdigit(s[i]))
                    temp = temp * 10 + (s[i++] - '0');
                switch(op)
                {
                case '+':
                    now = temp;
                    break;
                case '-':
                    now = -temp;
                    break;
                case '*':
                    now *= temp;
                    break;
                case '/':
                    now /= temp;
                    break;
                }
            }
            else if(s[i] == ' ')
                i++;
            else
            {
                if(s[i] == '+' || s[i] == '-')
                {
                    ret += now;
                    now = 0;
                }
                op = s[i++];
            }
        }
        return ret + now;
    }
};