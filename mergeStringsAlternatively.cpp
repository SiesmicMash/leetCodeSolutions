#include <string>
using std::string;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int len1 = word1.size();
        int len2 = word2.size();
        int minLen = len1 < len2 ? len1 : len2;

        // Reserve space for the final result to avoid repeated allocations
        result.reserve(len1 + len2);

        // Interleave characters up to the length of the shorter word
        for (int i = 0; i < minLen; ++i) {
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }

        // Append the remaining part of the longer word
        if (len1 > len2) {
            result.append(word1.begin() + minLen, word1.end());
        } else if (len2 > len1) {
            result.append(word2.begin() + minLen, word2.end());
        }

        return result;
    }
};
