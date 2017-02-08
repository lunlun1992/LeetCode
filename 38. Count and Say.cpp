//就是模拟题
class Solution {
public:
    string countAndSay(int n)
    {
        string str = "1";
        for(int k = 0; k < n - 1; k++)
        {
            string next = "";
            int len = str.size();
            int i = 0;
            char now = str[0];
            int count = 0;
            while(i < len)
            {
                if(str[i] == now)
                {
                    count++;
                    i++;
                }
                else
                {
                    next += (count + '0');
                    next += now;
                    count = 1;
                    now = str[i];
                    i++;
                }
            }
            
            next += (count + '0');
            next += now;
            str = next;
        }
        return str;
    }
};