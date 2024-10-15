// https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {
    vector<int>_nums;
    unordered_map<int,int>_position;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(_position.find(val)!=_position.end())
            return false;
        _nums.push_back(val);
        _position[val] = _nums.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(_position.find(val)==_position.end())
            return false;
        int pos = _position[val];
        _nums[pos] = _nums[_nums.size()-1];
        _position[_nums[pos]] = pos ; 
        _nums.pop_back();
        _position.erase(val);
        return true;
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return _nums[rand()%_nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */