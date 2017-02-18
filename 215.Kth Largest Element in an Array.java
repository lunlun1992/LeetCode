public class Solution 
{
    static int[] nn = null;
    static void swap(int l, int r)
    {
        int t = nn[l];
        nn[l] = nn[r];
        nn[r] = t;
    }
    static int find(int s, int e, int small)
    {
        if(s == e)
            return s;
        int pivot = nn[s];
        int l = s + 1;
        int r = e;
        while(l <= r)
        {
            while(l <= r && nn[l] <= pivot)
                l++;
            if(l > r)
                break;
            while(r >= l && nn[r] > pivot)
                r--;
            if(l > r)
                break;
            swap(l, r);
        }
        swap(s, r);
        if(r == small)
            return r;
        else if(r < small)
            return find(r + 1, e, small);
        else
            return find(s, r - 1, small);
            
    }
    public int findKthLargest(int[] nums, int k) 
    {
        int len = nums.length;
        nn = nums;
        return nums[find(0, len - 1, len - k)];
    }
}