class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int b = 1;
        int e = len - 1;
        while (b < e) {
            int m = b + ((e - b) >> 1);
            int count = 0;
            for (int j = 0; j < len; j++)
                if (nums[j] <= m)
                    count++;
            if (count > m)
                e = m;
            else 
                b = m + 1;
        }
        return b;
    }
};