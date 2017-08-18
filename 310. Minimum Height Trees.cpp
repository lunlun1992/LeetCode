//找到一棵树的最小高度根节点，方法是求得树的直径和两端，然后回溯半径长度，就能找到对应的根节点了。
//根节点可以是1到2个。
//找到一棵树的最小高度根节点，方法是求得树的直径和两端，然后回溯半径长度，就能找到对应的根节点了。
//根节点可以是1到2个。
class Solution {
public:
typedef pair<int, int> P;
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<bool> flag(n, false);
        vector<int> ret;
        vector<vector<int>> G(n);
        int len = edges.size();
        for (int i = 0; i < len; i++) {
            P p = edges[i];
            G[p.first].push_back(p.second);
            G[p.second].push_back(p.first);
        }
        queue<P> que;
        que.push(P(0, 0));
        flag[0] = true;
        int maxd = 0;
        int maxv = 0;
        while (!que.empty()) {      //BFS找最远的点
            P p = que.front();
            que.pop();
            int to = p.first;
            int depth = p.second;
            if (depth > maxd) {
                maxd = depth;
                maxv = to;
            }
            for(int i = 0; i < G[to].size(); i++) {
                if(!flag[G[to][i]]) {
                    que.push(P(G[to][i], depth + 1));
                    flag[G[to][i]] = true;
                }
            }
        }

        flag.assign(n, false);
        flag[maxv] = true;
        vector<int> back(n, -1);
        que.push(P(maxv, 0));
        maxd = 0;
        int othermaxv = 0;
        while (!que.empty()) {      //BFS找直径
            P p = que.front();
            que.pop();
            int to = p.first;
            int depth = p.second;
            if (depth > maxd) {
                maxd = depth;
                othermaxv = to;
            }
            for (int i = 0; i < G[to].size(); i++) {
                if (!flag[G[to][i]]) {
                    back[G[to][i]] = to;
                    que.push(P(G[to][i], depth + 1));
                    flag[G[to][i]] = true;
                }
            }
        }
        int temp = othermaxv;
        for (int i = 0; i < maxd / 2; i++) {
            temp = back[temp];
        }
        ret.push_back(temp);
        if (maxd % 2 == 0) {
            return ret;
        } else {
            temp = back[temp];
            ret.push_back(temp);
            return ret;
        }
    }
};