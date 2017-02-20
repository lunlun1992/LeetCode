//暴力搜索法，说实话很慢，但是代码的思路值得学习。
//先取前面，再取中间长度，最后迭代后面长度。
public class Solution {

    boolean isValid(int i, int j, String num)
    {
        if(num.charAt(0) == '0' && i > 1)
            return false;
        if(num.charAt(i) == '0' && j > 1)
            return false;
        String sum = "";
        long nb = Long.parseLong(num.substring(0, i));
        long na = Long.parseLong(num.substring(i, i + j));
        for(int k = i + j; k < num.length(); k += sum.length())
        {
            na = nb + na;
            nb = na - nb;
            sum = na + "";
            //System.out.println(sum);
            if(!num.startsWith(sum, k))
                return false;
        }
        return true;
    }
    public boolean isAdditiveNumber(String num)
    {
        int len = num.length();
        if(len < 3)
            return false;
        for(int i = 1; i <= len / 2; i++)
        {
            for(int j = 1; Math.max(i, j) <= len - i - j; j++)
            {
                if(isValid(i, j, num))
                    return true;
            }
        }
        return false;
    }
}