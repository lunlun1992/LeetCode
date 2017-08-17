// Forward declaration of the knows API.
bool knows(int a, int b);
//首先，如果A认识B，则A肯定不是，B有可能是，设置为candidate。
//如果C不认识candidate，则candidate肯定不是，candidate = C
//最后检验一下candidate是否大家都认识以及是否一个人也不认识
class Solution {
public:
    int findCelebrity(int n) {
        if (!n)
            return -1;
        int cand = 0;
        for (int i = 1; i < n; i++) {
            if (!knows(i, cand)) {
                cand = i;
            }
        } 
        for (int i = 0; i < n; i++) {
            if (i != cand && (knows(cand, i) || !knows(i, cand))) {
                return -1;
            }
        }
        return cand;
    }
};