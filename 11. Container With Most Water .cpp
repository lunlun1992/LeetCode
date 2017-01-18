//贪心法，每次把比较短的边向长的边伸展。只要比原先大即可。
//正确性：如果比原先小，则肯定不比原先更好，因为长度变小了。
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int len = height.size();
        int i = 0;
        int j = len - 1;
        int ret = 0;
        while(i < j)
        {
            int sum = (j - i) * min(height[j], height[i]);
            ret = max(ret, sum);
            int ih = height[i];
            int jh = height[j];
            if(ih < jh)
                while(i < j && height[i] <= ih)
                    i++;
            else
                while(i < j && height[j] <= jh)
                    j--;
        }
        return ret;
        
    }
};