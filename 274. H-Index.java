//用标记数组排序，从后往前找，比i大的有几个便可以知道
public class Solution {
    public int hIndex(int[] citations)
    {
        int len = citations.length;
        if(0 == len)
            return 0;
        int[] index = new int[len + 1];
        for(int i = 0; i < len; i++)
        {
            int t = Math.min(citations[i], len);
            index[t]++;
        }
        if(index[len] >= len)
            return len;
        int i;
        for(i = len - 1; i >= 0; i--)
        {
            index[i] += index[i + 1];
            if(index[i] >= i)
                break;
        }

        return i;
    }
}