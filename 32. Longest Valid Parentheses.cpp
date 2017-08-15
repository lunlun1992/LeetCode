//简单的想法，所有不匹配的括号中间都是匹配的串。
//首先存储下来所有不匹配的括号序号
//然后一个一个弹出来，中间的间隔就是其匹配的长度，找到最长的即可。

class Solution {
public:
    int longestValidParentheses(string s)
    {
        int ret = 0;
        int len = s.size();
        if(len < 2)
            return 0;
        stack<int> st;
        
        for (int i = 0; i < len; i++) {
            if (!st.empty() && s[i] == ')' && s[st.top()] == '(') {
                st.pop();
            } else {
                st.push(i);
            }
        }
        int a = len;
        int b = -1;
        while (!st.empty()) {
            b = st.top();
            st.pop();
            ret = max(ret, a - b - 1);
            a = b;
        }
        return max(ret, a);
    }
};