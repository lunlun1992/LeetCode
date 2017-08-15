//贪心法，每次把比较短的边向长的边伸展。只要比原先大即可。
//正确性：如果比原先小，则肯定不比原先更好，因为长度变小了。
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int ret = INT_MIN;
        while (l < r) {
            ret = max(ret, (r - l) * min(height[l], height[r]));
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ret;
    }
};