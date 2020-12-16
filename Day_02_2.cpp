#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;

struct pass_data
{
  int pos1 = 0;
  int pos2 = 0;
  char alphabet;
  string password;
};

void printPassData(vector<pass_data> vect)
{
  for (int i = 0; i < vect.size(); i++)
  {
    cout << vect[i].pos1 << "-" << vect[i].pos2 << " " << vect[i].alphabet << " " << vect[i].password << "\n";
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
      data.pos1 *= 10;
      data.pos1 += rangeStr[i] - '0';
    }
    else if (isdigit(rangeStr[i]) && isReadingMax)
    {
      data.pos2 *= 10;
      data.pos2 += rangeStr[i] - '0';
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
    bool hit = false;

    //check positions
    if (data.password[data.pos1 - 1] == data.alphabet)
    {
      hit = !hit;
    }

    if (data.password[data.pos2 - 1] == data.alphabet)
    {
      hit = !hit;
    }

    if (hit)
    {
      count++;
    }
  }

  cout << "Count: " << count << "\n";

  return 0;
}
