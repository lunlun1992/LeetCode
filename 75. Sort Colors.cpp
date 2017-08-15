// start以及start的左边是0
// e的右边是2
// b是遍历的指针，发现0放到start里面去，发现2放到e里面去，发现1不管。
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int len = nums.size();
        int e = len - 1;
        int b = 0;
        int start = -1;
        
        while (b <= e) {
            if (nums[e] == 2) {
                e--;
            } else if (nums[b] == 0) {
                nums[b] = nums[++start];
                nums[start] = 0;
                b++;
            } else if (nums[b] == 2) {
                nums[b] = nums[e];
                nums[e] = 2;
            } else {
                b++;
            }
        }
    }
};