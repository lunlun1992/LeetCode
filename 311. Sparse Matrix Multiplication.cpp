class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ar = A.size();
        int ac = A[0].size();
        int br = B.size();
        int bc = B[0].size();
        
        vector<vector<int>> ret(ar, vector<int>(bc, 0));
        for (int i = 0; i < ar; i++) {
            for (int j = 0; j < ac; j++) {
                if (A[i][j]) {
                    for (int k = 0; k < bc; k++) {
                        ret[i][k] += A[i][j] * B[j][k];
                    }
                }
            }
        }
        return ret;
    }
};