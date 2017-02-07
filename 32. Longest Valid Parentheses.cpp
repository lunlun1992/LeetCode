//简单的想法，所有不匹配的括号中间都是匹配的串。
//首先存储下来所有不匹配的括号序号
//然后一个一个弹出来，中间的间隔就是其匹配的长度，找到最长的即可。

class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int len = s.size();
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(')
                st.push(i);
            else
                if(!st.empty() && s[st.top()] == '(')
                    st.pop();
                else
                    st.push(i);
        }
        if(st.empty())
            return len;
        else
        {
            int ret = INT_MIN;
            int a = 0;
            int b = len;
            while(!st.empty())
            {
                a = st.top();
                ret = max(ret, b - a - 1);
                b = a;
                st.pop();
            }
            ret = max(ret, b);//最后一个区间千万不要忘记
            return ret;
        }
    }
private:
    stack<int> st;
};