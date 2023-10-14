#include <bits/stdc++.h>
using namespace std;

class MountainArray {
  public:
    int get(int index);
    int length();
};


class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0;
        int r = mountainArr.length() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (mountainArr.get(l) == target) {
            return l;
        }
        int peak = l;
        l = 0;
        r = peak;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mountainArr.get(mid) == target) {
                return mid;
            } else if (mountainArr.get(mid) < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        l = peak;
        r = mountainArr.length();
        while (l < r) {
            int mid = (l + r) / 2;
            if (mountainArr.get(mid) == target) {
                return mid;
            } else if (mountainArr.get(mid) < target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};

int main() {

    return 0;
}