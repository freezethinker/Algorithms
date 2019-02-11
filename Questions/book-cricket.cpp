/**
 * Book Cricket with every page ending with {0,2,4,6,8}
 * 0 and 8 are out.
 * 2, 4, 6 are valid runs.
 * 
 * Objective: Calculate the number of ways possible to score a total score, without getting out.
 * 
 * Example: 6: (6), (2, 4), (4, 2), (2, 2, 2) = 4
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim (const string &);
string rtrim (const string &);

int
noOfWaysToDrawTheGame (int totalScore)
{
  if (totalScore < 2)
    return 0;

  int possibleWays[totalScore + 1], i;
  for (int j = 0; j < totalScore + 1; j++)
    {
      possibleWays[j] = 0;
    }
  possibleWays[0] = 1;

  for (i = 2; i <= totalScore; i++)
    {
      possibleWays[i] += (i - 2) >= 0 ? possibleWays[i - 2] : 0;
      possibleWays[i] += (i - 4) >= 0 ? possibleWays[i - 4] : 0;
      possibleWays[i] += (i - 6) >= 0 ? possibleWays[i - 6] : 0;
    }
  return possibleWays[totalScore];
}

int
main ()
{
  ofstream fout (getenv ("OUTPUT_PATH"));

  string totalScore_temp;
  getline (cin, totalScore_temp);

  int totalScore = stoi (ltrim (rtrim (totalScore_temp)));

  int res = noOfWaysToDrawTheGame (totalScore);

  fout << res << "\n";

  fout.close ();

  return 0;
}

string
ltrim (const string & str)
{
  string s (str);

  s.erase (s.begin (),
	   find_if (s.begin (), s.end (),
		    not1 (ptr_fun < int, int >(isspace))));

  return s;
}

string
rtrim (const string & str)
{
  string s (str);

  s.erase (find_if
	   (s.rbegin (), s.rend (),
	    not1 (ptr_fun < int, int >(isspace))).base (), s.end ());

  return s;
}
