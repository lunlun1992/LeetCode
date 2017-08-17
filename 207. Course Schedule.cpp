class Solution {
public:

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> map(numCourses, 0);
        int lenedge = prerequisites.size();
        for(int i = 0; i < lenedge; i++) {
            pair<int, int> p = prerequisites[i];
            map[p.first]++;
        }
        queue<int> que;
        for(int i = 0; i < numCourses; i++)
            if (map[i] == 0)
                que.push(i);
        int count = 0;
        while (!que.empty()) {
            int front = que.front();
            que.pop();
            count++;
            for (int i = 0; i < lenedge; i++) {
                pair<int, int> p = prerequisites[i];
                if (p.second == front) {
                    map[p.first]--;
                    if (map[p.first] == 0)
                        que.push(p.first);
                }
            }
        }
        return count == numCourses;
    }
};