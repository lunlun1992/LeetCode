//这里使用了一个双端链表结构来维护cache，每touch一次就把它放到开头
//set的时候也可以touch
class LRUCache {
public:
    LRUCache(int capacity) 
    {
        capa = capacity;
    }
    
    int get(int key) 
    {
        if(!dict.count(key))
            return -1;
        touch(key);
        return dict[key];
    }
    
    void put(int key, int value) 
    {
        if(dict.count(key))
        {
            touch(key);
            dict[key] = value;
        }
        else
        {
            if(key_que.size() == capa)
            {
                dict.erase(key_que.back());
                m.erase(key_que.back());
                key_que.pop_back();
            }
            key_que.push_front(key);
            m[key] = key_que.begin();
            dict[key] = value;
        }
        
    }
private:
    int capa;
    unordered_map<int, int> dict;
    list<int> key_que;
    unordered_map<int, list<int>::iterator> m;
    
    void touch(int key)
    {
        key_que.erase(m[key]);
        key_que.push_front(key);
        m[key] = key_que.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */