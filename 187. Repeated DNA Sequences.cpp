class Solution {
public:
    int sss[1 << 20];
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        int len = s.size();
        if(len < 10)
            return ret;
        int hash = 0;

        for(int i = 0; i < len; i++) {
            hash <<= 2;
            switch(s[i]) {
                case 'T':
                    hash += 1;
                    break;
                case 'C':
                    hash += 2;
                    break;
                case 'G':
                    hash += 3;
                    break;
            }
            if(i >= 9) {
                hash &= 0x000fffff;
                if(sss[hash] == 1)
                    ret.push_back(s.substr(i - 9, 10));
                sss[hash]++;
            }
        }
        return ret;
        
    }
};