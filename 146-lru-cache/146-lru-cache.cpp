// METHOD 1
class LRUCache {
public:
    class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val; 
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int, node*>m;
    
    LRUCache(int capacity) {
        cap = capacity;    
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node* resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res; 
        }
    
        return -1;
    }
    
    void put(int key_, int value) {
        if(m.find(key_) != m.end()) {
            node* existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if(m.size() == cap) {
          m.erase(tail->prev->key);
          deletenode(tail->prev);
        }
        
        addnode(new node(key_, value));
        m[key_] = head->next; 
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*<=========================================METHOD 2=============================================================--------------->*/


class LRUCache {
    list<pair<int,int>> cache;
        unordered_map<int,list<pair<int,int>>::iterator> mymap;  //Key, address in dequeue PAIR
        
        void refreshPosition(int key,int value)
        {
            cache.erase(mymap[key]);
            cache.push_front(make_pair(key,value));
            mymap[key] = cache.begin();     //Addr of new position stored in map
        }
    int capacity;
    
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mymap.find(key)!=mymap.end())
        {
            refreshPosition(key,(*mymap[key]).second);
            return (*mymap[key]).second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mymap.find(key)!=mymap.end())
            refreshPosition(key,value);
        else
        {
            //Add to cache
            cache.push_front(make_pair(key,value));
            mymap[key] = cache.begin();
            if(mymap.size()>capacity)
            {
                mymap.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// Method 3

typedef struct Entry_t {
	int address;
	int value;
	Entry_t* next;
	Entry_t* prev;
	Entry_t(int _add, int _val, Entry_t *_next, Entry_t* _prev) :
			address(_add), value(_val), next(_next), prev(_prev) {
	}

} Entry;

class LRUCache {
	int size;
	Entry* head;
	Entry* tail;
	unordered_map<int, Entry*> map;
	int len;

	void evict() { //Depending on policy
		//remove last one
		if (!tail)
			return;
		if (tail->prev)
			tail->prev->next = nullptr;
		else
			//single Entry
			head = nullptr;
		Entry* temp = tail;
		tail = tail->prev;
		//remove from map
		map.erase(temp->address);
		delete temp;
		len--;
	}
public:
    LRUCache(int capacity) :
			size(capacity), head(nullptr), tail(nullptr), len(0) {
	}
    
    int get(int key) {
        auto it = map.find(key);
		if (it == map.end())
			return -1;
		//bring it to front
		Entry* ptr = it->second;
		if (ptr == head)		// nothing to do
			return ptr->value;
		if (ptr->prev)
			ptr->prev->next = ptr->next;
		if (ptr->next)
			ptr->next->prev = ptr->prev;
		else
			tail = ptr->prev;

		//Now put it at the front
		ptr->next = head;
		if (head)
			head->prev = ptr;
		head = ptr;
		return ptr->value;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
		if (it!=map.end()){
			it->second->value = value;
			get(key);
			return;
		}
		//New Entry
		if (len == size)		//full
			evict();
		//Add
		Entry* ptr = new Entry(key, value, nullptr, nullptr);
		ptr->next = head;
		if (head)
			head->prev = ptr;
		head = ptr;
		if (!tail)
			tail = ptr;
		//Add it to the map
		map.insert(make_pair(key, ptr));
		len++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
