#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;

int main(void){
    char table[52];
    int tableCount = 0;
    deque<char> cards[2];
    int turn = 1;
    int times = -1;
    char current;
    bool toEnd;
    
	while(1){            
        scanf("%c",&current);
        if (current == '#')
           break;
        scanf("%c",&current);
        cards[turn].push_front(current);
        scanf("%c",&current);
        turn = 1 - turn;
        if (cards[0].size() == 26 && cards[1].size() == 26){
           while (cards[turn].size() != 0){
                 table[tableCount] = cards[turn].front();
                 cards[turn].pop_front();
                 tableCount++;
                 if (times > 0)
                    times--;                    
                 if (table[tableCount - 1] >= 'A' && table[tableCount - 1] != 'T') {
                    if (table[tableCount - 1] == 'A')
                       times = 4;
                    else if (table[tableCount - 1] == 'K')
                       times = 3;
                    else if (table[tableCount - 1] == 'Q')
                       times = 2;
                    else if (table[tableCount - 1] == 'J')
                       times = 1;
                    turn = 1 - turn;
                 }
                 if (times == 0){
                    turn = 1 - turn;
                    for (int i = 0; i < tableCount; i++){
                        cards[turn].push_back(table[i]);
                    }
                    tableCount = 0; 
                    times = -1;
                    turn = 1 - turn;                
                 }
                 
                 if (times == -1)
                     turn = 1 - turn;
           }
           
           printf("%d%3d\n", (turn ? 1 : 2), cards[(turn+1)%2].size());
           tableCount = 0;
           cards[0].clear();
           cards[1].clear();
           turn = 1;
           times = -1;
        }
        
    }
    
    return 0;
}
