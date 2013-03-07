#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int count;
    char type;
    int rows,cols;
    scanf("%d%c",&count,&type);
    for (int i = 0; i < count; i++){
        scanf("%c%d%d", &type, &rows, &cols);
        if (type == 'k')
           printf("%d\n",((rows*cols+1) >> 1));
        else if (type == 'K')
           printf("%d\n", ((rows + 1) >> 1) * ((cols + 1) >> 1) );
        else {
           if (rows < cols)
              printf("%d\n",rows);
           else
               printf("%d\n",cols);
        }
        scanf("%c",&type);
    }
    system("pause");
    return 0;
}
