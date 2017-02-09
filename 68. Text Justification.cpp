//模拟题，注意最后一行的特殊性以及空格的分配
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string> ret;
        int len = words.size();
        int i = 0;
        while(i < len)
        {
            int totallen = words[i].size();
            int b = i;
            i++;
            while(i < len && maxWidth >= totallen + words[i].size() + 1)
            {
                totallen += words[i].size() + 1;
                i++;
            }
            int e = i - 1;
            int spacecount = e - b;
            
            if(b == e)
            {
                string now(maxWidth, ' ');
                now.replace(0, words[b].size(), words[b]);
                ret.push_back(now);
            }
            else if(i == len)
            {
                string aa = words[b];
                for(int j = b + 1; j <= e; j++)
                {
                    aa += " ";
                    aa += words[j];
                }
                string space(maxWidth - totallen, ' ');
                aa += space;
                ret.push_back(aa);
            }
            else
            {
                int remain = maxWidth - totallen + spacecount;
                int left = remain / spacecount;
                string aa = words[b];
                
                cout << remain << " " << left << endl;
                
                for(int j = b + 1; j <= e; j++)
                {
                    if((remain % (e - j + 1)) == 0)
                    {
                        string space(left, ' ');
                        aa += space;
                        remain -= left;
                    }
                    else
                    {
                        string space(left + 1, ' ');
                        aa += space;
                        remain -= (left + 1);
                    }
                    aa += words[j];
                }
                ret.push_back(aa);
            }
            
        }
        return ret;
    }
};