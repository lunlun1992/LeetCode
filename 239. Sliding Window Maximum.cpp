//滑动窗口法取最大值，方法是使用一个双端队列做数据结构存储index。
//按照顺序放入index。每次从队列头取出窗口外的index，每次从队列尾取出不如本次放入的大的index。
//这样双端队列里面的队头肯定是最大的。
class Solution {
public:
#define MAX(a,b) ((a) > (b) ? (a) : (b))
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> ret;
        deque<int> dq;
        int len = nums.size();
        if(len == 0)
            return ret;

        for(int i = 0; i < len; i++)
        {
            while(!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1)
                ret.push_back(nums[dq.front()]);
        }

        return ret;
    }
};