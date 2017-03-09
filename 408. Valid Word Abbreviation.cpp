class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) 
    {
        int lenw = word.size();
        int lena = abbr.size();
        int j = 0;
        int i = 0;
        while(i < lena && j < lenw)
        {
            if(islower(abbr[i]))
            {
                if(word[j] != abbr[i])
                    return false;
                else
                {
                    i++;
                    j++;
                }
            }
            else
            {
                int count = 0;
                int ori = i;
                if(abbr[ori] == '0')
                    return false;
                while(i < lena && isdigit(abbr[i]))
                    count = count * 10 + (abbr[i++] - '0');
                istringstream istr(abbr.substr(ori, i - ori));
                istr >> count;
                
                if(count > lenw - j)
                    return false;
                j += count;
            }
        }
        return i == lena && j == lenw;
    }
};