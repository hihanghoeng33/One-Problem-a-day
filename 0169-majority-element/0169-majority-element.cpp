class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = findCandidate(nums);
        // Confirm the candidate is a majority element
        if (isMajor(candidate, nums)) {
            return candidate;
        }
        return -1; 
    }

private:
    // First step: Find a potential majority candidate
    int findCandidate(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }

    // Second step: Verify if the candidate is actually the majority element
    bool isMajor(int candidate, vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            if (num == candidate) {
                count++;
            }
        }

        return count > nums.size() / 2;
    }
};
