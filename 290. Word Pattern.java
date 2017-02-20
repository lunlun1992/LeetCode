//利用Java的hash特性实现了一个map，感觉很简单，但是没有模板的怎么办？    
public boolean wordPattern(String pattern, String str)
{
    int patlen = pattern.length();
    char[] chpat = pattern.toCharArray();
    str = str.trim();
    String[] words = str.split(" ");
    int wordslen = words.length;
    int[] charac = new int[256];
    if(wordslen != patlen)
        return false;
    HashMap<Character, String> hash = new HashMap<Character, String>();
    for(int i = 0; i < patlen; i++)
    {
        if(hash.containsKey(chpat[i]))
        {
            if(!hash.get(chpat[i]).equals(words[i]))
                return false;
        }
        else
        {
            if(hash.containsValue(words[i]))
                return false;
            else
                hash.put(chpat[i], words[i]);
        }
    }
    return true;
}