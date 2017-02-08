//大整数乘法，注意点如下
//注意存放中间结果的位置，我是从小到大存储的，乘数1的第i位乘以乘数2的第j位，对应的位置是i+j
//注意最后多余0的去除，原因是前面仍然存在很多0，要加一个while循环去除
class Solution {
public:
    string multiply(string num1, string num2) 
    {
        string ans = "";
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> prod(220, 0);

        
        for(int i = len1 - 1; i >= 0; i--)
        {
            int digit = num1[i] - '0';
            if(digit == 0)
                continue;
            int begin = len1 - 1 - i;

            for(int j = len2 - 1; j >= 0; j--)
            {
                prod[begin + len2 - 1 - j] += digit * (num2[j] - '0');
            }
        }

        int adder = 0;
        for(int i = 0; i < len1 + len2 - 1; i++)
        {
            prod[i] += adder;
            adder = prod[i] / 10;
            prod[i] %= 10;
        }
        
        if(adder != 0)
            ans += to_string(adder);
        int i = len1 + len2 - 2;
        while(i > 0 && prod[i] == 0 && adder == 0)
            i--;
        for(; i >= 0; i--)
        {
            ans += (prod[i] + '0');
        }
        return ans;
    }
};