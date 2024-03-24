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
    int digit1 = R;
    while (digit1 > 10)
    {
        digit1 /= 10;
    }
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

// Function to decode the color code of a capacitor
void decodeCapacitorColor(int band1, int band2, int multiplier, int tolerance)
{
    // Array of colors corresponding to digit values
    char *colors[] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Violet", "Gray", "White"};

    // Printing the decoded values
    printf("Capacitor Value: %d%d * 10^%d Farad\n", band1, band2, multiplier);
    printf("Tolerance: %d%%\n", tolerance);
}

int main()
{

    printf("WELCOME TO OUR PROJECT CREATED BY GROUP P14- SCI-FI-CALCULATOR\n We are \n 1. Nishanth Kumaran    ROLL NO: 2301PH12\n 2. MANISH KUMAR REDDY   ROLL NO:2301MC06\n 3. AWADHESH KUMAR SHARMA    ROLL NO: 2301ME63 \n 4. MITALI KUMARI   ROLL NO: 2301ME33\n 5. SAGAR KUMAR  ROLL NO: 2301MM28\n 6. LAKSH KUMAR SISODIYA   ROLL NO: 2302MC05\n  7. KIRAN KUMAR BOMMU  ROLL NO: 2302VL03\n 8. SARAVAN KUMAR NALLAPU  ROLL NO: 2302ST07\n 9. SONALI KUMARI  ROLL NO: 2301EC31\n 10. AFIFAH KHAN  ROLL NO: 2302CM06\n");
    printf("-------------------------------------------------\n");
    printf("-------------------------------------------------\n");
    printf("Select the type of calculation you wish");
    // we can also do integration,differentiation,all type of calculation,
    //  age

    printf("Enter the resistance value in ohms: ");
    scanf("%d", &resistance);
    Resistorcolorcode(resistance);

    // Colors and their corresponding values
    int band1, band2, multiplier, tolerance;
    char *colorNames[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white"};
    int colorValues[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float multipliers[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int toleranceValues[] = {20, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Tolerance values in percent

    // User input for the color bands
    printf("Enter the color of the first band: ");
    char color1[10];
    scanf("%s", color1);

    printf("Enter the color of the second band: ");
    char color2[10];
    scanf("%s", color2);

    printf("Enter the color of the multiplier band: ");
    char color3[10];
    scanf("%s", color3);

    printf("Enter the color of the tolerance band: ");
    char color4[10];
    scanf("%s", color4);

    // Decoding the colors
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(color1, colorNames[i]) == 0)
            band1 = colorValues[i];
        if (strcmp(color2, colorNames[i]) == 0)
            band2 = colorValues[i];
        if (strcmp(color3, colorNames[i]) == 0)
            multiplier = multipliers[i];
        if (strcmp(color4, colorNames[i]) == 0)
            tolerance = toleranceValues[i];
    }

    // Displaying the decoded capacitor information
    decodeCapacitorColor(band1, band2, multiplier, tolerance);

    int **matrix1;
    int **matrix2;
    int **summatrix;

    int sizeM;
    printf("Enter the size of matrix you want to add\n");
    scanf("%d", &sizeM);

    matrix1 = (int **)malloc(sizeM * sizeof(int *));
    for (int i = 0; i < sizeM; i++)
    {
        matrix1[i] = (int *)malloc(sizeM * sizeof(int));
    }

    // Allocate memory for matrix2
    matrix2 = (int **)malloc(sizeM * sizeof(int *));
    for (int i = 0; i < sizeM; i++)
    {
        matrix2[i] = (int *)malloc(sizeM * sizeof(int));
    }

    summatrix = (int **)malloc(sizeM * sizeof(int *));
    for (int i = 0; i < sizeM; i++)
    {
        summatrix[i] = (int *)malloc(sizeM * sizeof(int));
    }

    printf("Enter the matrix1\n");
    for (int i = 0; i < sizeM; i++)
    {
        for (int j = 0; j < sizeM; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter the matrix2\n");
    for (int i = 0; i < sizeM; i++)
    {
        for (int j = 0; j < sizeM; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("\n");

    printf("The resultant sum matrix is\n");
    for (int i = 0; i < sizeM; i++)
    {
        for (int j = 0; j < sizeM; j++)
        {
            summatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", summatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
