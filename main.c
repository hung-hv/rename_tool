#include <stdio.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXC 1024       /* if you need a constant, #define one (or more) */
#define NPTRS   2       /* initial no. of pointers to allocate (lines) */

int countLines(FILE *fp, int *longest)
{
    int i=0;
    int max = 0;
    char line[4095];  // max for C99 strings
    *longest = max;
    while(fgets(line, 4095, fp))
    {
        max = strlen(line); 
        if(max > *longest) *longest = max;//record longest
        i++;//track line count
    }
    return i;
}

char ** create2D(char **a, int lines, int longest)
{
    int i;
    a = malloc(lines*sizeof(char *));
    if(!a) return NULL;
    {
        for(i=0;i<lines;i++)
        {
            a[i] = malloc(longest+1);
            if(!a[i]) return NULL;
        }
    }
    return a;
}

void free2D(char **a, int lines)
{
    int i;
    for(i=0;i<lines;i++)
    {
        if(a[i]) free(a[i]);
    }
    if(a) free(a);
}
int main() {
    int longest;
    // char **strArr = {0};
    int line_count= 0;
    FILE *fp = fopen("HKB.txt", "r");
    // if(fp)
    // {
    //     line_count = countLines(fp, &longest);
    //     printf("\nnumber of line: %d", line_count);
    //     // GetKey();
    // }
    // // use count and longest to create memory
    // strArr = create2D(strArr, count, longest);
    // printf("\nline %s to %s", filename, strArr[i]);

     char buf[MAXC],                 /* fixed buffer to read each line */
        **lines = NULL;             /* pointer to pointer to hold collection of lines */
    size_t  nptrs = NPTRS,          /* number of pointers available */
            used = 0;               /* number of pointers used */
    /* use filename provided as 1st argument (stdin by default) */
    // FILE *fp = argc > 1 ? fopen (argv[1], "r") : stdin;
    
    if (!fp) {  /* validate file open for reading */
        perror ("file open failed");
        return 1;
    } 
    // else {
    //     line_count = countLines(fp, &longest);
    //     printf("\nnumber of line: %d", line_count);
    // }
    
    /* allocate/validate block holding initial nptrs pointers */
    if ((lines = malloc (nptrs * sizeof *lines)) == NULL) {
        perror ("malloc-lines");
        exit (EXIT_FAILURE);
    }
    
    while (fgets (buf, MAXC, fp)) {                 /* read each line into buf */
        size_t len;
        buf[(len = strcspn (buf, "\n"))] = 0;       /* trim \n, save length */
        
        if (used == nptrs) {    /* check if realloc of lines needed */
            /* always realloc using temporary pointer (doubling no. of pointers) */
            void *tmp = realloc (lines, (2 * nptrs) * sizeof *lines);
            if (!tmp) {                             /* validate reallocation */
                perror ("realloc-lines");
                break;                              /* don't exit, lines still good */
            }
            lines = tmp;                            /* assign reallocated block to lines */
            nptrs *= 2;                             /* update no. of pointers allocatd */
            /* (optionally) zero all newly allocated memory here */
        }
        
        /* allocate/validate storage for line */
        if (!(lines[used] = malloc (len + 1))) {
            perror ("malloc-lines[used]");
            break;
        }
        memcpy (lines[used], buf, len + 1);         /* copy line from buf to lines[used] */
        line_count++;
        printf("\nadding new line to char Double Pointer: %d", line_count);
        
        used += 1;                                  /* increment used pointer count */
    }
    // if (fp != stdin)   /* close file if not stdin */
        fclose (fp);


// char *arr[] = { "Geek.pdf", "Geeks.pdf", "Geekfor.pdf" };

const int numfiles = 10;
// FILE *files[numfiles];
// printf("\nnumber of line: %d", line_count);


// for (int i = 0; i < line_count; i++)
// {
//     char filename[20];
//     sprintf(filename, "HK (%d).txt", i+1);
//     FILE *demo_file;
//     demo_file = fopen(filename, "w");
//     fprintf(demo_file, "%d", i + 1);
//     fclose(demo_file);
// }

uint8_t retn = 0;
printf("\total of line: %d", line_count);

int counter = 0;
for (int i = 0; i < line_count; i++)
{
    char filename[30];
    char new_name[50];
    // char tail[] = ".txt";
    // memset(filename, 0, sizeof(filename));
    sprintf(filename, "HK (%d).pdf", i+1);
    // memset(new_name, 0, sizeof(new_name));
    sprintf(new_name, "%s.pdf", lines[i]);
    // strcat(lines[i], tail);
    // printf("\ntesting %s", lines[i]);
    printf("\nchanged name %s to %s", filename, new_name);
    retn = rename(filename, new_name);
    counter++;
} 
    printf("\n >>Total converted item = %d", counter);

    printf("\n--------------------------------------------------------\n\n\n\n");
    printf("\nHelloooooo, Mot ngay dep troi nho'");
    printf("\n\nPress any key to exit!");
    getch();
    return 0;
}