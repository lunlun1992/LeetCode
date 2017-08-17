//芯片淘汰法，发现不一样的就一起扔，发现一样的就加1.
//顺序芯片淘汰法虽然时间复杂度高，但是简单。
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        if(!len)
            return nums;
        int n1;
        int c1 = 0;
        int n2;
        int c2 = 0;
        vector<int> ret;
        for (int i = 0; i < len; i++) {
            if(!c1 && nums[i] != n2) {
                c1++;
                n1 = nums[i];
            } else if(!c2 && nums[i] != n1) {
                c2++;
                n2 = nums[i];
            } else {
                if(nums[i] == n1)
                    c1++;
                else if(nums[i] == n2)
                    c2++;
                else {
                    c1--;
                    c2--;
                }
            }
        }
        if (c1) {
            int count = 0;
            for(int i = 0; i < len; i++)
                if(n1 == nums[i])
                    count++;
            if(count > len / 3)
                ret.push_back(n1);
        }
        if (c2) {
            int count = 0;
            for(int i = 0; i < len; i++)
                if(n2 == nums[i])
                    count++;
            if(count > len / 3)
                ret.push_back(n2);
        }
        return ret;
    }
};