/*
Problem: Median of Two Sorted Arrays
Platform: LeetCode
Difficulty: Hard
Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

Approach 1: Merge Technique
- Merge both sorted arrays into a single sorted array
- If total size is odd → return middle element
- If even → return average of two middle elements

Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;

        vector<int> merged(n);

        int p1 = 0, p2 = 0, p = 0;

        // Merge both arrays
        while (p1 < n1 && p2 < n2) {
            if (nums1[p1] < nums2[p2])
                merged[p++] = nums1[p1++];
            else
                merged[p++] = nums2[p2++];
        }

        // Remaining elements
        while (p1 < n1)
            merged[p++] = nums1[p1++];

        while (p2 < n2)
            merged[p++] = nums2[p2++];

        // Find median
        if (n % 2 != 0)
            return merged[n / 2];

        return (merged[n/2 - 1] + merged[n/2]) / 2.0;
    }
};
