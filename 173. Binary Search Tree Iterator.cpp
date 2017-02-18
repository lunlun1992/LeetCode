/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) 
    {
        node = root;    
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty() || node;
    }

    /** @return the next smallest number */
    int next() 
    {
        while(node)
        {
            st.push(node);
            node = node->left;
        }
        node = st.top();
        st.pop();
        int ret = node->val;
        node = node->right;
        return ret;
    }
private:
    TreeNode *node;
    stack<TreeNode *> st;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */