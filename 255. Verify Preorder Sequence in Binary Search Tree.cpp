//递归法，确定每一个范围即可
class Solution {
public:
    bool verify(vector<int>& pre, int b, int e, int down, int up)
    {
        if(b > e)
            return true;
        else if(down > up)
            return false;
        else if(b == e)
            return true;
        
        int r = pre[b];
        if(r > up || r < down)
            return false;
        int i = b;
        while(i <= e && pre[i] <= r)
            i++;
        return verify(pre, b + 1, i - 1, down, r - 1) && verify(pre, i, e, r + 1, up);
    }

    bool verifyPreorder(vector<int>& preorder) 
    {
        return verify(preorder, 0, preorder.size() - 1, INT_MIN, INT_MAX);
    }
};