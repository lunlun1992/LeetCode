//各种各样的奇葩情况
class Solution {
public:
    bool isNumber(string s) 
    {
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        int len = s.size();
        if(s.empty())
            return false;
        bool digitseen = false;
        bool Eseen = false;
        bool numberafterE = true;
        bool pointseen = false;
        for(int i = 0; i < len; i++)
        {
            if(isdigit(s[i]))
            {
                digitseen = true;
                numberafterE = true;
            }
            else if(s[i] == 'e')
            {
                
                if(!digitseen || Eseen)
                    return false;
                numberafterE = false;
                Eseen = true;
            }
            else if(s[i] == '.')
            {
                if(Eseen || pointseen)
                    return false;
                pointseen = true;
            }
            else if(s[i] == '-' || s[i] == '+')
            {
                if(i != 0 && s[i - 1] != 'e')
                    return false;
            }
            else 
                return false;
            
        }
        return numberafterE && digitseen;
    }
};