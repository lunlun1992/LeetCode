#define MIN(a,b) (a) < (b) ? (a) : (b)
int findKth(int *nums1, int len1, int *nums2, int len2, int k)
{
    //assume len1 <= len2
    if(len1 > len2)
        return findKth(nums2, len2, nums1, len1, k);
    if(len1 == 0)
        return nums2[k - 1];
    if(k == 1)
        return MIN(nums1[0], nums2[0]);
        
    int i1 = MIN(len1, k / 2);
    int i2 = MIN(len2, k / 2);
    if(nums1[i1 - 1] < nums2[i2 - 1])
        return findKth(nums1 + i1, len1 - i1, nums2, len2, k - i1);
    else
        return findKth(nums1, len1, nums2 + i2, len2 - i2, k - i2);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int r1 = findKth(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size + 1) >> 1);
    int r2 = findKth(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size + 2) >> 1);
    return (r1 + r2) / 2.0;
}