class Solution {
public:
    typedef pair<int, int> P;
    int calculate(string s)
    {
        stack<P> st1, st2;
        int len = s.size();
        int i = 0;
        while (i < len)
        {
            if (s[i] == ' ')
            {
                i++;
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9')
            {
                int j = i;
                while (j < len && s[j] >= '0' && s[j] <= '9')
                    j++;
                st2.push(P(atoi(s.substr(i, j - i).c_str()), 0));
                i = j;
                continue;
            }
            if (s[i] == ')')
            {
                P t = st1.top();
                while (!st1.empty() && t.first != '(')
                {
                    st2.push(t);
                    st1.pop();
                    t = st1.top();
                }
                st1.pop();
                i++;
            }
            else if (s[i] == '(' || st1.empty() || st1.top().first == '(')
            {
                st1.push(P(s[i], 1));
                i++;
                continue;
            }
            else if ((s[i] == '*' || s[i] == '/') && (st1.top().first == '+' || st1.top().first == '-'))
            {
                st1.push(P(s[i], 1));
                i++;
            }
            else if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-')
            {
                st2.push(st1.top());
                st1.pop();
            }

        }
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }

        //calculate

        while (!st1.empty())
        {
            P p = st1.top();
            st1.pop();
            if (p.second == 0)
            {
                st2.push(p);
            }
            else
            {
                char op = p.first;
                int aop = st2.top().first;
                st2.pop();
                int bop = st2.top().first;
                st2.pop();
                int res;
                switch (op)
                {
                case '+':
                    res = bop + aop;
                    break;
                case '-':
                    res = bop - aop;
                    break;
                case '*':
                    res = bop * aop;
                    break;
                case '/':
                    res = bop / aop;
                    break;
                }
                st2.push(P(res, 0));
            }
        }

        return st2.top().first;
    }
};