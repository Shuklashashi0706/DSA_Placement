// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size() - 1;
        int start = *max_element(nums.begin(), nums.end());
        int end = reduce(nums.begin(), nums.end());
        int ans;
        while (start <= end)
        {
            int mid = end + (start - end) / 2;
            int page = 0;
            int count = 1;
            for (int i = 0; i <= n; i++)
            {
                page += nums.at(i);
                if (page > mid)
                {
                    count++;
                    page = nums.at(i);
                }
            }
            if (count <= k)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    class Solution obj;
    vector<int> nums{10, 20, 30, 40};
    int ans = obj.splitArray(nums, 3);
    cout << ans << endl;
    return 0;
}