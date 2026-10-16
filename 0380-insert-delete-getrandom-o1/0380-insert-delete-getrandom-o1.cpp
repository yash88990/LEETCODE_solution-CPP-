class RandomizedSet {
public:
    unordered_map<int,int> ans;
    vector<int>nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(ans.find(val) != ans.end())return false;
        else{
            nums.push_back(val);
            ans[val] = nums.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(ans.find(val) == ans.end()){
            return false;
        }
        int last = nums.back();
        int index = ans[val];

        nums[index] = last;
        ans[last] = index;

        nums.pop_back();
        ans.erase(val);
        return true;

    }
    
    int getRandom() {
        int randindex = rand() % nums.size();
        return nums[randindex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */