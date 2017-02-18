// good solution, i rewrite it in c++, just for those don't know java 
bool mycomparison(pair<int, int> &p1, pair<int, int> &p2)
{
    if(p1.first != p2.first)
    {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}
struct comparor
{
    bool operator () (int a , int b)
    {
        return a > b;
    }
};
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) 
    {
        vector<pair<int, int>> ret;
        vector<pair<int, int>> sweepline;
        multiset<int, comparor> ms;
        ms.insert(0);
        for(auto &b : buildings)
        {
            sweepline.push_back(make_pair(b[0], -b[2]));
            sweepline.push_back(make_pair(b[1], b[2]));
        }
        
        sort(sweepline.begin(), sweepline.end(), mycomparison);
        int pre = 0;
        
        for(auto &s : sweepline)
        {
            
            if(s.second < 0)
            {
                ms.insert(-s.second);
            }
            else
            {
                auto it = ms.find(s.second);
                ms.erase(it);
            }
            int heightnow = *ms.begin();
            
            if(heightnow != pre)
            {
                pre = heightnow;
                ret.push_back(make_pair(s.first, heightnow));
            }
            
        }
        return ret;
    }
};