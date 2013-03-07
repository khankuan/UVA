#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <ctime>
using namespace std;

int parent(int i){ return i >> 1;}
int left(int i){ return i << 1;}
int right(int i){ return (i << 1) +1;}

void create_segment(int st[], int A[], int pcount){
     
     int tsize = 1 << (((int)(log(pcount << 1)/log(2))) + 1);
     memset(st,0,sizeof(st));
     int bottomsize = tsize >> 1;
     for (int i = 0; i < pcount; i++)
         st[bottomsize+i] = A[i];
     for (int i = bottomsize-1; i > 0; i--)
         st[i] = st[left(i)] + st[right(i)];   
}

void update_segment(int st[], int first, int second, int type){
     queue<int> q;    
     
     if (type == 1){
        for (int i = first; i <= second; i++){
            if (st[i] == 0){
               st[i] = 1;
               q.push(parent(i));
            }
        }
     } else if (type == 0){
       for (int i = first; i <= second; i++){
            if (st[i]){
               st[i] = 0;
               q.push(parent(i));
            }
       }
     } else{
         for (int i = first; i <= second; i++){
               st[i] = 1 - st[i];
               q.push(parent(i));
         }
     }
     
     bool* done = new bool[2097152];
     memset(done, 0, sizeof(done));
     while (q.size() != 0){
           int one = q.front();
           q.pop();
           if (!done[one]){
              done[one] = true;
              st[one] = st[left(one)] + st[right(one)];
              if (one != 1)
                 q.push(parent(one));
           }
           if (q.size() != 0){
               int two = q.front();
               q.pop();
               if (!done[two]){
                   done[two] = true;
                   st[two] = st[left(two)] + st[right(two)];
                   if (parent(two) != parent(one) && parent(two) != 0)
                      q.push(parent(two));
               }
           }           
           
     }
}

int query_segment(int st[], int v, int L, int R, int first, int second){
    
     if (first == L && second == R)
        return st[v];
     
     int M = (R+L)>>1;
     return ((first > M) ? 0 : query_segment(st, left(v), L, M, first,  (second < M) ? second : M)) + 
            ((second < M+1) ? 0 : query_segment(st, right(v), M+1, R, (first > M+1) ? first : M+1 , second));
}

struct{
       int times;
       char pattern[50];
       Node next;
} Node;

int main(void){
    int testcount;
    scanf("%d", &testcount);
    int* segmentTree = new int[2097152];
    int* pirates = new int[1024000];
    char input[50];
    for (int test = 0; test < testcount; test++){
        int set;
        scanf("%d", &set);        
        int pcount = 0;
        int times;   
        for (int seti = 0; seti < set; seti++){              
            scanf("%d", &times);
            getchar();            
            scanf("%s",&input);
            getchar();
            int len = strlen(input);
            int toInt[len];
            for (int i = 0; i < len; i++)
                toInt[i] = input[i] - '0';       
            for (int timesi = 0; timesi < times; timesi++){
                int current = pcount + timesi*len;
                for (int lengthi = 0; lengthi < len; lengthi++)
                    pirates[current+lengthi] = toInt[lengthi];
            }
            pcount += times*len;
        }
        
        create_segment(segmentTree, pirates, pcount);        

        
        int action;
        scanf("%d", &action);
        getchar();
        printf("Case %d:\n",test+1);
        int qcount = 0;
        int psize = 1 << (int)(log(pcount << 1)/log(2));
        for (int actioni = 0; actioni < action; actioni++){

            char type;
            int first, second;
            scanf("%c %d %d", &type, &first, &second);
            
            getchar();
            if (type == 'F')
               update_segment(segmentTree, psize+first, psize+second, 1); 
            else if (type == 'E')
               update_segment(segmentTree, psize+first, psize+second, 0); 
            else if (type == 'I')
               update_segment(segmentTree, psize+first, psize+second, 2); 
            else{
               qcount++;
               printf("Q%d: %d\n", qcount, query_segment(segmentTree, 1, 0, psize-1, first, second));
            }


        }
        
    }    
    system("pause");
    return 0;
}
