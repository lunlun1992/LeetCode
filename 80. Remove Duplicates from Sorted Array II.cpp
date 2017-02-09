//相对于原来，加了一个计数器。
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int start = -1;
        int b = 0;
        int len = nums.size();
        int count = 0;
        int lastnum = 0;
        if(len < 2)
            return len;

        nums[++start] = nums[b++];
        count++;
        lastnum = nums[start];
        
        while(b < len)
        {
            if(lastnum == nums[b])
            {
                count++;
                if(count > 2)
                    b++;
                else
                    nums[++start] = nums[b++];
            }
            else
            {
                nums[++start] = nums[b++];
                count = 1;
                lastnum = nums[start];
            }
        }
        return start + 1;
    }
};

//用n>nums[i - 2]代表其不重复超过两次
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int i = 0;
        for(auto n : nums)
            if(i < 2 || n > nums[i - 2])
                nums[i++] = n;
        return i;
    }
};