//去除重复的字母，并且返回最小字母序的字符串。
//去处重复字母我会啊。用一个hashtable
//如何返回最小字母序？此时就要维护一个表，其存储每一个字母的最先位置。
//那么为了不丢失任何字母，一定要在最先位置之前把它放入字符串，同时为了维护字母序，则在这个位置之前搜索比较小的字母，然后先实现它，最后才管当前的字母。这样既不会丢失字母，也不会违反字母序。
//这样的速度是O(26n)，有点慢。
class Solution {
public:
    int findtheFirstEnd(int *alpha)
    {
        int mini = INT_MAX;
        for(int i = 0; i < 26; i++)
            if(alpha[i] != -1)
                mini = min(mini, alpha[i]);
        return mini;
    }

    string removeDuplicateLetters(string s)
    {
        int len = s.size();
        int alpha[26];
        memset(alpha, -1, sizeof(alpha));
        for(int i = 0; i < len; i++)
            alpha[s[i] - 'a'] = i;

        int retlen = 0;
        for(int i = 0; i < 26; i++)
            if(alpha[i] != -1)
                retlen++;

        string ret(retlen, 0);
        int begin = 0;
        int end = findtheFirstEnd(alpha);
       // printf("%d\n", end);
        for(int i = 0; i < retlen; i++)
        {
            char smallest = 'z' + 1;
            for(int k = begin; k <= end; k++)
            {
                if(alpha[s[k] - 'a'] != -1 && s[k] < smallest)
                {
                    smallest = s[k];
                    begin = k + 1;
                }
            }
           // printf("%c\n", smallest);
            ret[i] = smallest;
            alpha[smallest - 'a'] = -1;
            if(smallest == s[end])
                end = findtheFirstEnd(alpha);
        }

        return ret;

    }
};