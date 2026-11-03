// 153FindMinimumInRotatedSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <math.h>
int findMin(std::vector<int>& nums) 
{   
    int leftPtr = 0;
    int RightPtr = nums.size() - 1;
    while((RightPtr-leftPtr) >= 2)
    {
        int mid = (RightPtr + leftPtr) / 2;

        if (nums[leftPtr] > nums[mid])
        {
            RightPtr = mid;
        }

        else if (nums[RightPtr] < nums[mid])
        {
            leftPtr = mid;
        }

        else {
            return nums[leftPtr];
        }

    }
    return std::min(nums[leftPtr], nums[RightPtr]);
}

int main()
{
    std::vector<int> num = { 4,5,6,7,0,1,2 };
    std::cout << findMin(num);
    
}

