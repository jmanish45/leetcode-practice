class Solution {
public:
    double halfarea;

    bool check(double y, const vector<vector<int>>& squares) {
        double area = 0.0;

        for (const auto& square : squares) {
            double bottom = square[1];
            double side = square[2];
            double top = bottom + side;

            if (y <= bottom) continue;

            if (y >= top)
                area += side * side;
            else
                area += (y - bottom) * side;

            
            if (area >= halfarea)
                return true;
        }
        return false;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double total = 0.0;
        double lo = 1e18, hi = -1e18;

        for (const auto& square : squares) {
            double side = square[2];
            total += side * side;
            lo = min(lo, (double)square[1]);
            hi = max(hi, (double)square[1] + side);
        }

        halfarea = total / 2.0;

        
        for (int i = 0; i < 45; i++) {
            double mid = (lo + hi) / 2.0;
            if (check(mid, squares))
                hi = mid;
            else
                lo = mid;
        }

        return (lo + hi) / 2.0;
    }
};
