//教科书上的回溯法，简单应用，还可以优化。
public class Solution
{
    static ArrayList<List<Integer>> list;
    static ArrayList<Integer> arr;
    static void dfs(int num, int n, int k)
    {
        if(k == 0)
        {
            if(n == 0)
            {
                ArrayList<Integer> arr1 = new ArrayList<Integer>();
                arr1.addAll(arr);
                list.add(arr1);
            }
            return;
        }
       
        for(int i = num; i <= 9; i++)
        {
            if(n - i >= 0)
            {
                arr.add(i);
                dfs(i + 1, n - i, k - 1);
                arr.remove(arr.size() - 1);
            }
        }
    }
    public List<List<Integer>> combinationSum3(int k, int n)
    {
        list = new ArrayList<List<Integer>>();
        if(k == 0)
            return list;
        arr = new ArrayList<Integer>();
        dfs(1, n, k);
        return list;
    }
}