public class Solution {
    public void Merge(int[] nums1, int m, int[] nums2, int n) {
        nums2.CopyTo(nums1, n > 0 ? m : 0);
        Array.Sort(nums1);
    }
}