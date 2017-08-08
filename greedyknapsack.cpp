#include <cassert>
#include <iostream>
//#include <unistd.h>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <climits>
using namespace std;
void cinN(unsigned int &x)
{
    register unsigned int c;

    x = 0;
    while((c = getchar_unlocked()) == ' ' || (c == '\n'));
    for (; (c>47 && c<58); c=getchar_unlocked())
        x = (x<<1) + (x<<3) + c - 48;
}
int main (void) {
	std::ios::sync_with_stdio(false);
  unsigned int cases, maxWeight, items;
  cinN(cases);
  for(int i = 0; i<cases; i++)
  {
    //cout << "Testcase: " << i << endl;
    cinN(maxWeight);
    cinN(items);
    pair<double, int>* quotient = new pair<double, int>[items];
    int* value = new int[items];
    int* weights = new int[items];
    unsigned int maxValue = 0;
    unsigned int maxValueItem;
    for(int j = 0; j<items; j++)
    {

     unsigned int weight;
     unsigned int val;
     cinN(val);
     cinN(weight);
     double valDouble = val;
     double weightDouble = weight;
     if(weight <= maxWeight)
     {
     quotient[j] = make_pair(-valDouble/weightDouble, j);
     value[j] = val;
     weights[j] = weight;
     maxValue = max(maxValue, val);
     if(maxValue == val)
     {
       maxValueItem = j;
     }
   }



    }
    sort(quotient, quotient+items);
    //cout << quotient[0].first << " " << quotient[1].first << endl;
    uint64_t greedySum=0;
    uint64_t greedyWeight = 0;
    vector<int> toPrint;
    for(int k = 0; k<items; k++)
    {
      greedyWeight += weights[quotient[k].second];
      if(greedyWeight<=maxWeight)
      {
        toPrint.push_back(quotient[k].second);
        //cout << "ToPrint: " << quotient[k].second << endl;
        greedySum += value[quotient[k].second];
      }
      else
      { maxValue = value[quotient[k].second];
        maxValueItem = quotient[k].second;
        //cout << "Greedy: " << maxValueItem << endl;
      break; }
    }
    if(greedySum < maxValue)
    {
      cout << maxValueItem << endl;
    }
    else{
      for(int m = 0; m<toPrint.size(); m++)
      {
        if(m != 0)
          cout << " ";
        cout << toPrint[m];
      }
      cout << endl;
    }
  }

}
