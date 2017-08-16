class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        if(tokens.empty())
            return 0;
        stack<int> st1;
        for(int i = 0; i < tokens.size(); i++) {
            if(isdigit(tokens[i][0]) || tokens[i].size() > 1 && isdigit(tokens[i][1])) {
                st1.push(atoi(tokens[i].c_str()));
            } else {
                int aop = st1.top();
                st1.pop();
                int bop = st1.top();
                st1.pop();
                switch(tokens[i][0])
                {
                case '+':
                    st1.push(bop + aop);
                    break;
                case '-':
                    st1.push(bop - aop);
                    break;
                case '*':
                    st1.push(bop * aop);
                    break;
                case '/':
                    st1.push(bop / aop);
                    break;
                }
            }
        }
        return st1.top();
    }
};