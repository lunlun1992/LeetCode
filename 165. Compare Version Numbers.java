//这里主要为了利用split函数haha
public class Solution 
{
    public int compareVersion(String version1, String version2)
    {
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");
        if(v1.length > v2.length)
            return -compareVersion(version2, version1);
        int len1 = v1.length;
        int len2 = v2.length;
        int i = 0;
        for(; i < len1; i++)
        {
            int i1 = Integer.parseInt(v1[i]);
            int i2 = Integer.parseInt(v2[i]);
            if(i1 > i2)
                return 1;
            else if(i1 < i2)
                return -1;
        }
        while(i < len2)
        {
            int i2 = Integer.parseInt(v2[i]);
            if(i2 != 0)
                return -1;
            i++;
        }
        return 0;
    }

}