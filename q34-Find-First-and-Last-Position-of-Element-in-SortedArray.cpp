/*

1. Use Binary Search to Find the target
2. Expand Higher bound
3. Expand Lower bound

*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;

        while(l <= h) {
            int mid = l + (h - l) / 2;
            //1. Use Binary Search to Find the target 
            if( nums[mid] == target ) {
                int low = mid;
                int high = mid;

                // find higher
                int x = mid + 1;
                int y = h;

                // 2. Expand Higher bound
                while(x <= y) {
                    int z =  x + (y - x) /2;
                    if(nums[z] == target) {
                        high = z;
                        x = z + 1;
                    } else { 
                        //num[z] > target 
                        //num[z] < target is not possible
                        y = z - 1;
                    } 
                }

                // 3. Expand Lower bound
                x = l;
                y = mid - 1;

                while(x<=y) {
                    int z =  x + (y - x) /2;
                    if(nums[z] == target) {
                        low = z;
                        y = z - 1;
                    } else { 
                        //num[z] < target 
                        //num[z] > target is not possible
                        x = z + 1;
                    } 
                }
                return vector<int> {low, high};

            } else if (target > nums[mid]) {
                l = mid + 1;
            } else { // target < nums[mid] 
                h = mid - 1;
            }
        }
        return vector<int> {-1, -1};
    }
};