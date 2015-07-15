/* pe15-5.c */ 
#include <stdio.h> 

unsigned int rotate_l(unsigned int, unsigned int);
char * itobs(int, char *);

int main(void)
{
    unsigned int val;
    unsigned int rot;
    unsigned int places;
    char bstr1[8* sizeof (int) + 1];
    char bstr2[8* sizeof (int) + 1];
    
    printf("Enter an integer (0 to quit): ");
    while (scanf("%ud", &val) && val > 0)
    {
        printf("Enter the number of bits to be rotated: \n");
        scanf("%ul", &places);
        rot = rotate_l(val, places);
        itobs(val, bstr1);
        itobs(rot, bstr2);
        printf ("%u rotated is %u.\n", val, rot );
        printf("%s rotated is %s.\n", bstr1, bstr2);
        printf("Next value: ");
    }
    
    puts("Done");
    return 0;
}

unsigned int rotate_l(unsigned int n, unsigned int b)
{
    static const int size = 8 * sizeof(int);
    unsigned int overflow;
    
    b %= size;  /* keep b a valid value */
    
    overflow = n >> (size - b);  /* save bits that are shifted out */
    return (n << b) | overflow;
}
char * itobs(int n, char * ps)
{
    int i;
    static int size = 8 * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}
