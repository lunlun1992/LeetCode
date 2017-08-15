//KMP算法
int next[100000];
int strStr(char* haystack, char* needle)
{
    int lenh = strlen(haystack);
    int lenn = strlen(needle);
    int i = 0;
    int j = -1;

    if(lenh < lenn)
        return -1;
    if(lenh == 0 || lenn == 0)
        return 0;

   
    next[0] = -1;
    while(i < lenn)
    {
        if(j == -1 || needle[i] == needle[j])
        {
            i++;
            j++;
            next[i] = j;// needle[i] == needle[j] ? next[j] : j;
        }
        else
        {
            j = next[j];
        }
    }
    j = 0;
    i = 0;
    while(i < lenh && j < lenn)
    {
        if(j == -1 || haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
      
    }
    return j == lenn ? (i - j) : -1;
}