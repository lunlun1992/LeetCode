class Solution {
public:
    string licenseKeyFormatting(string S, int K)
    {
        string res;
        for (auto i = S.rbegin(); i < S.rend(); i++)
            if (*i != '-') 
                (res.size() % (K + 1) - K ? res : res += '-') += toupper(*i);
        return reverse(res.begin(), res.end()), res;
    }
};