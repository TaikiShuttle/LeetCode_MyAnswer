#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len_1 = nums1.size();
        int len_2 = nums2.size();
        int left = (len_1 + len_2 +  1) / 2;
        int right = (len_1 + len_2 + 2) / 2;
        // if odd, left and right will be the same; else left = right - 1; thus, if the sum is even, we will get the centering 2 buckets

        return ((findposK(nums1, 0, len_1 - 1, nums2, 0, len_2 - 1, left) + findposK(nums1, 0, len_1 - 1, nums2, 0, len_2 - 1, right)) / 2);
    }
    
    double findposK(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
        int len_1 = end1 - start1 + 1;
        int len_2 = end2 - start2 + 1;
        if (len_1 > len_2) return (findposK(nums2, start2, end2, nums1, start1, end1, k));
        if (len_1 == 0) return nums2[start2 + k - 1];

        // base case
        if (k == 1) return fmin(nums1[start1], nums2[start2]);

        // if the length of the array is less than half of k, just look at the tail, else look at half of k
        int i = start1 + fmin(len_1, k/2) - 1;
        int j = start2 + fmin(len_2, k/2) - 1;
        if (nums1[i] > nums2[j]) return (findposK(nums1, start1, end1, nums2, j + 1, end2,  k - (j - start2 + 1)));
        else return (findposK(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1)));

            
    }
}sol;

int main() {
    vector<int> * arr1 = new vector<int>{1,2,3};
    vector<int> * arr2 = new vector<int>{4,5,6};
    double answer = sol.findMedianSortedArrays(*arr1, *arr2);
    cout<<answer<<endl;
    delete arr1;
    delete arr2;
    return 0;
}