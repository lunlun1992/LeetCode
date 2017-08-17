class Solution {
public:
    vector<int> diffWaysToCompute(string input) 
    {
        vector<int> ret;
        int len = input.size();
        for(int i = 0; i < len; i++) {
            if (!isdigit(input[i])) {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                
                for (int u = 0; u < left.size(); u++) {
                    for (int v = 0; v < right.size(); v++) {
                        switch(input[i]) {
                            case '+':
                                ret.push_back(left[u] + right[v]);
                                break;
                            case '-':
                                ret.push_back(left[u] - right[v]);
                                break;
                            case '*':
                                ret.push_back(left[u] * right[v]);
                                break;
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