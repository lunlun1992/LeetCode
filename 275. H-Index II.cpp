class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if (!len)
            return 0;
        int b = 0;
        int e = len - 1;
        while (b < e) {
            int m = b + ((e - b) >> 1);
            int size = len - m;
            if (size == citations[m])
                return size;
            else if (size > citations[m])
                b = m + 1;
            else
                e = m;
        }
        return len - b > citations[b] ? 0 : len - b;//如果连最后的终点都大于，则证明所有的数字都是0.
    }
};