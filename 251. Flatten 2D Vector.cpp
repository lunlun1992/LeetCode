class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d)
    {
        it = vec2d.begin();
        end = vec2d.end();
        idx = 0;
    }

    int next() 
    {
        return it->at(idx++);
    }

    bool hasNext()
    {
        while(it != end && idx == it->size()) 
        {
            it++;
            idx = 0;
        }
        return it != end;
    }
private:
    vector<vector<int>>::iterator it;
    vector<vector<int>>::iterator end;
    int idx;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */