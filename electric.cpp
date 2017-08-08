#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <limits.h>
#include <fstream>
#include <iomanip>
#include <queue>
#include <cassert>

using namespace std;
void cinN(unsigned int &x)
{
    register unsigned int c;

    x = 0;
    while((c = getchar_unlocked()) == ' ' || (c == '\n'));
    for (; (c>47 && c<58); c=getchar_unlocked())
        x = (x<<1) + (x<<3) + c - 48;
}
int main(void) {
  ios::sync_with_stdio(false);
  unsigned int cases;
  cinN(cases);
  for(int l = 0; l<cases; l++)
  {
   unsigned int v, e, start, end;
   cinN(v);
   cinN(e);
   cinN(start);
   cinN(end);
   vector<pair<int,int> >* adj = new vector<pair<int, int> >[v];
   for(int i = 0; i<e; i++)
   {
     unsigned int first, second, length;
     cinN(first);
     cinN(second);
     cinN(length);
     adj[first].push_back(make_pair(second, length));
     adj[second].push_back(make_pair(first, length));

   }
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
   bool* visited = new bool[v]();
   int* mi = new int[v];
   int* maxtoreach = new int[v]();
   maxtoreach[start] = 0;
   fill(mi, mi+v, INT_MAX/2);
   q.push(make_pair(0, start));
   while(!q.empty())
   {

     unsigned int vis = q.top().second;
     //cout << vis << endl;
     q.pop();
     visited[vis] = true;
     //cout << vis << " ";
     for(pair<int, int> p: adj[vis])
     {
        //cout << p.second << " ";
       if(!visited[p.first] && p.second < mi[p.first])
       {

         q.push(make_pair(p.second, p.first));
         mi[p.first] = p.second;
         maxtoreach[p.first] = max(maxtoreach[vis], p.second);
       }
     }
   }
  /* while(currentNode != start)
   {
     int swap = parent[currentNode].first;
     sum = max(sum, parent[currentNode].second);
     currentNode = swap;
   }*/
   /*for(int u = 0; u<v; u++)
   {
     cout << maxtoreach[u] << endl;
   }*/
   cout << maxtoreach[end] << endl;
  }
}
