//这样直接来就行，左右夹击
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int b = 0;
        int e = numbers.size() - 1;
        while(b < e)
        {
            int v = numbers[b] + numbers[e];
            if(v > target)
                e--;
            else if(v < target)
                b++;
            else
                return {b + 1, e + 1};
        }
        return {};
    }
};