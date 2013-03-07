#include <cstdio>
#include <vector>
using namespace std;

#define LSOne(S) (S & (-S))

// initialization: n + 1 zeroes, ignoring index 0, just using index [1..n]
void ft_create(vector<int> &ft, int n) { ft.assign(n + 1, 0); }

int ft_rsq(const vector<int> &ft, int b) {                      // returns RSQ(1, b)
  int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
  return sum; }

int ft_rsq(const vector<int> &ft, int a, int b) {               // returns RSQ(a, b)
  return ft_rsq(ft, b) - (a == 1 ? 0 : ft_rsq(ft, a - 1)); }

// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
void ft_adjust(vector<int> &ft, int k, int v) {           // note: n = ft.size() - 1
  for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }



int main(void){
    int N,M;
    while (true){
          scanf("%d %d",&N,&M);
          if (N == 0 && M == 0)
             break;
          
          vector<int> ft;
          ft_create(ft,1000001);
          bool valid = true;
          for (int i = 0; i < N; i++){
              int from,to;
              scanf("%d %d",&from,&to);
              from++;
              to++;
              if (valid){
                  if (ft_rsq(ft,from,to-1) > 0)
                     valid = false;
                  for (int j = from; j < to;j++){     
                      ft_adjust(ft,j,1);
                  }
              }
          }
          for (int i = 0; i < M; i++){
              int from,to,interval;
              scanf("%d %d %d",&from,&to,&interval);
              from++;
              to++;
              if (valid){
                  while (from < 1000002){
                        if (to > 1000001)
                           to = 1000001;
                      if (ft_rsq(ft,from,to-1) > 0)
                         valid = false;
                      if (!valid)
                         break;
                      for (int j = from; j < to;j++){     
                          ft_adjust(ft,j,1);
                      }
                      from += interval;
                      to += interval;
                  }
              }
          }
          
          if (valid)
              printf("NO CONFLICT\n");
          else
              printf("CONFLICT\n");
    }
    
    
    return 0;
}
