class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        int ans = 1;
        if (freq.count(1)) {
            int cnt = freq[1];

            if (cnt % 2 == 0)
                ans = max(ans, cnt - 1);
            else
                ans = max(ans, cnt);
        }

        for (auto &[value, count] : freq) {
            if (value == 1) continue;

            long long x = value;
            int len = 0;

            while (freq.count(x) && freq[x] >= 2) {
                len += 2;
                x = x * x;

                if (x > 1e18) break;
            }

            if (freq.count(x)) {
                len++;
            } 
            else {
    
                len--;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};