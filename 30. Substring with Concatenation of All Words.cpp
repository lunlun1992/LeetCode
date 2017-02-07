//这题的思路是，滑动窗口法。用两个hashmap来存储本字符串是否存在于字典里面。
//如果多了，则一个一个删除，直到不多
//如果不存在，则从下一个点开始找
//如果少了，直接加一即可。
//由于是字符串，存在长度，故起始搜索点等于字符串的长度。

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> ret;
        for(auto word : words)
            d[word]++;
        int wordlen = words[0].size();
        int slen = s.size();
        int wc = words.size();
        for(int k = 0; k < wordlen; k++)
        {
            unordered_map<string, int> dict;
            int start = k;
            int count = 0;
            for(int i = k; i + wordlen <= slen; i += wordlen)
            {
                string now = s.substr(i, wordlen);
                if(d.count(now))
                {
                    if(dict[now] < d[now])
                    {
                        dict[now]++;
                        count++;
                    }
                    else
                    {
                        dict[now]++;
                        count++;
                        while(dict[now] > d[now])
                        {
                            string tore = s.substr(start, wordlen);
                            start += wordlen;
                            dict[tore]--;
                            count--;
                        }
                    }
                    
                    if(count == wc)
                    {
                        ret.push_back(start);
                        count--;
                        dict[s.substr(start, wordlen)]--;
                        start += wordlen;
                    }
                }
                else
                {
                    start = i + wordlen;
                    count = 0;
                    dict.clear();
                }
            }
        }
        return ret;
    }
private:
    unordered_map<string, int> d;
};