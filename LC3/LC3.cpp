// LC3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
int lengthOfLongestSubstring(std::string s)
{
	std::unordered_map<char, int> charDup;
	if (s.length() > 1) {
		int leftPtr = 0;
		int rightPtr = leftPtr + 1;

		charDup.insert({ s[leftPtr],1 });

		int maxSubStringCount = 0;
		int currentSubStringCount = maxSubStringCount;

		while (rightPtr < s.length())
		{
			if (charDup.contains(s[rightPtr]))
			{

				currentSubStringCount = rightPtr - leftPtr;
				while (charDup.find(s[rightPtr]) != charDup.end()) {
					charDup.erase(s[leftPtr]);
					leftPtr++;
				}
				charDup.insert({ s[rightPtr],1 });
				maxSubStringCount = std::max(maxSubStringCount, currentSubStringCount);

			}
			else
			{
				charDup.insert({ s[rightPtr],1 });
			}
			rightPtr++;
		}

		return std::max(maxSubStringCount, rightPtr - leftPtr);
	}
	else if (s.length() == 1)
	{
		return 1;
	}
	else {
		return 0;
	}
}


int main()
{
	std::string s = "eea";
	std::cout << lengthOfLongestSubstring(s);
}

