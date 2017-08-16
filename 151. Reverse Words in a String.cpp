//先把字符串整体翻转，然后再翻转每一个单词。
//去除多余空格采用的方法是有效区域法，用b作为指针即可。
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int len = s.size();
        int b = -1;
        for(int i = 0; i < len; i++) {
            if(s[i] != ' ') {
                if(b >= 0)
                    s[++b] = ' ';
                int j = i;
                while(j < len && s[j] != ' ')
                    s[++b] = s[j++];
                reverse(s.begin() + b - (j - i) + 1, s.begin() + b + 1);
                i = j;
            }
        }
        s.erase(s.begin() + b + 1, s.end());
    }
};