#include "iostream"
#include "math.h"

using namespace std;

int suma(const int a, const int b)
{
    int res;

    __asm__ __volatile__(
        "movl %1, %%eax;"
        "movl %2, %%ebx;"
        "addl %%ebx, %%eax;"
        "movl %%eax, %0;" : "=g" (res) : "g" (a), "g" (b)
    );

    cout << "\nEl resultado es: " << res << endl << endl;
}

int resta(const int a, const int b)
{
    int res;

    __asm__ __volatile__(
        "movl %1, %%eax;"
        "movl %2, %%ebx;"
        "subl %%ebx, %%eax;"
        "movl %%eax, %0;" : "=g" (res) : "g" (a), "g" (b)
    );

    cout << "\nEl resultado es: " << res << endl << endl;
}

int mult(const int a, const int b)
{
    int res;

    __asm__ __volatile__(
        "movl %1, %%eax;"
        "movl %2, %%ebx;"
        "mul %%ebx;"
        "movl %%eax, %0;" : "=g" (res) : "g" (a), "g" (b)
    );

    cout << "\nEl resultado es: " << res << endl << endl;
}

int divi(const int a, const int b)
{
    int res;

    __asm__ __volatile__(
        "movl %1, %%eax;"
        "movl %2, %%ebx;"
        "cltd;"
        "div %%ebx;"
        "movl %%eax, %0;" : "=g" (res) : "g" (a), "g" (b)
    );

    cout << "\nEl resultado es: " << res << endl << endl;
}

int pot(const int a, const int b)
{
    int res;

    __asm__ __volatile__(
        "movl %1, %%eax;"
        "movl %1, %%ebx;"
        "movl %2, %%ecx;"
        "cmpl $1, %%ecx;"
        "je UNO;"
        "jl CERO;"
        "decl %%ecx;"
        "POTENCIA: imull %%ebx;"
            "loopl POTENCIA;"
        "jmp FIN;"
        "UNO: jmp FIN;"
        "CERO: movl $1, %%eax;"
            "jmp FIN;"
        "FIN: movl %%eax, %0;" : "=g" (res) : "g" (a), "g" (b)
    );

    cout << "\nEl resultado es: " << res << endl << endl;
}

int raizC(const float n)
{
    float res;

    __asm__ __volatile__(
        "fld %1;"
        "fsqrt;"
        "fst %0;" : "=m" (res) : "g" (n)
    );

    cout << "\nEl resultado es: " << res << endl << endl;
}

int facto(const int n)
{
    int res;

    __asm__ __volatile__(
        "xor %%eax, %%eax;"
        "inc %%eax;"
        "xor %%ebx, %%ebx;"
        "inc %%ebx;"
        "movl %1, %%ecx;"
        "fun: mul %%ebx;"
        "inc %%ebx;"
        "cmp %%ebx, %%ecx;"
        "jne fun;"
        "mul %%ebx;"
        "movl %%eax, %0;" : "=g" (res) : "g" (n)
    );

    cout << "\nEl resultado es: " << res << endl << endl;
}

int absol(const int n)
{
    int res, neg = -1;

    __asm__ __volatile__(
        "movl %1, %%eax;"
        "cmp $0, %%eax;"
        "jg positive;"
        "movl %2, %%ebx;"
        "mul %%ebx;"
        "positive: movl %%eax, %0;" : "=g" (res) : "g" (n), "g" (neg)
    );

    cout << "\nEl resultado es: " << res << endl << endl;
}

int seno(float n)
{
    n = (n * M_PI) / 180;
    long double res;

    __asm__ __volatile__(
        "fsin" : "=t" (res) : "0" (n)
    );

    cout << "\nEl resultado es: " << res << endl << endl;
}

int coseno(float n)
{
    n = (n * M_PI) / 180;
    long double res;

    __asm__ __volatile__(
        "fcos" : "=t" (res) : "0" (n)
    );

    cout << "\nEl resultado es: " << res << endl << endl;
}

int tang(float n)
{
    n = (n * M_PI) / 180;
    long double res, res1, res2;

    __asm__ __volatile__(
        "fsin" : "=t" (res1) : "0" (n)
    );

    __asm__ __volatile__(
        "fcos" : "=t" (res2) : "0" (n)
    );

    res = res1 / res2;

    cout << "\nEl resultado es: " << res << endl << endl;
}

int secan(float n)
{
    n = (n * M_PI) / 180;
    long double res, res1;

    __asm__ __volatile__(
        "fcos" : "=t" (res1) : "0" (n)
    );

    res = 1 / res1;

    cout << "\nEl resultado es: " << res << endl << endl;
}

int cosec(float n)
{
    n = (n * M_PI) / 180;
    long double res, res1;

    __asm__ __volatile__(
        "fsin" : "=t" (res1) : "0" (n)
    );

    res = 1 / res1;

    cout << "\nEl resultado es: " << res << endl << endl;
}

int cotan(float n)
{
    n = (n * M_PI) / 180;
    long double res, res1, res2;

    __asm__ __volatile__(
        "fsin" : "=t" (res1) : "0" (n)
    );

    __asm__ __volatile__(
        "fcos" : "=t" (res2) : "0" (n)
    );

    res = res2 / res1;

    cout << "\nEl resultado es: " << res << endl << endl;
}

