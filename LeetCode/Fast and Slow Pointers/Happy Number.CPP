class Solution {
public:
    int squareNo(int n) {
        int sum = 0;
        while (n > 0) {
            int r = n % 10;
            n = n / 10;
            sum += r * r;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;
        while (true) {
            slow = squareNo(slow);                 // move slow one step
            fast = squareNo(squareNo(fast));       // move fast two steps

            if (fast == 1) return true;            // fast reached 1 → happy number
            if (slow == fast) return false;        // cycle detected → not happy
        }
    }
};