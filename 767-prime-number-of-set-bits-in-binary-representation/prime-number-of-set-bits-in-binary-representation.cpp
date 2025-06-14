class Solution {
public:
    bool isPrime(int n) {
        return n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19;
    }
    
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }

    int countPrimeSetBits(int left, int right) {
        int result = 0;
        for (int i = left; i <= right; ++i) {
            int bits = hammingWeight(i);
            if (isPrime(bits)) result++;
        }
        return result;
    }
};
