// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int b = 1;
        int e = n;
        while(b < e)
        {
            int m = b + ((e - b) >> 1);
            if(isBadVersion(m))
                e = m;
            else
                b = m + 1;
        } 
        return b;
    }
};