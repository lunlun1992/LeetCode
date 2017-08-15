//这题的思路是找到两个第k大，然后平均
//首先要假定左边小于右边，另外k除以二的边界无所谓，反正可以舍去。
#define min(a, b) ((a) < (b) ? (a) : (b))
int findkth(int* n1, int len1, int *n2, int len2, int k) {
    if (len1 > len2)
        return findkth(n2, len2, n1, len1, k);
    if (len1 == 0)
        return n2[k - 1];
    if (k == 1)
        return min(n1[0], n2[0]);
    int i1 = min(len1, k >> 1);
    int i2 = min(len2, k >> 1);
    if (n1[i1 - 1] < n2[i2 - 1])
        return findkth(n1 + i1, len1 - i1, n2, len2, k - i1);
    else
        return findkth(n1, len1, n2 + i2, len2 - i2, k - i2);
}


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int r1 = findkth(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size + 1) >> 1);
    int r2 = findkth(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size + 2) >> 1);
    return (r1 + r2) / 2.0;
}