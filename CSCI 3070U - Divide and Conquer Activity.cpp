// CSCI 3070U - Divide and Conquer Activity.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int main()
{
    std::cout << "Hello World!\n";
    
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes

void mergeSort(std::vector<float> array) {
    int midpoint = array.size() / 2;
    int endpoint = array.size();
    divide(array, midpoint, endpoint);
}

void divide(std::vector<float> array, int mid, int end)
{
    std::vector<float>firstHalf;
    std::vector<float>secondHalf;

    for (int i = 0; i < (mid + 1); i++)
    {
        firstHalf.push_back(array[i]);
    }
    for (int i = mid; i < end; i++)
    {
        int k = 1;
        secondHalf.push_back(array[mid + k]);
        k++;
    }

    if (firstHalf.size() == 1 || secondHalf.size() == 1)
    {
        merge(firstHalf, secondHalf);
    }
    divide(firstHalf, firstHalf.size() / 2, firstHalf.size());
    divide(secondHalf, secondHalf.size() / 2, secondHalf.size());
}

std::vector<float> merge(std::vector<float> subArr1, std::vector<float> subArr2)
{
    int arrSize1 = subArr1.size();
    int arrSize2 = subArr2.size();
    std::vector<float> merged;

    if (arrSize2 > arrSize1)
    {

    }
    else
    {
        //subArray indices need to increase, NOT i
        for (int i = 0; i < subArr1.size(); i++)
        {
            if (subArr1[i] < subArr2[i])
            {
                merged.push_back(subArr1[i]);
                subArr1.erase(subArr1.begin() + i);
            }
            else
            {
                merged.push_back(subArr2[i]);
                subArr2.erase(subArr1.begin() + i);
            }
        }
    }

    return merged;
}