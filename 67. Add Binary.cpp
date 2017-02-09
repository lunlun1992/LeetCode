//半加器组合成全加器
//一个数字用完了没关系，接着加。
class Solution {
public:
    string addBinary(string a, string b) 
    {
        int lena = a.size();
        int lenb = b.size();
        
        int i = lena - 1;
        int j = lenb - 1;
        int adder = 0;
        string ret = "";
        
        while(i >= 0 || j >= 0 || adder == 1)
        {
            adder += i >= 0 ? a[i--] - '0' : 0;
            adder += j >= 0 ? b[j--] - '0' : 0;
            ret = (char)(adder % 2 + '0') + ret;
            adder /= 2;
        }
        return ret;
    }
};