#include <stdio.h>

/**
 * Afisati adresele elementelor din vectorul "v" impreuna cu valorile
 * de la acestea.
 * Parcurgeti adresele, pe rand, din octet in octet,
 * din 2 in 2 octeti si apoi din 4 in 4.
 */

void print_1in1(int* v,unsigned int length)
{
    unsigned char* p = (unsigned char*) (v);
    printf("\nDin 1 in 1 octeti : \n\n");
    for(int i = 0; i < length / sizeof(char); i++)
    {
        printf("ADRESA : %p VALOARE : %x\n", p, *p);
        p++;
    }
}

void print_2in2(int* v,unsigned int length)
{
    unsigned short* p = (unsigned short*) (v);
    printf("\nDin 2 in 2 octeti : \n\n");
    for(int i = 0; i < length / sizeof(short); i++)
    {
        printf("ADRESA : %p VALOARE : %x\n", p, *p);
        p++;
    }
}

void print_4in4(int* v,unsigned int length)
{
    unsigned int* p = (unsigned int*) (v);
    printf("\nDin 4 in 4 octeti : \n\n");
    for(int i = 0; i < length / sizeof(int); i++)
    {
        printf("ADRESA : %p VALOARE : %x\n", p, *p);
        p++;
    }
}

int main() {
    int v[] = {0xCAFEBABE, 0xDEADBEEF, 0x0B00B135, 0xBAADF00D, 0xDEADC0DE};
    unsigned int n = sizeof(v);
    printf("\nAdresele si valorile din v : \n\n");
    for(int i = 0; i < sizeof(v) / sizeof(int); i++){
        printf("ADRESA : %p VALOARE : %x\n", v + i, *(v + i));
    }
    print_1in1(v, n);
    print_2in2(v, n);
    print_4in4(v, n);
    return 0;
}
