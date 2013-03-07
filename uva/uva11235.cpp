#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;

// Segment Tree Library: The segment tree is stored like a heap array
void st_build(vi &st, const vi &A, int vertex, int L, int R) {
  if (L == R)                              // as L == R, either one is fine
    st[vertex] = L;                                      // store the index
  else {   // recursively compute the values in the left and right subtrees
    int nL = 2 * vertex, nR = 2 * vertex + 1;
    st_build(st, A, nL, L              , (L + R) / 2);
    st_build(st, A, nR, (L + R) / 2 + 1, R          );
    int lContent = st[nL]     , rContent = st[nR];
    int lValue   = A[lContent], rValue   = A[rContent];
    st[vertex] = (lValue >= rValue) ? lContent : rContent;
} }

void st_create(vi &st, const vi &A) {       // if original array size is N,
     // the required segment tree array length is 2*2^(floor(log2(N)) + 1);
  int len = (int)(2*pow(2.0, floor((log((double)A.size())/log(2.0)) + 1)));
  st.assign(len, 0); // create vector of size `len' and fill it with zeroes
  st_build(st, A, 1, 0, (int)A.size() - 1);              // recursive build
}

int st_rmq(vi &st, const vi &A, int vertex, int L, int R, int i, int j) {
  if (i >  R || j <  L) return -1;   // current segment outside query range
  if (L >= i && R <= j) return st[vertex];            // inside query range

     // compute the min position in the left and right part of the interval
  int p1 = st_rmq(st, A, 2 * vertex    , L              , (L+R) / 2, i, j);
  int p2 = st_rmq(st, A, 2 * vertex + 1, (L+R) / 2 + 1, R          , i, j);

                        // return the position where the overall minimum is
  if (p1 == -1) return p2;     // if we try to access segment outside query
  if (p2 == -1) return p1;                                 // same as above
  return (A[p1] >= A[p2]) ? p1 : p2; }

int st_rmq(vi &st, const vi& A, int i, int j) {     // function overloading
  return st_rmq(st, A, 1, 0, (int)A.size() - 1, i, j); }

int main() {
    
    while (true){
          int num,qcount,i;
          scanf("%d",&num);
          int arr[num]; 
          int freq[num];
          int start[200005];
          int end[200005];          
          if (num == 0)
             break;
          scanf(" %d",&qcount);
          getchar();
                  
          i = 1;
          
          scanf("%d",&arr[0]);
          start[arr[0]+100000] = 0;    
          while (1){
                if (i == num)
                   break;
                scanf("%d",&arr[i]);
                if (arr[i] != arr[i-1]){
                   end[arr[i-1]+100000] = i-1;
                   start[arr[i]+100000] = i;
                   int count = i - start[arr[i-1]+100000];
                   for (int j = i - count; j < i; j++)
                       freq[j] = count;
                }
                i++;
          }
          getchar();
          end[arr[i-1]+100000] = i-1;
          int count = i - start[arr[i-1]+100000];
          for (int j = i - count; j < i; j++)
             freq[j] = count;
                    
          
          vector<int> A(freq, freq + num);

          vi st; 
          st_create(st, A);        
          
          for (int i = 0; i < qcount; i++){
              int from, to;
              scanf("%d %d",&from,&to);
              getchar();
              from--;
              to--;         
              int qStart = 0,qEnd = 0,x,y;
              if (from > 0){
                     if (arr[from] == arr[from-1]){
                         x = end[arr[from]+100000] + 1;
                         if (x > to)
                            x = to + 1;
                         qStart = x - from;   
                     }else
                         x = from;
              } else
                    x = from;
              if (to < num-1){
                 if( arr[to] == arr[to+1]){
                     y = start[arr[to]+100000] - 1;
                     if (y < from)
                        y = from - 1;
                     qEnd = to - y;   
                 }else
                      y = to;               
              } else
                 y = to;
              
              int highest = max(qStart,qEnd);
              if (x == y)
                 highest = max(highest,1);
              else if (x < y)
                   highest = max(highest,min(A[st_rmq(st,A,x,y)],y-x+1));
              printf("%d\n",highest);
          }
          
    } 
    
    system("pause");
    return 0;
} 
