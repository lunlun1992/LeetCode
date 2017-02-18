//利用一个hash表记录出现的次数，两个字符串中若出现字母的次数相同，则两个字母是可替换得到的。
    public boolean isAnagram(String s, String t)
    {
        if("".equals(s))
        {
            if("".equals(t))
                return true;
            else
                return false;
        }
        if(s.length() != t.length())
            return false;
        char[] chs = s.toCharArray();
        char[] cht = t.toCharArray();
        int[] chsflag = new int[26];
        int[] chtflag = new int[26];
        int i = 0;
        for(i = 0; i < chs.length; i++)
        {
            chsflag[chs[i] - 'a']++;
            chtflag[cht[i] - 'a']++;
        }
        i = 0;
        while(i < 26 && chsflag[i] == chtflag[i])
            i++;
        if(i != 26)
            return false;
        else
            return true;
    }