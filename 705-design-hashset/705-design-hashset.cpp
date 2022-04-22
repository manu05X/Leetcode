class MyHashSet {
    int numBuckets;
    vector<vector<int>> buckets;
    
    private: int hashFunction(int key){
        return key%numBuckets;
    }
public:
    MyHashSet() {
        numBuckets = 15000;
        buckets = vector<vector<int>> (numBuckets, vector<int>{});
    }
    
    void add(int key) {
        int i = hashFunction(key);
        
        if(find(buckets[i].begin(), buckets[i].end(), key) == buckets[i].end()){
            buckets[i].push_back(key);
        }
    }
    
    void remove(int key) {
        int i = hashFunction(key);
        
        auto it = find(buckets[i].begin(), buckets[i].end(), key);
        if(it != buckets[i].end())
            buckets[i].erase(it);
    }
    
    bool contains(int key) {
        int i = hashFunction(key);
        
        if(find(buckets[i].begin(), buckets[i].end(), key) == buckets[i].end()){
            return false;
    }
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */