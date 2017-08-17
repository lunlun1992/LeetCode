//这是着重优化add的算法
class TwoSum {
    unordered_map<int, int> map;
public:
    void add(int number) {
        map[number]++;
    }

    bool find(int value) {
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            int i = it->first;
            int j = value - i;
            if ((i == j && it->second > 1) || (i != j && map.find(j) != map.end())) {
                return true;
            }
        }
        return false;
    }
};


//优化find的算法，只需要加入了一个map，确定某一个和是否存在即可