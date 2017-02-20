//除了二分搜索，还可以双指针逼近
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target)
    {
        int count = 0;
        sort(nums.begin(), nums.end());
        int len = nums.size();
    
        for(int i = 0; i < len - 2; i++) 
        {
            int left = i + 1;
            int right = len - 1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] < target) 
                {
                    count += right - left;
                    left++;
                } 
                else
                    right--;
            }
        }   
        return count;
    }
};