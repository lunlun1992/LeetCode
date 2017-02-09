//每一次找下一个节点中潜力最大的点。
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int len = nums.size();
        
        int idx = 0;
        while(idx < len - 1)
        {
            if(!nums[idx])
                return false;
            int nextidx = idx;
            int maxi = 0;
            int nextone = 0;
            for(int i = 1; i <= nums[idx]; i++)
            {
                int nextidx = idx + i;
                if(nextidx > len - 1)
                    return true;
                if(nextidx + nums[nextidx] > maxi)
                {
                    maxi = nextidx + nums[nextidx];
                    nextone = nextidx;
                }
            }
            idx = nextone;
        }
        return true;
    }
};

//这种做法很聪明，反其道而行之
//找到能到最后一个点的所有点，每次记录最靠前的那一个。
//如果能到任何一个，都能到最后一个
//如果连最靠前的那个点都到不了，则肯定不可能到最后一个点
//最后判断0点能否到即可。
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int len = nums.size();
        
        int idx = len - 1;
        for(int i = len - 1; i >= 0; i--)
        {
            if(nums[i] + i >= idx)
            {
                idx = i;
            }
        }
        return idx == 0;
    }
};