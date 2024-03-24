#include <stdio.h>
#include <math.h>
#include <time.h>
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
    while (digit1 >= 10)
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

    printf("Digit 1:      ");
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
    printf("\nDigit 2:      ");
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
    printf("\nMultiplier:   ");
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
    char *colors[] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Violet", "Grey", "White"};

    // Printing the decoded values
    printf("Capacitor Value: %d%d * 10^%d Farad\n", band1, band2, multiplier);
    printf("Tolerance: %d%%\n", tolerance);
}

void Agecalculator(int birth_date, int birth_month, int birth_year)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    // here we are getting local time from computer with date, month and year
    int current_date = tm.tm_mday;
    int current_month = tm.tm_mon + 1;
    int current_year = tm.tm_year + 1900;

    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // number of days in months
    if (birth_date > current_date)
    {
        current_date += month[birth_month - 1];
        current_month -= 1;
    }
    if (birth_month > current_month)
    {
        current_month += 12;
        current_year -= 1;
    }
    int calculated_days = current_date - birth_date;
    int calculated_months = current_month - birth_month;
    int calculated_years = current_year - birth_year;

    printf("\n Your Current Age is %d Years, %d Months, %d Days\n", calculated_years, calculated_months, calculated_days);
    return;
}

void MatrixAddition(int m1rows, int m2rows, int m1cols, int m2cols)
{
    int **matrix1;
    int **matrix2;
    int **summatrix;
    if ((m1rows == m2rows) && (m1cols == m2cols))
    {

        matrix1 = (int **)malloc(m1rows * sizeof(int *));
        for (int i = 0; i < m1rows; i++)
        {
            matrix1[i] = (int *)malloc(m1cols * sizeof(int));
        }

        // Allocate memory for matrix2
        matrix2 = (int **)malloc(m2rows * sizeof(int *));
        for (int i = 0; i < m2rows; i++)
        {
            matrix2[i] = (int *)malloc(m2cols * sizeof(int));
        }

        summatrix = (int **)malloc(m1rows * sizeof(int *));
        for (int i = 0; i < m1rows; i++)
        {
            summatrix[i] = (int *)malloc(m1cols * sizeof(int));
        }

        printf("Enter the matrix1\n");
        for (int i = 0; i < m1rows; i++)
        {
            for (int j = 0; j < m1cols; j++)
            {
                scanf("%d", &matrix1[i][j]);
            }
        }
        printf("Enter the matrix2\n");
        for (int i = 0; i < m1rows; i++)
        {
            for (int j = 0; j < m1cols; j++)
            {
                scanf("%d", &matrix2[i][j]);
            }
        }
        printf("\n");

        printf("The resultant sum matrix is:\n");
        for (int i = 0; i < m1rows; i++)
        {
            for (int j = 0; j < m1cols; j++)
            {
                summatrix[i][j] = matrix1[i][j] + matrix2[i][j];
                printf("%d ", summatrix[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("INVALID INPUT! Rows and Cols of Both Matrices must be equal.\n");
    }
}
// main function
int main()
{

    int m1rows, m2rows, m1cols, m2cols;
    int birth_date, birth_month, birth_year;
    // Colors and their corresponding values
    int band1, band2, multiplier, tolerance;
    char *colorNames[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
    int colorValues[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float multipliers[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int toleranceValues[] = {20, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Tolerance values in percent

    printf("WELCOME TO OUR PROJECT CREATED BY GROUP P14- SCI-FI-CALCULATOR\n We are \n 1. Nishanth Kumaran    ROLL NO: 2301PH12\n 2. MANISH KUMAR REDDY   ROLL NO:2301MC06\n 3. AWADHESH KUMAR SHARMA    ROLL NO: 2301ME63 \n 4. MITALI KUMARI   ROLL NO: 2301ME33\n 5. SAGAR KUMAR  ROLL NO: 2301MM28\n 6. LAKSH KUMAR SISODIYA   ROLL NO: 2302MC05\n  7. KIRAN KUMAR BOMMU  ROLL NO: 2302VL03\n 8. SARAVAN KUMAR NALLAPU  ROLL NO: 2302ST07\n 9. SONALI KUMARI  ROLL NO: 2301EC31\n 10. AFIFAH KHAN  ROLL NO: 2302CM06\n");
    printf("-------------------------------------------------\n");
    printf("-------------------------------------------------\n");
    printf("Select the type of calculation you wish\n Enter 1 for Resistor color code\n Enter 2 for Capacitor Color code\n Enter 3 for AgeCalculation Feature\n Enter 4 for Adding two matrices\n");
    // we can also do integration,differentiation,all type of calculation,
    //  age
    int option;
    scanf("%d", &option);
    
    switch (option)
    {

    case 1:
        printf("Enter the resistance value in ohms: ");
        scanf("%d", &resistance);
        Resistorcolorcode(resistance);
        break;

    case 2:

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
        break;

    case 4:

        printf("Enter the number of rows,columns of matrix1\n");
        scanf("%d %d", &m1rows, &m1cols);
        printf("Enter the number of rows,columns of matrix2\n");
        scanf("%d %d", &m2rows, &m2cols);
        // as we know only same dimension m x n matrices can be added, that is if m1=m2 and n1=n2 , then only matrices addition can be possible
        MatrixAddition(m1rows, m2rows, m1cols, m2cols);
        break;

    case 3:

        printf("\n");
        printf("\tWelcome to Age Calculator feature:-------------\n");
        printf("Enter your birth date:");
        scanf("%d", &birth_date);
        printf("Enter your birth month:");
        scanf("%d", &birth_month);
        printf("Enter your birth year:");
        scanf("%d", &birth_year);
        Agecalculator(birth_date, birth_month, birth_year);
        break;
    default:
        printf("You have entered an Invalid Input.\n");
        break;
    }
    return 0;
}
