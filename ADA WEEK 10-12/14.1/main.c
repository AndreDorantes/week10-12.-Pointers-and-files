#include <stdio.h>
#include <stdlib.h>
#define FSIZE 100
 
int main()
{
    FILE *fptr;
    int ctr = 0;  
    char fname[FSIZE];
    char c; 
	printf(" Inserta el nombre del archivo : ");
	scanf("%s",fname);

    fptr = fopen(fname, "r");
    if (fptr == NULL)
    {
        printf("boludo, no se pudo abrir el archivo %s", fname);
        return 0;
    }
    for (c = getc(fptr); c != EOF; c = getc(fptr))
        if (c == '\n') 
            ctr = ctr + 1;
    fclose(fptr);
    printf(" El totoal de lineas del archivo son  %s  : %d \n \n", fname, ctr);
    
    getch();
    return 0;
}
