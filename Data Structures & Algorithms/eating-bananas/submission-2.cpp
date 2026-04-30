class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int sum = 0;
        int maxK = 0;

        for (int i = 0; i < n; i++) {
            maxK = max(maxK, piles[i]);
            sum += piles[i];
        }

        int minK = 1;
        int curBest = maxK;
        int curBestHours = sum;
        while (minK <= maxK) {
            int mid = minK + (maxK - minK) / 2;
            int hours = getHours(piles, mid);

            if (hours <= h) {
                if (mid < curBest) {
                    curBestHours = hours;
                    curBest = mid;
                }
                maxK = mid - 1;
            } else {
                minK = mid + 1;
            }
        }

        return curBest;
    }

    int getHours(vector<int>& piles, int k) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += piles[i] / k;
            hours += piles[i] % k > 0 ? 1 : 0;
        }
        return hours;
    }
};
