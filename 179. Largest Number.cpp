//主要看两个数正反拼接之后，其大小的区别。
class Solution {
public:
    static bool compare(string n1, string n2)
    {
        string n1first = n1 + n2;
        string n2first = n2 + n1;
        for(int i = 0; i < n1first.size(); i++)
            if(n1first[i] != n2first[i])
                return n1first[i] > n2first[i];
        return true;//n1first[i] == n2first[i];
    }
    
    string largestNumber(vector<int>& nums) 
    {
        int len = nums.size();
        int nzeros = 0;
        vector<string> snums;
        for(int i = 0; i < len; i++)
        {
            char temp[1000];
            if(nums[i] == 0)
            {
                nzeros++;
                continue;
            }
            sprintf(temp, "%d", nums[i]);
            string s(temp);
            snums.push_back(s);
        }
        sort(snums.begin(), snums.end(), compare);
        string ret = "";
        for(int i = 0; i < snums.size(); i++)
        {
            ret += snums[i];
            //cout << snums[i] << endl;
        }
        if(nzeros == nums.size())
            return "0";
        else
            for(int i = 0; i < nzeros; i++)
                ret += "0";
        return ret;
    }
};