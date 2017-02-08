//思路是：用两个指针确定中间有多少水
//每次让两个指针中比较矮的那个向前走，防止加入了过多的水
//如果遇到了低洼（确定方法是之前的最大值大于此处，之后肯定有比之前的最大值更大的边界，由于上一行的条件）
//则填充水，如果遇到了高地，则更新最大值。
//直到两个指针相遇。
class Solution {
public:
    int trap(vector<int>& height)
    {
        if(height.empty())
            return 0;
        int len = height.size();
        
        int s = 0;
        int e = len - 1;
        int maxs = 0;
        int maxe = 0;
        int ret = 0;
        while(s < e)
        {
            if(height[s] < height[e])
            {
                if(height[s] > maxs)
                    maxs = height[s];
                else
                    ret += maxs - height[s];
                s++;
            }
            else
            {
                if(height[e] > maxe)
                    maxe = height[e];
                else
                    ret += maxe - height[e];
                e--;
            }
        }
        
        return ret;
        
    }
};