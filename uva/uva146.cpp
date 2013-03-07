#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(void)
{
    char input[51];
    while(true)
    {
        gets(input);
        if (input[0] == '#')
           break;
        if(next_permutation(input, input+strlen(input)))
            printf("%s\n", input);
        else
            printf("No Successor\n");
    }
    return 0;
} 
