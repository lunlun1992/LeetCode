//设计一个类，实现返回数组任意部分和。
//方法是保存所有第一个数到当前数的和，当需要一段距离的和时，就相减即可
public class NumArray
{
    int[] sums;
    public NumArray(int[] nums)
    {
        int len = nums.length;
        int i;
        int sum = 0;
        sums = new int[len];
        for(i = 0; i < len; i++)
        {
            sum += nums[i];
            sums[i] = sum;
        }
    }

    public int sumRange(int i, int j)
    {
        if(i == 0)
            return sums[j];
        else
            return sums[j] - sums[i - 1];
    }
}