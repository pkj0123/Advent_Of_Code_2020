#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> vect)
{
  for (int i = 0; i < vect.size(); i++)
  {
    cout << vect[i] << " ";
  }
}

int main()
{
  string inputStr;
  const int maxArraySize = 512;
  int sum = 2020;
  vector<int> inputVector;
  bool found = false;

  //read from text file
  ifstream InputFile("Day_01_input.txt");
  while (getline (InputFile, inputStr))
  {
    inputVector.push_back(stoi(inputStr));
  }
  InputFile.close();

  sort(inputVector.begin(), inputVector.end());
  printVector(inputVector);

  int digit1 = 0, digit2 = 0, digit3 = 0;
  for (int i = 0; i < inputVector.size(); i++)
  {
    if (inputVector[i] > sum)
    {
      //skip this iteration
      continue;
    }

    int targetSum = sum - inputVector[i];
    int lastIndex = inputVector.size() - 1;
    for (int j = i + 1; j < lastIndex;)
    {
      if (inputVector[j] > targetSum)
      {
        //smallest number is more than targetSum
        cout << "\nSmallest available number is " << inputVector[j] << " which is greater than " << targetSum;
        break;
      }
      if (inputVector[j] + inputVector[lastIndex] == targetSum)
      {
        //found
        digit2 = inputVector[j];
        digit3 = inputVector[lastIndex];
        cout << "\n" << j << " " << lastIndex;
        found = true;
        break;
      }
      else if (inputVector[j] + inputVector[lastIndex] < targetSum)
      {
        //need a bigger number
        j++;
      }
      else
      {
        //need a smaller number
        lastIndex--;
      }
    }

    if (found)
    {
      digit1 = inputVector[i];
      cout << "\n" << digit1 << " + " << digit2 << " + " << digit3 << " = " << sum << "\n";
      cout << "Multiple of those digit is: " << digit1*digit2*digit3;
      break;
    }
  }

  return 0;
}
