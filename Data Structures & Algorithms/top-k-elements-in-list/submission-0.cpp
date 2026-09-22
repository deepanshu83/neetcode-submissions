class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> frequency;

        // 1. Count frequency
        for (int num : nums) {
            frequency[num]++;
        }

        // 2. Create buckets
        vector<vector<int>> buckets(nums.size() + 1);

        // 3. Put numbers into frequency buckets
        for (const auto& [num, count] : frequency) {
            buckets[count].push_back(num);
        }

        vector<int> result;

        // 4. Traverse from highest frequency
        for (int freq = nums.size(); freq >= 1; freq--) {

            for (int num : buckets[freq]) {

                result.push_back(num);

                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};