//1.考虑多余空格
//2.考虑符号位
//3.考虑途中遇到非数字的跳出
//4.考虑溢出的跳出
class Solution {
public:
    int myAtoi(string str) {
        str.erase(0, str.find_first_not_of(" "));  
        str.erase(str.find_last_not_of(" ") + 1); 
        if(str.empty())
            return 0;
        bool isnaga = (str[0] == '-');
        int startidx = (str[0] == '+' || str[0] == '-') ? 1 : 0;
        int len = str.size();
        int64_t num = 0;
        while(startidx < len && num <= 2147483648) {
            if(str[startidx] < '0' || str[startidx] > '9') break;
            num *= 10;
            num += str[startidx++] - '0';
        }
        if(num > 2147483648)
            return isnaga ? INT_MIN : INT_MAX;
        else if(num > 2147483647)
            return isnaga ? -(int)num : INT_MAX;
        else
            return isnaga ? -(int)num : (int)num;
    }
};