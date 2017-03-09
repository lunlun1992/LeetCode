//pairhash的方法记住了
//另外，防止重复全部放进set里面
//对称的点可以使用(sum-)的方式
class Solution {
public:
    typedef pair<int, int> P;
    bool isReflected(vector<pair<int, int>>& points) 
    {
        int len = points.size();
        if(!len)
            return true;
        int maxx = INT_MIN;
        int minx = INT_MAX;
        for(int i = 0; i < len; i++)
        {
            minx = min(minx, points[i].first);
            maxx = max(maxx, points[i].first);
            m.insert(points[i]);
        }
        int sum = minx + maxx;
        for(int i = 0; i < len; i++)
            if(!m.count(P(sum - points[i].first, points[i].second)))
                return false;
        return true;
    }
private:
    struct pairhash
    {
        template<typename T, typename U>
        size_t operator() (const pair<T, U> &p) const
        {
            auto h1 = hash<T>{}(p.first);
            auto h2 = hash<U>{}(p.second);
            return h1 ^ h2;
        }
    };
    unordered_set<P, pairhash> m;
};