int main()
{
    int opc, num1, num2;
    float num;
    do
    {
        cout << "Bienvenido a la Calculadora Cientifica en ENSAMBLADOR" << endl << endl;
        cout << "1) SUMA" << endl;
        cout << "2) RESTA" << endl;
        cout << "3) MULTIPLICACION" << endl;
        cout << "4) DIVISION" << endl;
        cout << "5) POTENCIA" << endl;
        cout << "6) RAIZ CUADRADA" << endl;
        cout << "7) FACTORIAL" << endl;
        cout << "8) VALOR ABSOLUTO" << endl;
        cout << "9) SENO" << endl;
        cout << "10) COSENO" << endl;
        cout << "11) TANGENTE" << endl;
        cout << "12) SECANTE" << endl;
        cout << "13) COSECANTE" << endl;
        cout << "14) COTANGENTE" << endl;
        cout << "0) SALIR" << endl;
        cout << "\nSelecciona la operacion que deseas realizar: ";
        cin >> opc;
        switch(opc)
        {
            case 0: cout << "\nGracias por utilizar esta calculadora" << endl;
                 break;
            case 1: 
                cout << "\n---------------------------------------" << endl;
                cout << "\n\t\tSUMA" << endl;
                cout << "\nIntroduce el valor del 1er numero: ";
                cin >> num1;
                cout << "\nIntroduce el valor del 2do numero: ";
                cin >> num2;
                suma(num1, num2);
                cout << "---------------------------------------" << endl << endl;
                break;
            case 2:
                cout << "\n---------------------------------------" << endl;
                cout << "\n\t\tRESTA" << endl;
                cout << "\nIntroduce el valor del 1er numero: ";
                cin >> num1;
                cout << "\nIntroduce el valor del 2do numero: ";
                cin >> num2;
                resta(num1, num2);
                cout << "---------------------------------------" << endl << endl;
                break;
            case 3:
                cout << "\n---------------------------------------" << endl;
                cout << "\n\tMULTIPLICACION" << endl;
                cout << "\nIntroduce el valor del 1er numero: ";
                cin >> num1;
                cout << "\nIntroduce el valor del 2do numero: ";
                cin >> num2;
                mult(num1, num2);
                cout << "---------------------------------------" << endl << endl;
                break;
            case 4:
                cout << "\n---------------------------------------" << endl;
                cout << "\n\t\tDIVISION" << endl;
                cout << "\nIntroduce el valor del 1er numero: ";
                cin >> num1;
                cout << "\nIntroduce el valor del 2do numero: ";
                cin >> num2;
                divi(num1, num2);
                cout << "---------------------------------------" << endl << endl;
                break;
            case 5:
                cout << "\n---------------------------------------" << endl;
                cout << "\n\t\tPOTENCIA" << endl;
                cout << "\nIntroduce el valor del numero: ";
                cin >> num1;
                cout << "\nIntroduce el valor de la potencia: ";
                cin >> num2;
                pot(num1, num2);
                cout << "---------------------------------------" << endl << endl;
                break;
            case 6:
                cout << "\n---------------------------------------" << endl;
                cout << "\n\tRAIZ CUADRADA" << endl;
                cout << "\nIntroduce el valor del numero: ";
                cin >> num;
                raizC(num);
                cout << "---------------------------------------" << endl << endl;
                break;
            case 7:
                cout << "\n---------------------------------------" << endl;
                cout << "\n\t\tFACTORIAL" << endl;
                cout << "\nIntroduce el valor del numero: ";
                cin >> num1;
                facto(num1);
                cout << "---------------------------------------" << endl << endl;
                break;
            case 8:
                cout << "\n---------------------------------------" << endl;
                cout << "\n\tVALOR ABSOLUTO" << endl;
                cout << "\nIntroduce el valor del numero: ";
                cin >> num1;
                absol(num1);
                cout << "---------------------------------------" << endl << endl;
                break;
            case 9:
                cout << "\n---------------------------------------" << endl;
                cout << "\n\t\tSENO" << endl;
                cout << "\nIntroduce el valor del numero: ";
                cin >> num;
                seno(num);
                cout << "---------------------------------------" << endl << endl;
                break;
            case 10:
                cout << "\n---------------------------------------" << endl;
                cout << "\n\t\tCOSENO" << endl;
                cout << "\nIntroduce el valor del numero: ";
                cin >> num;
                coseno(num);
                cout << "---------------------------------------" << endl << endl;
                break;
            case 11:
                cout << "\n---------------------------------------" << endl;
                cout << "\n\t\tTANGENTE" << endl;
                cout << "\nIntroduce el valor del numero: ";
                cin >> num;
                tang(num);
                cout << "---------------------------------------" << endl << endl;
                break;
            case 12:
                cout << "\n---------------------------------------" << endl;
                cout << "\n\t\tSECANTE" << endl;
                cout << "\nIntroduce el valor del numero: ";
                cin >> num;
                secan(num);
                cout << "---------------------------------------" << endl << endl;
                break;
            case 13:
                cout << "\n---------------------------------------" << endl;
                cout << "\n\t\tCOSECANTE" << endl;
                cout << "\nIntroduce el valor del numero: ";
                cin >> num;
                cosec(num);
                cout << "---------------------------------------" << endl << endl;
                break;
            case 14:
                cout << "\n---------------------------------------" << endl;
                cout << "\n\t\tCOTANGENTE" << endl;
                cout << "\nIntroduce el valor del numero: ";
                cin >> num;
                cotan(num);
                cout << "---------------------------------------" << endl << endl;
                break;
            default: cout << "ERROR. Opcion invalida, vuelve a interalo."<< endl;
                break;
        }
    }
    while(opc!=0);

    return 0;
}
