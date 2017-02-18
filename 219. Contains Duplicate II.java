//利用hashset和滑动窗口法解决一个窗口内存在重复的问题。 
   public boolean containsNearbyDuplicate(int[] nums, int k)
    {
        HashSet<Integer> hash = new HashSet<Integer>();
        if(nums == null)
            return true;
        if(k == 0)
            return false;
        k++;
        if(k >= nums.length)
        {
            for(int i = 0; i < nums.length; i++)
            {
                if(!hash.add(nums[i]))
                    return true;
            }
            return false;
        }
        for(int i = 0; i < k; i++)
        {
            if(!hash.add(nums[i]))
                return true;
        }
        int lenw = nums.length - k;
        for(int j = 0; j < lenw; j++)
        {
            hash.remove(nums[j]);
            if(!hash.add(nums[k + j]))
                return true;
        }
        return false;
       
    }