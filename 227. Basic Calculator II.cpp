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
        while(i < len) {
            if (s[i] == ' ') {
                ++i;
            } else if (isdigit(s[i])) {
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
            } else {
                if(s[i] == '+' || s[i] == '-') {
                    ret += now;
                    now = 0;
                }
                op = s[i++];
            }
        }
        return ret + now;
    }
};