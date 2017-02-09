public class Solution {
    public String simplifyPath(String path)
    {
        Stack<String> stack = new Stack<String>();
        int len = path.length();
        if(len == 0)
            return "";
        String[] strs = path.split("/");
        if(strs.length == 0)
            return "/";
        int depth = 0;
        for(int i = 0; i < strs.length; i++)
        {
            if(strs[i].equals(".") || strs[i].equals(""))
                continue;
            if(strs[i].equals(".."))
            {
                if(stack.empty())
                {

                }
                else
                    stack.pop();
            }
            else
                stack.push(strs[i]);
        }
        String ret = "";
        for(int i = 0; i < stack.size(); i++)
        {
            ret += ("/" + stack.get(i));
        }

        if(stack.empty())
            ret = "/";
        return ret;
    }
}
