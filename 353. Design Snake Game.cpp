class SnakeGame {
public:
    using P = pair<int, int>;
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) 
    {
        this->width = width;
        this->height = height;
        this->food = food;
        dq.push_back(P(0, 0));
        st.insert(0);
        curfood = 0;
        size = 1;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) 
    {
        //1.下一步是否越界，不越界的话deque加入本点
        int curposx = dq.front().first;
        int curposy = dq.front().second;
        int nextposx = curposx;
        int nextposy = curposy;
        switch(direction[0])
        {
        case 'U':
            nextposx--;
            break;
        case 'D':
            nextposx++;
            break;
        case 'L':
            nextposy--;
            break;
        case 'R':
            nextposy++;
            break;
        }
        if(nextposx < 0 || nextposx >= height || nextposy < 0 || nextposy >= width)
            return -1;
        dq.push_front(P(nextposx, nextposy));
        
        //2.是否有食物，有食物吃掉
        if(curfood < food.size() && food[curfood].first == nextposx && food[curfood].second == nextposy)
        {
            size++;
            curfood++;
        }
        
        //3.维护deque
        if(dq.size() != size)
        {
            st.erase(dq.back().first * width + dq.back().second);
            dq.pop_back();
        }
        
        //4.是否撞上自己，有则return -1
        if(st.count(nextposx * width + nextposy))
            return -1;
        
        //5.维护set
        st.insert(nextposx * width + nextposy);
        
        //6.结束，return curfood
        return curfood;
    }
private:
    int width;
    int height;
    int curfood;
    int size;
    deque<P> dq;
    unordered_set<int> st;
    vector<P> food;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */