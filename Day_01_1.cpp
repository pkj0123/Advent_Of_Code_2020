#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printArray(int arr[], int size);
void quickSort (int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
  /*
  //create and open a text file
  ofstream OutputFile("output.txt");

  //write to the file
  OutputFile << "test output :< \ntest";

  //close the file
  OutputFile.close();
  */

  string inputStr;
  const int maxArraySize = 512;
  int array[maxArraySize];
  int arraySize = 0;
  int sum = 2020;

  //read from text file
  ifstream InputFile("Day_01_input.txt");
  while (getline (InputFile, inputStr))
  {
    //cout << inputStr << "\n";
    array[arraySize] = stoi(inputStr);
    arraySize++;
  }
  InputFile.close();

  //find the 2 entries that sum to 2020
  //then multiply them together

  /*
  printArray(array, arraySize);
  quickSort(array, 0, arraySize - 1);
  cout << "\n Sorted Array \n";
  printArray(array, arraySize);
  */

  for (int i = 0; i < arraySize; i++)
  {
    if (array[i] > sum)
    {
      continue;
    }

    for (int j = i + 1; j < arraySize; j++)
    {
      if (array[i] + array[j] == sum)
      {
        cout << array[i] << " + " << array[j] << " = 2020\n";
        cout << array[i] << " * " << array[j] << " = " << array[i] * array[j];
        break;
      }
    }
  }

  return 0;
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
}

/*
void quickSort (int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int partition(int arr[], int low, int high)
{
  //set pivot to be the last element
  int pivot = arr[high];

  //start from low - 1 because i will be incremented when swapping
  int i = low--;
  for (int j = low; j <= high; j++)
  {
    //if current elelement is smaller than pivot
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  //sort the pivot
  swap(arr[i+1], arr[high]);

  return (i + 1);
}
*/
