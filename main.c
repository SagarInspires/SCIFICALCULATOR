#include <stdio.h>
// #include <conio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#define PI 3.1415926536
#define SIZE 10
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"
#define FOR(count) for (int i = 0; i < count; i++)
#define DELnxn(arr, n) \
    FOR(n)             \
    free(arr[i]);      \
    free(arr);
#define INITnxn(arr, n)                \
    (int **)malloc(n * sizeof(int *)); \
    FOR(n)                             \
    arr[i] = (int *)malloc(n * sizeof(int));
int resistance;
int MatrixOpn;
// double addition(double a, ...){
//     va_list args;
//     double sum = a;
//     va_start(args, a);
//     double arg;
//     while ((arg = va_arg(args, double)) != 0) sum += arg;
//     va_end(args);
//     return sum;
// }
void addition();
void subtraction();
void multipLication();
void division();

void factorial(double);
void modulus(double);
void square(double);
void squareroot(double);
void cube(double);
void SIN(double);
void COS(double);
void TAN(double);
void SININV(double);
void COSINV(double);
void TANINV(double);

// Function to calculate factorial
void factorial(double x)
{
    double result = 1.0;
    int i;

    if (x < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
        return;
    }

    for (i = 2; i <= x; ++i)
    {
        result *= i;
    }

    printf("Factorial of %.0f: %.0f\n", x, result);
}

// Function to calculate modulus
void modulus(double x)
{
    double result = fabs(x);
    printf("Modulus of %.2f: %.2f\n", x, result);
}

// Function to calculate square
void square(double x)
{
    double result = x * x;
    printf("Square of %.2f: %.2f\n", x, result);
}

// Function to calculate square root
void squareroot(double x)
{
    if (x < 0)
    {
        printf("Square root is not defined for negative numbers.\n");
        return;
    }

    double result = sqrt(x);
    printf("Square root of %.2f: %.2f\n", x, result);
}

// Function to calculate cube
void cube(double x)
{
    double result = x * x * x;
    printf("Cube of %.2f: %.2f\n", x, result);
}
// Function to calculate sine
void SIN(double x)
{
    printf("SIN(%.2f) = %.6f\n", x, sin(x * PI / 180));
}

// Function to calculate cosine
void COS(double x)
{
    printf("COS(%.2f) = %.6f\n", x, cos(x * PI / 180));
}

// Function to calculate tangent
void TAN(double x)
{
    printf("TAN(%.2f) = %.6f\n", x, tan(x * PI / 180));
}

// Function to calculate inverse sine
void SININV(double x)
{
    printf("SININV(%.6f) = %.2f\n", x, asin(x) * 180 / PI);
}

// Function to calculate inverse cosine
void COSINV(double x)
{
    printf("COSINV(%.6f) = %.2f\n", x, acos(x) * 180 / PI);
}

// Function to calculate inverse tangent
void TANINV(double x)
{
    printf("TANINV(%.6f) = %.2f\n", x, atan(x) * 180 / PI);
}

// void _print_nxn(int **arr, int n){}
void _print_mxn(int **arr, int m, int n)
{
    printf("[");
    FOR(m - 1)
    {
        printf("[");
        for (int j = 0; j < n - 1; j++)
            printf("%d, ", arr[i][j]);
        printf("%d]\n ", arr[i][n - 1]);
    }
    printf("[");
    for (int j = 0; j < n - 1; j++)
        printf("%d, ", arr[n - 1][j]);
    printf("%d]]\n\n", arr[n - 1][n - 1]);
}
void _print_n(int *arr, int n)
{
    printf("[");
    FOR(n - 1)
    printf("%d, ", arr[i]);
    printf("%d]\n ", arr[n - 1]);
}
// #define _print(arr, n, ...) _Generic((arr), \
//     int *: _print_n, \
//     int **: _Generic((n), \
//         int: _print_nxn, \
//         default: _print_mxn) \
// )(arr, n, ##__VA_ARGS__)
#define _print(arr, ...) _Generic(arr, int **: _print_mxn, int *: _print_n)(arr, __VA_ARGS__)

int determinant(int **arr, int n)
{
    int result = 0;
    if (n >= 2)
    {
        FOR(n)
        {
            int **tmp;
            int _n = n - 1;
            tmp = INITnxn(tmp, _n);
            for (int j = 1; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (i == k)
                        continue;
                    tmp[j - 1][k - ((i > k) ? 0 : 1)] = arr[j][k];
                }
            }
            result += (determinant(tmp, _n) * arr[0][i]) * ((i % 2) ? -1 : 1);
            DELnxn(tmp, _n);
        }
    }
    else
        result = arr[0][0];
    return result;
}

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

