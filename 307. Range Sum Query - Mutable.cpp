//采用了BIT（树状数组）来存储数据，O(logn)的查询和修改时间
class NumArray {
public:
    vector<int> BIT;
    vector<int> nn;
    int len;
    NumArray(vector<int> &nums)
    {
        len = nums.size();
        nn = nums;
        BIT.assign(len + 1, 0);
        for(int i = 1; i <= len; i++)
        {
            update(i - 1, nn[i - 1] * 2);
            nn[i - 1] /= 2;
        }
    }

    void update(int i, int val)
    {
        i++;
        int diff = val - nn[i - 1];
        nn[i - 1] = val;
        //printf("VAL : %d NN : %d DIFF : %d\n", val, nn[i - 1], diff);
        while(i <= len)
        {
            BIT[i] += diff;
            i += (i & (-i)); //find the last bit index
        }

        // for(int j = 1; j <= len; j++)
        //     printf("BIT : %d\nNN : %d\n", nn[j - 1]);
    }

    int sumRange(int i, int j)
    {
        i++;
        j++;
        int ret = 0;

        while(j > 0)
        {
            ret += BIT[j];
            j -= (j & (-j));
        }

        if(i != 1)
        {
            i--;
            while(i > 0)
            {
                ret -= BIT[i];
                i -= (i & (-i));
            }
        }
       // printf("SUM : %d\n", ret);
        return ret;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);