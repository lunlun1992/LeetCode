//将一个正整数的每一位相加，得到最终的数。这个数叫数根，是一个数mod9的余数，如果这个数是9的倍数，则结果是9。
public class Solution
{
    public int addDigits(int num)
    {
        if(num <= 0)
            return 0;
        if(num % 9 == 0)
            return 9;
        else
            return num % 9;
    }
}