//找到丢失的那个数，显然用下标置换，最后谁保留着最后一个数，谁就是缺失的那个数。   
 public int missingNumber(int[] nums)
    {
        int len = nums.length;
        int n = len;
        for(int i = 0; i < len; i++)
        {
            while(i != nums[i])
            {
                if(nums[i] == len)
                {
                    n = i;
                    break;
                }
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return n;
    }