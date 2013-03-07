#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

vector<int> pset;
		
int findSet(int i) {
	if (pset.at(i) == i) return i;
	else {
		pset.at(i) = findSet(pset.at(i));
		return pset.at(i);
	}
}

void unionSet(int i, int j) {
	pset.at(findSet(i)) = findSet(j);
}

bool isSameSet(int i, int j) {
	return findSet(i) == findSet(j);
}

int main(void){
    int testcount;
    scanf("%d",&testcount);
    getchar();
    for (int test = 0; test < testcount; test++){
        
        int numComs;
        vector<pair<int,int> > q;
        scanf("%d",&numComs);
        getchar();
        
        pset.clear();
        for (int i = 0; i < numComs; i++)        
		    pset.push_back(i);
		    
        char input;
        int same = 0, nosame = 0, first, second;
        while (scanf("%c",&input)==1 && input != '\n'){
              scanf("%d %d",&first,&second);
              getchar();
              if (input == 'q'){
                 if (isSameSet(first-1,second-1))
                    same++;
                 else
                    nosame++;
              }
              else
                 unionSet(first-1,second-1);
        }
        
        printf("%d,%d\n",same, nosame);
        if (test != testcount -1)
           printf("\n");
    }

    system("pause");
    return 0;
}
