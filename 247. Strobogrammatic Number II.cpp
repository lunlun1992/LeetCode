class Solution {
public:
    vector<string> findStrobogrammatic(int n) 
    {
        if(n == 0)
            return {""};
        else if(n == 1)
            return {"0", "1", "8"};
        top = max(top, n);
        vector<string> small = findStrobogrammatic(n - 2);
        vector<string> ret;
        int len = small.size();
        for(int i = 0; i < len; i++)
        {
            ret.push_back("6" + small[i] + "9");
            ret.push_back("9" + small[i] + "6");
            ret.push_back("1" + small[i] + "1");
            ret.push_back("8" + small[i] + "8");
            if(n != top)
                ret.push_back("0" + small[i] + "0");
        }
        return ret;
    }
private:
    int top;
};