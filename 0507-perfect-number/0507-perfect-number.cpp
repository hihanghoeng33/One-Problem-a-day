class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1)
            return false;

        int sumOfDivisors = 1; // Initialize with 1 (since 1 is always a divisor)

        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                sumOfDivisors += i;
                if (i != num / i) // Avoid counting the same divisor twice
                    sumOfDivisors += num / i;
            }
        }

        return sumOfDivisors == num;
    }
};
