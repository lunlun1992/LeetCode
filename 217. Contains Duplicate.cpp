class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> s;
        for(int n : nums)
            if(s.count(n))
                return true;
            else
                s.insert(n);
        return false;
    }
};