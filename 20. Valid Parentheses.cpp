//利用一个栈来判断括号的完成性。
class Solution {
public:
    bool isValid(string s)
    {
        int len = s.size();
        for(int i = 0; i < len; i++)
        {
            switch(s[i])
            {
            case '(':
                st.push('(');
                break;
            case '[':
                st.push('[');
                break;
            case '{':
                st.push('{');
                break;
            case '}':
                if(!st.empty() && st.top() == '{')
                    st.pop();
                else
                    return false;
                break;
            case ']':
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else
                    return false;
                break;                
            case ')':
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    return false;
                break;            
            }
        }
        return st.empty();
    }
private:
    stack<char> st;
};