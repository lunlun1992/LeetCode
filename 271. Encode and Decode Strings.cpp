class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) 
    {
        int len = strs.size();
        string ret = "";
        for(int i = 0; i < len; i++)
        {
            ret += to_string(strs[i].size());
            ret += ",";
            ret += strs[i];
        }
        return ret;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) 
    {
        vector<string> ret;
        int i = 0;
        int len = s.size();
        while(i < len)
        {
            int j = i;
            while(s[j] != ',')
                j++;
            int size = atoi(s.substr(i, j - i).c_str());
            ret.push_back(s.substr(j + 1, size));
            i = j + 1 + size;
        }
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));