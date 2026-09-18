class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long countAtLeast(string word, int k) {
        unordered_map<char, int> freq;

        int left = 0;
        int consonants = 0;
        long long ans = 0;

        for (int right = 0; right < word.size(); right++) {

            if (isVowel(word[right])) {
                freq[word[right]]++;
            } else {
                consonants++;
            }

            while (consonants >= k && freq.size() == 5) {

                if (isVowel(word[left])) {
                    freq[word[left]]--;

                    if (freq[word[left]] == 0) {
                        freq.erase(word[left]);
                    }
                } else {
                    consonants--;
                }

                left++;
            }

            ans += left;
        }

        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return countAtLeast(word, k) - countAtLeast(word, k + 1);

    }
};