void MatrixOperations(int m1rows, int m2rows, int m1cols, int m2cols)
{
    int **matrix1;
    int **matrix2;
    int **summatrix;
    int **ProductMatrix;

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

    ProductMatrix = (int **)malloc(m1rows * sizeof(int));
    for (int i = 0; i < m1rows; i++)
    {
        ProductMatrix[i] = (int *)malloc(m2cols * sizeof(int));
        for (int j = 0; j < m2cols; j++)
        {
            ProductMatrix[i][j] = 0;
        }
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

    printf("Enter 0 for Addition. 1 for Multiplication\n");
    scanf("%d", &MatrixOpn);
    switch (MatrixOpn)
    {
    case 0:
        if ((m1rows == m2rows) && (m1cols == m2cols))
        {
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
        break;

    case 1:
        if (m1cols == m2rows)
        {
            printf("The Resultant Product Matrix of matrix 1 and matrix 2 is:\n");
            for (int i = 0; i < m1rows; i++)
            {
                for (int j = 0; j < m2cols; j++)
                {
                    // WE ARE iniating each element of product array as 0 in dynamkic memory allocation declaration then addition of other sums,
                    // as, in for loop. we must have to initialise with something , and zero here was better option as it is neutral thing we are initiating product ka 1st row element as zero because we have to take summation using for loop and initial value is required
                    // for this. So, we take it zero as after adding with zero every element of product matrix will be exact as 0+X=X from real analysis

                    for (int k = 0; k < m1cols; k++)
                    { // multiplication r1c1+r2c2+r3c3.. will go upto times, the number of rows in 2nd matrix
                        ProductMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
                    }

                    printf("%d  ", ProductMatrix[i][j]); // \t  can also be used for space of 6 integers almost provides space in right direction of workspace in typing area
                }

                printf("\n");
            }
        }
        else
        {
            printf("INVALID INPUT! Number of colums of matrix1 and number of rows of matrix2 not matched.\n");
        }
        break;
    default:
        printf("INVALID INPUT! Plz Amend and Try again\n");
        break;
    }
    free(matrix1);
    free(matrix2);
    free(summatrix);
    free(ProductMatrix);
}

// main function
int main()
{
    int sizeM;
    int CGsum = 0;
    int Csum = 0;
    float GPA;

    char *courses;
    int *credits;
    int *obtainedgrades;
    int number;
    int sqmatrix[100][100];

    int m1rows, m2rows, m1cols, m2cols;
    int birth_date, birth_month, birth_year;
    // Colors and their corresponding values
    int band1, band2, multiplier, tolerance;
    char *colorNames[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
    int colorValues[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float multipliers[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int toleranceValues[] = {20, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Tolerance values in percent

    printf(MAG "WELCOME TO OUR PROJECT CREATED BY GROUP P14- SCI-FI-CALCULATOR\n" RESET " We are \n"
               " 1. Nishanth Kumaran    ROLL NO: 2301PH12\n"
               " 2. MANISH KUMAR REDDY   ROLL NO:2301MC06\n"
               " 3. AWADHESH KUMAR SHARMA    ROLL NO: 2301ME63 \n"
               " 4. MITALI KUMARI   ROLL NO: 2301ME33\n"
               " 5. SAGAR KUMAR  ROLL NO: 2301MM28\n"
               " 6. LAKSH KUMAR SISODIYA   ROLL NO: 2302MC05\n 7."
               " KIRAN KUMAR BOMMU  ROLL NO: 2302VL03\n"
               " 8. SARAVAN KUMAR NALLAPU  ROLL NO: 2302ST07\n"
               " 9. SONALI KUMARI  ROLL NO: 2301EC31\n"
               " 10. AFIFAH KHAN  ROLL NO: 2302CM06\n");
    printf(BLU "-------------------------------------------------\n");
    printf("-------------------------------------------------\n");
    printf(CYN "Select the type of calculation you wish\n" RESET " Enter 1 for Resistor color code\n"
               " Enter 2 for Capacitor Color code\n"
               " Enter 3 for AgeCalculation Feature\n"
               " Enter 4 for Operating two matrices\n"
               " Enter 5 for Finding Determinant\n"
               " Enter 6 for GPA Calculation\n"
               " Enter 7 for GPA Calculation\n"
               " Enter 8 for CORE MATH Methods\n"
               " Option : ");
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
        // For multiplication of Matrices, number of cols of 1st matrix must be equal to number of rows of 2nd matrix
        MatrixOperations(m1rows, m2rows, m1cols, m2cols);
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

    case 5:
        int n;
        printf("Enter the size of the square matrix\n");
        scanf("%d", &n);
        printf("Enter the matrix: \n");
        int **arr;
        arr = INITnxn(arr, n);
        FOR(n)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
        printf("MATRIX IS:\n");
        _print(arr, n, n);
        printf("Determinant is :%d\n", determinant(arr, n));
        DELnxn(arr, n);
        break;

    case 6:
        // can we define new variables or array in side a switch case and use only those mentioned

        printf("Enter the number of courses\n");
        scanf("%d", &number);

        courses = (char *)malloc(number * sizeof(char));
        obtainedgrades = (int *)malloc(number * sizeof(int));
        credits = (int *)malloc(number * sizeof(int));

        printf("Enter the courses\n");
        for (int i = 0; i < number; i++)
        {
            scanf("%s", &courses[i]);
        }

        printf("Enter the credits of respective subjects\n");
        for (int i = 0; i < number; i++)
        {
            printf("The credits for %c is:", courses[i]);
            scanf("%d", &credits[i]);
            Csum = Csum + credits[i];
        }
        printf("Sum of the credits is %d.\n", Csum);
        printf("____________________________________\n");
        printf("____________________________________\n");
        printf("Enter the respective obtained grades e.g. AA-10, AB-9, BB-8, BC-7, CC-6, CD-5, DD-4:\n");
        for (int i = 0; i < number; i++)
        {
            scanf("%d", &obtainedgrades[i]);
            CGsum = CGsum + credits[i] * obtainedgrades[i];
        }

        printf("CG Sum is %d\n", CGsum);
        GPA = CGsum / Csum;
        printf("Hence, Your GPA is: %f\n", GPA);

        free(courses);
        free(obtainedgrades);
        free(credits);
        break;
    case 8:
        printf(GRN "\nBasic math functions\n" RESET
                   "x : ");
        int x;
        scanf("%d", &x);

        SIN(x);
        COS(x);
        TAN(x);
        SININV(x);
        COSINV(x);
        TANINV(x);

        factorial(x);
        modulus(x);
        square(x);
        squareroot(x);
        cube(x);
        break;
    default:
        printf("You have entered an Invalid Input.\n");
        break;
    }
    return 0;
}
