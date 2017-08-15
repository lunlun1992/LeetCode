//simulation
class Solution {
public:
    string countAndSay(int n) {
        string now = "1";
        for(int i = 2; i <= n; i++) {
            string next = "";
            int j = 0;
            int count = 0;
            for (int j = 0; j < now.size(); j++) {
                if (j > 0 && now[j - 1] != now[j]) {
                    next.append(to_string(count));
                    next.push_back(now[j - 1]);
                    count = 1;
                } else {
                    ++count;
                }
            }
            next.append(to_string(count));
            next.push_back(now.back());
            now = next;
        }
        return now;
    }
};