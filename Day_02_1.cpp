#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;

struct pass_data
{
  int min_freq = 0;
  int max_freq = 0;
  char alphabet;
  string password;
};

void printPassData(vector<pass_data> vect)
{
  for (int i = 0; i < vect.size(); i++)
  {
    cout << vect[i].min_freq << "-" << vect[i].max_freq << " " << vect[i].alphabet << " " << vect[i].password << "\n";
  }
}

pass_data getData(string inputStr)
{
  pass_data data;
  string rangeStr;
  string alphStr;
  string passStr;

  //split string
  rangeStr = inputStr.substr(0, inputStr.find(' '));
  inputStr.erase(0, inputStr.find(' ') + 1);
  alphStr = inputStr.substr(0, inputStr.find(' '));
  inputStr.erase(0, inputStr.find(' ') + 1);
  passStr = inputStr.substr(0, inputStr.find(' '));

  //read range
  bool isReadingMax = false;
  for (int i = 0; i < rangeStr.length(); i++)
  {
    if (isdigit(rangeStr[i]) && !isReadingMax)
    {
      data.min_freq *= 10;
      data.min_freq += rangeStr[i] - '0';
    }
    else if (isdigit(rangeStr[i]) && isReadingMax)
    {
      data.max_freq *= 10;
      data.max_freq += rangeStr[i] - '0';
    }
    else
    {
      //this is a hyphen
      isReadingMax = true;
    }
  }

  //read alphabet
  data.alphabet = alphStr[0];

  //read password
  data.password = passStr;

  return data;
}

int main()
{
  vector<pass_data> passVector;
  string inputStr;
  int i = 0;

  //read from text file
  ifstream InputFile("Day_02_input.txt");
  while (getline (InputFile, inputStr))
  {
    //read input string
    //cout << "Read: " << inputStr << "\n";

    pass_data data = getData(inputStr);

    passVector.push_back(data);
  }
  InputFile.close();

  //printPassData(passVector);

  int count = 0;
  for (int i = 0; i < passVector.size(); i++)
  {
    pass_data data = passVector[i];
    int occurance = 0;

    //count the number of occurances
    for (int j = 0; j < passVector[i].password.size(); j++)
    {
      if (data.password[j] == data.alphabet)
      {
        occurance++;
      }
    }

    if (occurance >= data.min_freq && occurance <= data.max_freq)
    {
      count++;
    }
  }

  cout << "Count: " << count << "\n";

  return 0;
}
