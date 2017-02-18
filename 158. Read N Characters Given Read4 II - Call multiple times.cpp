// Forward declaration of the read4 API.
//此题大致的意思是从文件中每次读4个char，但是一份文件没有读完，会重复调用read读。
//所以对于已经取出来的字符，要保存好，说不定下一次还要再调用read。
//此时就需要把read剩下的那部分字符也给读完了，才能接着调用read4

int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) 
    {
        int i = 0;
        while (i < n && (i4 < n4 || (i4 = 0) < (n4 = read4(buf4))))
            buf[i++] = buf4[i4++];
        return i;
    }
private:
    char buf4[4];
    int i4 = 0, n4 = 0;
};