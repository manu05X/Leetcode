class MyCalendar {
public:
    unordered_map<int,int> mp;
    MyCalendar() {
    }
    
    bool book(int start1, int end1) {
        for(auto& [start2,end2] : mp)
        {
            if(!(start1 >= end2 || start2 >= end1))
            {
                return false;
            }
        }
        mp[start1] = end1;
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */