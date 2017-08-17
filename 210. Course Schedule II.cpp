class Solution {
public:
typedef pair<int, int> P;
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ret;
        vector<int> map(numCourses, 0);
        int count = 0;
        int SizePre = prerequisites.size();
        for (int i = 0; i < SizePre; i++) {
            P p = prerequisites[i];
            map[p.first]++;
        }
        queue<int> que;
        for(int i = 0; i < numCourses; i++)
            if(map[i] == 0)
                que.push(i);
        while (!que.empty()) {
            int front = que.front();
            que.pop();
            count++;
            for (int i = 0; i < SizePre; i++) {
                if (front == prerequisites[i].second) {
                    map[prerequisites[i].first]--;
                    if(map[prerequisites[i].first] == 0)
                        que.push(prerequisites[i].first);
                }
            }
            ret.push_back(front);
        }
        if(count != numCourses)
            return {};
        else
            return ret;
    }
};