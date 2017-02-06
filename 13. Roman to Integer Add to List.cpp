//主要的思路是，1000/50/500/5左边不可能减任何数字
//其他的符号的右边都有可能组合起来表达另外一个意思。
class Solution {
public:
    int romanToInt(string s) 
    {
        int len = s.size();
        string &ch = s;
        int num = 0;
        for(int i = 0; i < len; i++)
        {
        	switch(ch[i])
        	{
        	case 'M':
        		num += 1000;
        		break;
        	case 'D':
        		num += 500;
        		break;
        	case 'C':
        		if(i != len - 1)
        		{
        			if(ch[i + 1] == 'D')
        			{
        				num += 400;
        				i++;
        			}
        			else if(ch[i + 1] == 'M')
        			{
        				num += 900;
        				i++;
        			}
        			else
        				num += 100;
        		}	
        		else
        			num += 100;
        		break;
        	case 'L':
        		num += 50;
        		break;
        	case 'X':
        		if(i != len - 1)
        		{
        			if(ch[i + 1] == 'C')
        			{
        				num += 90;
        				i++;
        			}
        			else if(ch[i + 1] == 'L')
        			{
        				num += 40;
        				i++;
        			}
        			else
        				num += 10;
        		}	
        		else
        			num += 10;
        		break;
        	case 'V':
        		num += 5;
        		break;
        	case 'I':
        		if(i != len - 1)
        		{
        			if(ch[i + 1] == 'X')
        			{
        				num += 9;
        				i++;
        			}
        			else if(ch[i + 1] == 'V')
        			{
        				num += 4;
        				i++;
        			}
        			else
        				num += 1;
        		}	
        		else
        			num += 1;
        		break;
        	}
        }
        return num;
    }
};