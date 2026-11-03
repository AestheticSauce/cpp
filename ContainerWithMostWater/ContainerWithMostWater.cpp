// ContainerWithMostWater.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <math.h>
int maxArea(std::vector<int> height)
{
	int firstIdx = 0;
	int lastIdx = height.size() - 1;
	int maxArea = 0;

	while (firstIdx<lastIdx)
	{


		int area = std::min(height[firstIdx], height[lastIdx]) * (lastIdx-firstIdx);
		maxArea = std::max(maxArea, area);

		if (height[firstIdx] > height[lastIdx])
		{
			lastIdx--;
		}
		else if (height[lastIdx] > height[firstIdx])
		{
			firstIdx++;
		}
		else {
			lastIdx--;
		}

	}
	return maxArea;
}

int main()
{
	std::vector<int> heights = { 1,8,6,2,5,4,8,3,7 };
	std::cout << maxArea(heights) << std::endl;
}
