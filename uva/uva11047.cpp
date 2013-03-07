#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main(void){
    int testcases;
    scanf("%d",&testcases);
    int V;
    for (int test  = 0; test < testcases; test++){
        scanf("%d",&V);
        getchar();
        int adjM[V][V];
        map<string,int> venueS;
        map<int,string> venueI;
        for (int i = 0; i < V; i++){
            char input[50];
            scanf("%s",&input);
            string inputS = input;
            venueS[inputS] = i;
            venueI[i] = inputS;
        }
        
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++){
                   scanf("%d",&adjM[i][j]);
                   if (adjM[i][j] == -1)
                      adjM[i][j] = 100000000;
                   getchar();
            }
        
        
        
        int p[V][V];
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                p[i][j] = i;

        for (int k = 0; k < V; k++){
            for (int i = 0; i < V; i++){
                for (int j = 0; j < V; j++){
                    if (adjM[i][j] > adjM[i][k] + adjM[k][j]){
                        adjM[i][j] = adjM[i][k] + adjM[k][j]; 
                        p[i][j] = p[k][j];
                    }
                }
            }
        }
        


        int qcount;
        scanf("%d",&qcount);
        
        char name[50],from[50],to[50];
        for (int query = 0; query < qcount; query++){
            scanf("%s %s %s",&name, &from, &to);
            string fromS = from, toS = to;
            int fromInt = venueS.find(fromS)->second;
            int toInt = venueS.find(toS)->second;
            if (adjM[fromInt][toInt] == 100000000){
              cout << "Sorry Mr " << name << " you can not go from " << from << " to " << to << endl;
            } else {
              cout << "Mr " << name << " to go from " << from << " to " << to << ", you will receive " << adjM[fromInt][toInt]<< " euros" << endl;
              cout << "Path:";
              int current = toInt;
              vector<int> s;
              while (true){
                    s.push_back(current);
                    current = p[fromInt][current];
                    if (current == fromInt)
                       break;
              }
              cout << from << " ";
              for (int i = s.size() - 1; i >= 0; i--){
                  cout << venueI.find(s[i])->second;
                  if (i != 0)
                     cout << " ";
              }
              cout << endl;
            }
        }
        
    }

    return 0;
}
