class MyHashMap {
    vector<list<pair<int, int>>> buckets;
    int size = 10000;
public:
    MyHashMap() {
        buckets.resize(size);
    }
    
    void put(int key, int value) {
        int bucket_no = key % size;
        auto &chain = buckets[bucket_no];

        for(auto &p : chain){
            if(p.first == key){
                p.second = value;
                return;
            }
        }
        chain.push_back({key, value});
    }
    
    int get(int key) {
        int bucket_no = key % size;
        auto &chain = buckets[bucket_no];

        for(auto &p : chain){
            if(p.first == key){
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int bucket_no = key % size;
        auto &chain = buckets[bucket_no];

        for(auto i = chain.begin(); i != chain.end(); i++){
            if(i->first == key){
                chain.erase(i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */