// 69. Sqrt(x)

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;

        int s = 1;
        int e = x;

        while (s <= e) {
            int m = s + (e - s) / 2;
            if (m == x / m) {
                return m;
            } else if (m > x / m) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        }

        return e;
    }
};
