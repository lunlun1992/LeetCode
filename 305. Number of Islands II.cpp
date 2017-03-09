//二维并查集，寻找到了之后就合并即可
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) 
    {
        vector<int> union_set(m * n, INT_MAX);
        vector<int> ret;
        int len = positions.size();
        int total = 0;
        for(int i = 0; i < len; i++)
        {
            P p = positions[i];
            int idxnow = point(p.first, p.second, n);
            union_set[idxnow] = -1;
            total++;
            
            int idxnext = point(p.first - 1, p.second, n);
            if(isvalid(p.first - 1, p.second, m, n) && union_set[idxnext] != INT_MAX && find_set(idxnext, union_set) != find_set(idxnow, union_set))
            {
                total--;
                uni(idxnext, idxnow, union_set);
            }
            
            idxnext = point(p.first + 1, p.second, n);
            if(isvalid(p.first + 1, p.second, m, n) && union_set[idxnext] != INT_MAX && find_set(idxnext, union_set) != find_set(idxnow, union_set))
            {
                total--;
                uni(idxnext, idxnow, union_set);
            }
            
            idxnext = point(p.first, p.second - 1, n);
            if(isvalid(p.first, p.second - 1, m, n) && union_set[idxnext] != INT_MAX && find_set(idxnext, union_set) != find_set(idxnow, union_set))
            {
                total--;
                uni(idxnext, idxnow, union_set);
            }
            
            idxnext = point(p.first, p.second + 1, n);
            if(isvalid(p.first, p.second + 1, m, n) && union_set[idxnext] != INT_MAX && find_set(idxnext, union_set) != find_set(idxnow, union_set))
            {
                total--;
                uni(idxnext, idxnow, union_set);
            }
            ret.push_back(total);
        }
        return ret;
    }
private:
    inline bool isvalid(int x, int y, int m, int n)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    inline int point(int x, int y, int n)
    {
        return x * n + y;
    }
    int find_set(int idx, vector<int> &us)
    {
        if(us[idx] < 0)
            return idx;
        else 
            return us[idx] = find_set(us[idx], us);
    }
    void uni(int idxa, int idxb, vector<int> &us)
    {
        int paa = find_set(idxa, us);
        int pab = find_set(idxb, us);
        if(us[paa] <= us[pab])
        {
            us[paa] += us[pab];
            us[pab] = paa;
        }
        else
        {
            us[pab] += us[paa];
            us[paa] = pab;
        }
    }
};