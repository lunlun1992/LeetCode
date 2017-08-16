/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
//每两个点都要算一次，然后按照斜率来hashmap
//因为截距不好算，所以固定一个点即可
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int ret = 0;
        int len = points.size();
        if(len <= 2)
            return len;
        unordered_map<int, unordered_map<int, int>> m;
        for(int i = 0; i < len - 1; i++) {
            m.clear();
            int overlap = 0;
            int vertical = 0;
            int horizontal = 0;
            int maxi = 0;
            for(int j = i + 1; j < len; j++) {
                int x1 = points[i].x;
                int y1 = points[i].y;
                int x2 = points[j].x;
                int y2 = points[j].y;
                
                int diffx = x2 - x1;
                int diffy = y2 - y1;
                if (diffx == 0 && diffy == 0) {
                    overlap++;
                    continue;
                } else if (diffx == 0) {
                    vertical++;
                    continue;
                } else if (diffy == 0) {
                    horizontal++;
                    continue;
                } else {
                    int a = diffx;
                    int b = diffy;
                    while(b) {
                        int t = b;
                        b = a % b;
                        a = t;
                    }
                    diffx /= a;
                    diffy /= a;
                    if(!m.count(diffx) || !m[diffx].count(diffy))
                        m[diffx][diffy] = 1;
                    else
                        m[diffx][diffy]++;
                }
                maxi = max(maxi, m[diffx][diffy]);
            }
            ret = max(ret, maxi + overlap + 1);
            ret = max(ret, vertical + 1);
            ret = max(ret, horizontal + 1);
        }
        return ret;
    }
};