class Solution {
public:
    long long countPages(vector<int> &arr, long long pages){
            long long stu = 1;
            long long sum = 0;
            for (int x : arr) {
                if (sum + x <= pages) {
                    sum += x;
                } else {
                    stu++;
                    sum = x;
                }
            }
            return stu;
        }
        int findPages(vector<int> &arr, int k) {
            int n = arr.size();
            if (k > n) return -1;
            long long l = *max_element(arr.begin(), arr.end());
            long long h = accumulate(arr.begin(), arr.end(), 0LL);
            while (l <= h) {
                long long mid = l + (h - l) / 2;
                long long st = countPages(arr, mid);
                if (st > k)
                    l = mid + 1;
                else
                    h = mid - 1;
            }
            return (int)l;
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,k);
    }
};