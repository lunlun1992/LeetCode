//之前想到了做三次dp的方法，但是做两次的没有想到。
//就是空出第一个不做，只看最后一个；和空出最后一个不做，只看第一个，找最大的那个。
public class Solution {
    static int dynamic(int[] nnn, int start, int end)
    {
        int[] dp = new int[end - start + 1];
        dp[0] = nnn[start];
        dp[1] = Math.max(nnn[start + 1], dp[0]);
        for(int i = 2; i < end - start + 1; i++)
        {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nnn[start + i]);
        }
        return dp[end - start];
    }
    public int rob(int[] nums)
    {
        int len = nums.length;
        int max = -1;
        if(0 == len)
            return 0;
        else if(1 == len)
            return nums[0];
        else if(2 == len)
            return Math.max(nums[0], nums[1]);
        //0 get
        max = Math.max(dynamic(nums, 0, len - 2), max);
        //len - 1 get
        max = Math.max(dynamic(nums, 1, len - 1), max);

        return max;

    }
}