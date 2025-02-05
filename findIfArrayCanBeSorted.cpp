#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    // Function to count the number of set bits in an integer
    int countSetBits(int num) {
        return __builtin_popcount(num); // Optimized for GCC/Clang
    }

    bool canSortArray(std::vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 1) return true;  // A single element or empty array is trivially sorted
        
        // Step 1: Traverse the array to split into segments of consecutive elements with the same number of set bits
        std::vector<std::vector<int>> segments;
        std::vector<int> currentSegment;
        int currentBitCount = countSetBits(nums[0]);
        
        for (int i = 0; i < n; ++i) {
            int bitCount = countSetBits(nums[i]);
            if (bitCount == currentBitCount) {
                currentSegment.push_back(nums[i]);
            } else {
                // Push the current segment and start a new one
                segments.push_back(currentSegment);
                currentSegment = {nums[i]};
                currentBitCount = bitCount;
            }
        }
        // Don't forget to push the last segment
        if (!currentSegment.empty()) {
            segments.push_back(currentSegment);
        }
        
        // Step 2: Check if the largest element of the previous segment is smaller than the smallest element of the next segment
        for (int i = 1; i < segments.size(); ++i) {
            int prevSegmentMax = *std::max_element(segments[i-1].begin(), segments[i-1].end());
            int currSegmentMin = *std::min_element(segments[i].begin(), segments[i].end());
            if (prevSegmentMax >= currSegmentMin) {
                return false;
            }
        }
        
        return true;
    }
};
