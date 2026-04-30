class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> cars;

        for (int i = 0; i < position.size(); i++) {
            double timeToDest = (double)(target - position[i]) / (double)speed[i];
            cars[-position[i]] = timeToDest;
        }

        int fleets = 1;
        double lastTime = -1;
        for (const auto& car : cars) {
            double curTime = car.second;
            cout << "cur: " << to_string(curTime) << ", last: " << to_string(lastTime);
            if (lastTime == -1) {
                lastTime = car.second;
                continue;
            }

            if (curTime > lastTime) {
                fleets++;
                lastTime = curTime;
                cout << ", fleets: " << to_string(fleets);
            }

            cout << "\n";
        }

        return fleets;
    }
};

// 17
// 10   9     9     6    7

// 16   12    11    8    7
// 0.1  0.56  0.67  1.5  1.428

