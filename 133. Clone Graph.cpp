/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
//DFS或者BFS都行，用一个map对应原来的节点和克隆的节点。
//然后边遍历，边克隆
//最后需要加上visited
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        stack<UndirectedGraphNode *> st;
        st.push(node);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        unordered_set<int> visited;
        UndirectedGraphNode *h = new UndirectedGraphNode(node->label);
        m[node] = h;
        visited.insert(node->label);
        while(!st.empty()) {
            UndirectedGraphNode *temp = st.top();
            st.pop();
            UndirectedGraphNode *head = m[temp];
            for(int i = 0; i < temp->neighbors.size(); i++) {
                if(!visited.count(temp->neighbors[i]->label)) {
                    UndirectedGraphNode *u = new UndirectedGraphNode(temp->neighbors[i]->label);
                    st.push(temp->neighbors[i]);
                    head->neighbors.push_back(u);
                    visited.insert(temp->neighbors[i]->label);
                    m[temp->neighbors[i]] = u;
                } else {
                    head->neighbors.push_back(m[temp->neighbors[i]]);
                }
                
            }
        }
        return m[node];
    }
};