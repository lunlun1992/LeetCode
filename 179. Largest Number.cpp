//主要看两个数正反拼接之后，其大小的区别。
class Solution {
public:
    static bool compare(string n1, string n2) {
        string n1first = n1 + n2;
        string n2first = n2 + n1;
        return n1first.compare(n2first) >= 0;
    }
    
    string largestNumber(vector<int>& nums) {
        int len = nums.size();
        int nzeros = 0;
        vector<string> snums;      
        for(int i = 0; i < len; i++) {
            if(nums[i] == 0) {
                nzeros++;
                continue;
            }
            snums.push_back(to_string(nums[i]));
        }
        if(nzeros == nums.size())
            return "0";

        sort(snums.begin(), snums.end(), compare);
        string ret = "";
        for(int i = 0; i < snums.size(); i++)
            ret += snums[i];
        for(int i = 0; i < nzeros; i++)
                ret += "0";
        return ret;
    }
};