//确定中间重合部分的边长
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        int ret = (D - B) * (C - A) + (H - F) * (G - E);
        int W1 = max(A, E);
        int W2 = min(C, G);
        int H1 = max(B, F);
        int H2 = min(D, H);
        if(W1 >= W2 || H1 >= H2)
            return ret;
        ret -= (W2 - W1) * (H2 - H1);
        return ret;
    }
};