//桶排序
//每一个盒子里的最大和最小值才是我要知道的，其他的不知道也罢
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) 
            return 0;
        auto lr = minmax_element(nums.begin(), nums.end());
        int l = *lr.first;
        int r = *lr.second;
        
        int gap = max((r - l) / (n - 1) , 1);
        int buckets = (r - l) / gap + 1; //put the max value in the last bucket;
        
        vector<int> bumax(buckets, INT_MIN);
        vector<int> bumin(buckets, INT_MAX);
        
        for(int i = 0; i < n; i++) {
            int index = (nums[i] - l) / gap;
            bumax[index] = max(bumax[index], nums[i]);
            bumin[index] = min(bumin[index], nums[i]);
        }
        int i = 0;
        int gapmax = bumax[0] - bumin[0];
        while(i < buckets) {
            int j = i + 1;
            while(j < buckets && bumax[j] == INT_MIN && bumin[j] == INT_MAX)
                j++;
            if(j == buckets)
                break;
            gapmax = max(gapmax, bumin[j] - bumax[i]);
            i = j;
        }
        return gapmax;
        
    } 
};