#include <iostream>
#include <vector>
using namespace std;

//第一题，两数之和
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res={0,0};
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            if (nums[i]+nums[j]==target&&i!=j)
            {
                res={i,j};
                break;
            }
        }
    }
    return res;
}

int main() {
    return 0;
}
