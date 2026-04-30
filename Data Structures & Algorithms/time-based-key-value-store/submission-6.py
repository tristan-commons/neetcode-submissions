class TimeMap:
    data_map = {}

    def __init__(self):
        self.data_map = {}
        return

    def set(self, key: str, value: str, timestamp: int) -> None:
        if self.data_map.get(key):
            self.data_map[key].append([value, timestamp])
        else:
            self.data_map[key] = [[value, timestamp]]

    def get(self, key: str, timestamp: int) -> str:
        arr = self.data_map.get(key)
        if arr:
            result = self.search_arr(arr, timestamp)
            print("Result: " + str(result))
            return result
        return ""
    
    def search_arr(self, arr: list, timestamp: int) -> str:
        l = 0
        r = len(arr) - 1
        closest = ""
        closest_diff = 9999999
        print(arr)

        while l <= r:
            mid = l + (r - l) // 2

            print("l: " + str(l) + ", m: " + str(mid) + ", r: " + str(r))

            if arr[mid][1] == timestamp:
                return arr[mid][0]

            if arr[mid][1] < timestamp:
                diff = timestamp - arr[mid][1]
                if diff < closest_diff:
                    closest = arr[mid][0]
                    closest_diff = diff
                l = mid + 1
            
            if arr[mid][1] > timestamp:
                r = mid - 1
        
        return closest
