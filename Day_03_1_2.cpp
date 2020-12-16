#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void printMap(vector<vector<char>> map)
{
  for (int i = 0; i < map.size(); i++)
  {
    for (int j = 0; j < map[0].size(); j++)
    {
      //print x
      cout << map[i][j];
    }
    cout << "\n";
  }
}

int countTrees(vector<vector<char>> map, int incX, int incY)
{
  vector<char> encounters;
  int localx = 0, localy = 0;
  int hit = 0;

  int x = map[0].size();
  int y = map.size();

  do
  {
    char encounter = map[localy][localx];
    //cout << "localx: " << localx << " localy: " << localy << "\n";
    //cout << "encounter: " << encounter << "\n";
    encounters.push_back(encounter);
    localx += incX;
    //localx = 30 should be 30
    //localx = 31 should be 0
    localx = localx % x;
    localy += incY;
  }
  while (localy < y);

  for (int i = 0; i < encounters.size(); i++)
  {
    if (encounters[i] == '#')
    {
      hit++;
    }
  }
  cout << "Hit " << hit << " trees\n";

  return hit;
}

int main()
{
  string inputStr;
  vector<vector<char>> map;

  //read from text file
  ifstream InputFile("Day_03_input.txt");
  while (getline (InputFile, inputStr))
  {
    //read input string
    vector<char> tmp;

    for (int i = 0; i < inputStr.size(); i++)
    {
      tmp.push_back(inputStr[i]);
    }
    map.push_back(tmp);
  }
  InputFile.close();

  int product = countTrees(map, 1, 1) * countTrees(map, 3, 1) * countTrees(map, 5, 1) * countTrees(map, 7, 1) * countTrees(map, 1, 2);

  cout << "Product: " << product;

  return 0;
}
