// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<char> chars = { 'a','a','a','b','b','b','b'};
    std::vector<char> str;
    char curr = chars[0];
    int count = 0;
    int size = chars.size();

    std::string countAsString = std::to_string(123456);
    int x = 0;

    for (char c : countAsString) 
    {
        str.insert(str.begin() + x, c);
        x++;
    }
    for (int i = 0; i < str.size(); i++) 
    {
        std::cout << str[i] << std::endl;
    }
    //for (int i = 1; i < size; ++i) {
    //    if (curr != chars[i]) {
    //        std::string countAsString = std::to_string(count);
    //        for (;;);
    //        count = 0;   
    //    }
    //    count++;
    //}

}

