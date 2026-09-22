class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> frequency;

        // 1. Count frequency
        for (int num : nums) {
            frequency[num]++;
        }

        using Pair = pair<int, int>;

        // 2. Min Heap
        priority_queue<
            Pair,
            vector<Pair>,
            greater<Pair>
        > minHeap;

        // 3. Maintain K most frequent elements
        for (const auto& [num, count] : frequency) {

            minHeap.push({count, num});

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;

        // 4. Extract elements
        while (!minHeap.empty()) {

            result.push_back(minHeap.top().second);

            minHeap.pop();
        }

        return result;
    }
};