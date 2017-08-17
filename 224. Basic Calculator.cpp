//利用sign存加减号，利用ans存之前的结果
//出现括号的时候用栈保存之前的结果
class Solution {
public:
    int calculate(string s) 
    {
        stack<int> st;
        int ans = 0;
        int sign = 1;
        int len = s.size();
        int i = 0;
        while (i < len) {
            if (isdigit(s[i])) {
                int now = 0;
                while (i < len && isdigit(s[i])) {
                    now *= 10;
                    now += (s[i] - '0');
                    i++;
                }
                ans += sign * now;
            } else if (s[i] == '+') {
                sign = 1;
                i++;
            } else if(s[i] == '-') {
                sign = -1;
                i++;
            } else if(s[i] == '(') {
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
                i++;
            } else if(s[i] == ')') {
                int ts = st.top();
                st.pop();
                int ta = st.top();
                st.pop();
                ans = ans * ts + ta;
                i++;
            } else
                i++;
        }
        return ans;
        
    }
};