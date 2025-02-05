#include <vector>
#include <algorithm> // For std::sort

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        std::vector<int> mergedList;  // Corrected typo: mergedList

        // Merge the two sorted arrays
        for (int i = 0; i < m; i++) {  // Corrected loop condition
            mergedList.push_back(nums1[i]);
        }

        for (int j = 0; j < n; j++) {  // Corrected loop condition
            mergedList.push_back(nums2[j]);
        }

        // Sort the merged list
        std::sort(mergedList.begin(), mergedList.end());

        // Find the median
        int totalSize = mergedList.size();
        if (totalSize % 2 == 1) {
            return mergedList[totalSize / 2];  // Odd length, return the middle element
        } else {
            return (mergedList[totalSize / 2 - 1] + mergedList[totalSize / 2]) / 2.0;  // Even length, return the average of the two middle elements
        }
    }
};
