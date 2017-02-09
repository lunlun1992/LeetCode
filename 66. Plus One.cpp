//加一而已不要想那么复杂
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int len = digits.size();
        int adder = 1;
        for(int i = len - 1; i >= 0; i--)
        {
            if(adder == 0)
                break;
            digits[i] += adder;
            adder = digits[i] / 10;
            digits[i] %= 10;
        }
        if(!adder)
            return digits;
        else
        {
            digits.push_back(0);
            digits[0] = 1;
            return digits;
        }
        
    }
};