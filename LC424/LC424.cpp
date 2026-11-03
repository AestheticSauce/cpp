// LC424.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <math.h>
#include<unordered_map>
int characterReplacement(std::string s, int k) 
{

    int rightPtr = 0;
    int leftPtr = 0; 
    int alphabetCount = 0;
    int maxWindowSize = 0;
    std::vector<int> characterArr(26,0);

    for(;rightPtr < s.size();rightPtr++)
    {
        if (s[rightPtr] - 65 >= 0) 
        {
            characterArr[s[rightPtr] - 65] = characterArr[s[rightPtr] - 65] + 1;
            alphabetCount = std::max(alphabetCount, characterArr[s[rightPtr] - 65]);
            int windowSize = rightPtr - leftPtr;
            
            if ((rightPtr-leftPtr+1) - alphabetCount > k)
            {
                maxWindowSize = std::max(maxWindowSize, windowSize);
                characterArr[s[leftPtr] - 65] = characterArr[s[leftPtr] - 65] - 1;
                leftPtr++;

                for (int i = 0; i < characterArr.size();i++)
                {
                     alphabetCount = std::max(alphabetCount, characterArr[i]);
                }
            }
        }
    }
    return std::max(rightPtr - leftPtr,maxWindowSize);
}

int main()
{
    std::cout << characterReplacement("AABABBA", 1) << std::endl;

}



