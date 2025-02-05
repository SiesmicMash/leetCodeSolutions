#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;  // Store value and index of each element
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            // Check if the complement exists in the map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            // Add the current number and its index to the map
            numMap[nums[i]] = i;
        }
        // Return empty vector if no solution is found
        return {};
    }
};
