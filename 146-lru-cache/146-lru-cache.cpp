// METHOD 1
class LRUCache {
public:
    class node{
        public:
            int key;
            int val;
            node *next;
            node *prev;
         
        node(int k, int v){
            key = k;
            val = v;
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int,node*> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node* newNode)
    {// temp is a node that head's next points previously So in between head and temp we insert newNode
        node* temp = head->next;
	    
        newNode->next = temp;
        newNode->prev = head;
	    
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deleteNode(node* delNode){
        node* delprev = delNode->prev;
        node* delnext = delNode->next;
        
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int k) 
    {   // searching the key in map
        if(mp.find(k) != mp.end())
        {
            node* resNode = mp[k]; // taking node address
            int temp = resNode->val; // taking node value
            // erase the key from map as it is the old addres of node
            mp.erase(k);
            // now delete the old resNode form DLL as it is now LRU so new address is to be inserted
            deleteNode(resNode); 
            addNode(resNode);// add in DLL as it is LRU
            
            mp[k] = head->next; //reassign i.e add new address in map
            return temp; // return the res for the key
        }
        return -1;
    }
    
    void put(int k, int value) 
    {
        // key is present in map
        if(mp.find(k) != mp.end())
        {
            node* existNode = mp[k]; // get its node from map
            mp.erase(k); //first erase it from map
            deleteNode(existNode); // delete it from DLL
        }
        // if capacity is full in map
        if(cap == mp.size())
        {
            mp.erase(tail->prev->key); // first erase it from map
            deleteNode(tail->prev); // delete it from DLL
        }
        addNode(new node(k,value)); // add it to DLL
        mp[k] = head->next; ////reassign i.e add new address in map for resently used map
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
