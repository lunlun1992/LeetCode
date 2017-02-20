//判断有多少个字母重合，有多少个字母两方都有但是不重合。  
public String getHint(String secret, String guess)
{
    int[] digits = new int[10];
    int[] digitg = new int[10];
    char[] chs = secret.toCharArray();
    char[] chg = guess.toCharArray();
    int len = chs.length;
    int A = 0;
    int B = 0;
    for(int i = 0; i < len; i++)
    {
        if(chs[i] == chg[i])
            A++;
        else
        {
            digits[chs[i] - '0']++;
            digitg[chg[i] - '0']++;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        B += digits[i] < digitg[i] ? digits[i] : digitg[i];
    }
    return new String(A + "A" + B + "B");
}