#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define PI 3.1415

int resistance;
void addition();
void subtraction();
void multipLication();
void division();
void factorial();
void modulus();
void square();
void squareroot();
void cube();
void SIN();
void COS();
void TAN();
void SININV();
void COSINV();
void TANINV();
int Resistorcolorcode(int R)
{
    // getting the 1st digit
    int digit1 = R / 100;
    int digit2 = (R / 10) % 10;
    int multiplier = 0;
    while (R >= 100)
    {
        R /= 10;
        multiplier++;
    }
    printf("The color code for the %d ohms resistance are:\n", resistance);

    printf(" Digit 1: ");
    switch (digit1)
    {
    case 0:
        printf("Black");
        break;
    case 1:
        printf("Brown");
        break;
    case 2:
        printf("Red");
        break;
    case 3:
        printf("Orange");
        break;
    case 4:
        printf("Yellow");
        break;
    case 5:
        printf("Green");
        break;
    case 6:
        printf("Blue");
        break;
    case 7:
        printf("Violet");
        break;
    case 8:
        printf("Grey");
        break;
    case 9:
        printf("White");
        break;
    }
    printf("\nDigit 2: ");
    switch (digit2)
    {
    case 0:
        printf("Black");
        break;
    case 1:
        printf("Brown");
        break;
    case 2:
        printf("Red");
        break;
    case 3:
        printf("Orange");
        break;
    case 4:
        printf("Yellow");
        break;
    case 5:
        printf("Green");
        break;
    case 6:
        printf("Blue");
        break;
    case 7:
        printf("Violet");
        break;
    case 8:
        printf("Grey");
        break;
    case 9:
        printf("White");
        break;
    }
    printf("\nMultiplier: ");
    switch (multiplier)
    {
    case 0:
        printf("Black");
        break;
    case 1:
        printf("Brown");
        break;
    case 2:
        printf("Red");
        break;
    case 3:
        printf("Orange");
        break;
    case 4:
        printf("Yellow");
        break;
    case 5:
        printf("Green");
        break;
    case 6:
        printf("Blue");
        break;
    case 7:
        printf("Violet");
        break;
    case 8:
        printf("Grey");
        break;
    case 9:
        printf("White");
        break;
    }
    printf("\n");
    return 0;
}

int main()
{


    printf("WELCOME TO OUR PROJECT CREATED BY GROUP P14- SCI-FI-CALCULATOR\n We are \n 1. Nishanth Kumaran    ROLL NO: 2301PH12\n 2. MANISH KUMAR REDDY   ROLL NO:2301MC06\n 3. AWADHESH KUMAR SHARMA    ROLL NO: 2301ME63 \n 4. MITALI KUMARI   ROLL NO: 2301ME33\n 5. SAGAR KUMAR  ROLL NO: 2301MM28\n 6. LAKSH KUMAR SISODIYA   ROLL NO: 2302MC05\n  7. KIRAN KUMAR BOMMU  ROLL NO: 2302VL03\n 8. SARAVAN KUMAR NALLAPU  ROLL NO: 2302ST07\n 9. SONALI KUMARI  ROLL NO: 2301EC31\n 10. AFIFAH KHAN  ROLL NO: 2302CM06\n");
    printf("-------------------------------------------------\n");
    printf("-------------------------------------------------\n");
    printf("Select the type of calculation you");
    // we can also do integration,differentiation,all type of calculation,
    //  age

    printf("Enter the resistance value in ohms: ");
    scanf("%d",&resistance);
    Resistorcolorcode(resistance);

    return 0;
}
