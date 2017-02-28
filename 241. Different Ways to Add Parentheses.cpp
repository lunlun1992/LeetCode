class Solution {
public:
    vector<int> diffWaysToCompute(string input) 
    {
        vector<int> ret;
        int len = input.size();
        for(int i = 0; i < len; i++)
        {
            if(!isdigit(input[i]))
            {
                vector<int> before = diffWaysToCompute(input.substr(0, i));
                vector<int> after = diffWaysToCompute(input.substr(i + 1));
                for(auto i1 : before)
                {
                    for(auto i2 : after)
                    {
                        switch(input[i])
                        {
                        case '+':
                            ret.push_back(i1 + i2);
                            break;
                        case '-':
                            ret.push_back(i1 - i2);
                            break;
                        case '*':
                            ret.push_back(i1 * i2);
                        }
                    }
                }
            }
        }
        if(ret.empty())
            return {atoi(input.c_str())};
        else
            return ret;
    }
};