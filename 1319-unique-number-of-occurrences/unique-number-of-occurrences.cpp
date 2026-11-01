class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
         unordered_map<int, int> freq;
        unordered_set<int> seen;

        for(int num : arr) {
            freq[num]++;
        }

        for(auto it : freq) {
            if(seen.find(it.second) != seen.end()) {
                return false;
            }

            seen.insert(it.second);
        }

        return true;
    }
};