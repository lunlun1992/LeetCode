class Solution {
public:
    int strobogrammaticInRange(string low, string high) 
    {
        int lenl = low.size();
        int lenh = high.size();
        int sum = 0;
        if(lenl > lenh)
            return 0;
        if(lenl == lenh)
        {
            top = lenl;
            vector<string> ret = ff(lenl);
            for(int i = 0; i < ret.size(); i++)
                if(ret[i] >= low && ret[i] <= high)
                    sum++;
            return sum;
        }
        
        top = lenl;
        vector<string> ret = ff(lenl);
        for(int i = 0; i < ret.size(); i++)
            if(ret[i] >= low)
                sum++;
        
        top = lenh;
        ret = ff(lenh);
        for(int i = 0; i < ret.size(); i++)
            if(ret[i] <= high)
                sum++;
        for(int i = lenl + 1; i < lenh; i++)
        {
            top = i;
            ret = ff(i);
            sum += ret.size();
        }
        return sum;
    }
    vector<string> ff(int n) 
    {
        if(n == 0)
            return {""};
        else if(n == 1)
            return {"0", "1", "8"};
        top = max(top, n);
        vector<string> small = ff(n - 2);
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