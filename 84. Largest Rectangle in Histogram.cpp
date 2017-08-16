class Solution {
public:
typedef pair<int, int> P;
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        int len = heights.size();
        if(heights.empty())
            return 0;
        stack<P> st;
        int left[len];
        int right[len];

        //递增单调栈，找到本长方形左边的边界
        for (int i = 0; i < len; i++) {
            int leftidx = i;
            while(!st.empty() && st.top().second >= heights[i]) {
                leftidx = st.top().first;
                st.pop();
            }
            if(st.empty())
                leftidx = 0;
            else
                leftidx = st.top().first + 1;
            st.push(P(i, heights[i]));
            left[i] = leftidx;
        }
        
        //递增单调栈，找到本长方形右边的边界
        stack<P> ss;
        for(int i = len - 1; i >= 0; i--) {
            int rightidx = i;
            while(!ss.empty() && ss.top().second >= heights[i]) {
                rightidx = ss.top().first;
                ss.pop();
            }
            if(ss.empty())
                rightidx = len - 1;
            else
                rightidx = ss.top().first - 1;
            ss.push(P(i, heights[i]));
            right[i] = rightidx;
        }
        
        for(int i = 0; i < len; i++)
            ret = max(ret, heights[i] * (right[i] - left[i] + 1));
            
        return ret;
    }
};