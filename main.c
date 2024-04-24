#include <stdio.h>
// #include <conio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "server.h"

// to run in windows : `gcc main.c -L. -lserver && ./a.exe`

#define HOST "0.0.0.0" // "localhost"
#define PORT 5000
#define DEBUG 0

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

// Function prototypes
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double exponentiate(double x, double y);
double square_root(double x);
double cube_root(double x);
double nth_root(double x, double n);
double reciprocal(double x);
double factorialv2(int n);
double absolute_value(double x);
double percentage(double x);
double sine(double x);
double cosine(double x);
double tangent(double x);
double inverse_sine(double x);
double inverse_cosine(double x);
double inverse_tangent(double x);
double hyperbolic_sine(double x);
double hyperbolic_cosine(double x);
double hyperbolic_tangent(double x);
double natural_logarithm(double x);
double common_logarithm(double x);
double base_10_logarithm(double x);
double exponential_function(double x);
double power_of_10(double x);
double power_of_2(double x);

struct resistorcolor
{
    int first;
    int second;
    int multiplier;
    int tolerance;
};
struct resistorcolor getResistorcolorcode(int);
void home(server *self, str *response, list *headers, str *content_buffer)
{
    send_file(response, "templates/index.html");
}
void ResistorcolorcodeGET(server *self, str *response, list *headers, str *content_buffer)
{
    send_file(response, "templates/Resistorcolorcode.html");
}
void ResistorcolorcodePOST(server *self, str *response, list *headers, str *content_buffer)
{
    char body[content_buffer->length];
    content_buffer->raw(content_buffer, body);
    int value;

    // Search for the "value" key and extract the integer following it
    if (sscanf(body, "{\"value\":%d}", &value) != 1)
    {
        // Error handling if sscanf fails
        printf("Error: Unable to extract value from JSON string.\n");
        response->append(response, "HTTP/1.1 400 ERROR\r\n\r\n");
        return;
    }
    struct resistorcolor result = getResistorcolorcode(value);

    printf("RESISTOR (ohm) : %d\n", value);

    response->append(response, "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\n\r\n");
    response->append_format(response, "{\"colors\": [%d, %d, %d]}", result.first, result.second, result.multiplier);
}
void send_static(server *self, str *response, list *headers, str *content_buffer)
{
    int pos = findchar(headers->head->data->value, ' ');
    char url[pos];
    for (int i = 1; i < pos; i++)
        url[i - 1] = headers->head->data->value[i];
    url[pos - 1] = '\0';
    send_file(response, url);
}
void send_logo(server *self, str *response, list *headers, str *content_buffer)
{
    str header_buffer = String();
    header_buffer.append(&header_buffer, "HTTP/1.1 200 OK\r\n");
    header_buffer.append(&header_buffer, "Accept-Ranges: bytes\r\n");
    FILE *fptr;
    fptr = fopen("static/favicon.ico", "rb");
    if (fptr == NULL)
    {
        response->append(response, "HTTP/1.1 404 NOT FOUND\r\n\r\n");
        response->append(response, "ERROR : 404 NOT FOUND");
        fclose(fptr);
        return;
    }
    size_t file_size = get_file_size(fptr);
    // header_buffer.append(&header_buffer, "Content-Length: 50000\r\n");
    header_buffer.append(&header_buffer, "Content-Type: image/x-icon\r\n\r\n");
    char raw_header[header_buffer.length];
    header_buffer.raw(&header_buffer, raw_header);
    header_buffer.free(&header_buffer);
    send_file_with_header(response, "static/favicon.ico", raw_header);
    fclose(fptr);
}
void stop_server(server *self, str *response, list *headers, str *content_buffer)
{
    self->stop(self);
    response->append(response, "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\n\r\n");
    response->append(response, "{\"stop\": true}");
}

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

// Function to calculate exponential of a number
void exponential(double x) {
    printf("exp(%.6f) = %.6f\n", x, exp(x));
}

// Function to calculate natural logarithm of a number
void natural_log(double x) {
    printf("log(%.6f) = %.6f\n", x, log(x));
}

// Function to calculate base 10 logarithm of a number
void log_base_10(double x) {
    printf("log10(%.6f) = %.6f\n", x, log10(x));
}

// Function to calculate x raised to the power of y
void power(double x, double y) {
    printf("%.6f raised to the power %.6f = %.6f\n", x, y, pow(x, y));
}

// Function to round a number to the nearest integer
void round_nearest(double x) {
    printf("round(%.6f) = %.0f\n", x, round(x));
}

// Function to round a number down to the nearest integer
void round_down(double x) {
    printf("floor(%.6f) = %.0f\n", x, floor(x));
}

// Function to round a number up to the nearest integer
void round_up(double x) {
    printf("ceil(%.6f) = %.0f\n", x, ceil(x));
}

// Function to calculate hyperbolic sine
void hyperbolicSine(double x) {
    printf("sinh(%.6f) = %.6f\n", x, sinh(x));
}

// Function to calculate hyperbolic cosine
void hyperbolicCosine(double x) {
    printf("cosh(%.6f) = %.6f\n", x, cosh(x));
}

// Function to calculate hyperbolic tangent
void hyperbolicTangent(double x) {
    printf("tanh(%.6f) = %.6f\n", x, tanh(x));
}

// Function to generate a random number in a specified range
void generate_random(int min, int max) {
    int random_number = min + rand() % (max - min + 1);
    printf("Random number between %d and %d: %d\n", min, max, random_number);
}

double mean(int data[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += data[i];
    }
    return sum / n;
}

// Function to calculate median
double median(int data[], int n)
{
    int tempArray[n];
    for (int i = 0; i < n; i++)
    {
        tempArray[i] = data[i];
    }
    int middle = n / 2;
    if (n % 2 == 0)
    {
        return (tempArray[middle - 1] + tempArray[middle]) / 2.0;
    }
    else
    {
        return tempArray[middle];
    }
}

// Function to compare elements for qsort
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Function to calculate mode
double mode(int data[], int n)
{
    qsort(data, n, sizeof(int), compare);

    int modeCount = 0, maxCount = 0, modeValue = data[0], prevValue = data[0];

    for (int i = 1; i < n; i++)
    {
        if (data[i] == prevValue)
        {
            modeCount++;
        }
        else
        {
            if (modeCount > maxCount)
            {
                maxCount = modeCount;
                modeValue = prevValue;
            }
            modeCount = 1;
            prevValue = data[i];
        }
    }

    return modeValue;
}

// Function to calculate standard deviation
double standardDeviation(int data[], int n)
{
    double meanValue = mean(data, n);
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pow(data[i] - meanValue, 2);
    }
    return sqrt(sum / n);
}
// Function to calculate variance
double variance(int data[], int n)
{
    double meanValue = mean(data, n);
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pow(data[i] - meanValue, 2);
    }
    return sum / n;
}

float final_velocity(float u, float t, float a)
{
    float v = u + a * t;
    return v;
}

float displacement_with_time(float t, float u, float a)
{
    float s = u * t + 0.5 * a * t * t;
    return s;
}

float diplacement_with_velocity(float v, float u, float a)
{
    float x = v * v - u * u;
    float s = x / (a * 2);
    return s;
}
float finalvelocity_with_displacement(float s, float u, float a)
{
    float v = sqrt(2 * a * s + u * u);

    return v;
}

float acceleration(float u, float v, float t)
{
    float a = (v - u) / t;
    return a;
}

float Time(float a, float v, float u)
{
    float t = (v - u) / a;
    return t;
}

void resistorColorCodev2(int resistance)
{

    char *color[] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Violet", "Gray", "White"};
    char *multiplier[] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Violet", "Gray", "White"};
    char *tolerance[] = {"Brown", "Red", "Green", "Blue", "Violet", "Gray", "Gold", "Silver"};

    int digit1 = resistance / 100;
    int digit2 = (resistance / 10) % 10;
    int multiplierIdx = (int)log10(resistance) - 1;

    printf("Resistor Color Code:\n");
    printf("Digit 1: %s\n", color[digit1]);
    printf("Digit 2: %s\n", color[digit2]);
    printf("Multiplier: %s\n", multiplier[multiplierIdx]);

    printf("Tolerance: %s\n", tolerance[1]);
}

// Function to calculate capacitor code
void capacitorCode(double capacitance)
{
    // Array of capacitor codes
    char *code[] = {"pF", "nF", "uF", "mF"};

    // Calculating capacitor code index
    int idx = 0;
    while (capacitance >= 1000)
    {
        capacitance /= 1000;
        idx++;
    }

    // Displaying capacitor code
    printf("Capacitor Code: %.2f %s\n", capacitance, code[idx]);
}

// Function to calculate inductor code
void inductorCode(double inductance)
{
    // Array of inductor codes
    char *code[] = {"nH", "uH", "mH", "H"};

    // Calculating inductor code index
    int idx = 0;
    while (inductance >= 1000)
    {
        inductance /= 1000;
        idx++;
    }

    // Displaying inductor code
    printf("Inductor Code: %.2f %s\n", inductance, code[idx]);
}

// Function to calculate Ohm's Law (Voltage, Current, Resistance)
void ohmsLaw()
{
    double voltage, current, resistance;
    int choice;
    printf("Choose which values you have:\n");
    printf("1. Voltage and Resistance\n");
    printf("2. Current and Resistance\n");
    printf("3. Voltage and Current\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter Voltage (V): ");
        scanf("%lf", &voltage);
        printf("Enter Resistance (ohms): ");
        scanf("%lf", &resistance);
        current = voltage / resistance;
        printf("Current (A): %.2f\n", current);
        break;
    case 2:
        printf("Enter Current (A): ");
        scanf("%lf", &current);
        printf("Enter Resistance (ohms): ");
        scanf("%lf", &resistance);
        voltage = current * resistance;
        printf("Voltage (V): %.2f\n", voltage);
        break;
    case 3:
        printf("Enter Voltage (V): ");
        scanf("%lf", &voltage);
        printf("Enter Current (A): ");
        scanf("%lf", &current);
        resistance = voltage / current;
        printf("Resistance (ohms): %.2f\n", resistance);
        break;
    default:
        printf("Invalid choice.\n");
    }
}

// Function to calculate RC circuit time constant
void rcCircuitTimeConstant(double resistance, double capacitance)
{
    double timeConstant = resistance * capacitance;
    printf("RC Circuit Time Constant (Tau): %.2f seconds\n", timeConstant);
}

// Function to calculate RL circuit time constant
void rlCircuitTimeConstant(double resistance, double inductance)
{
    double timeConstant = resistance / inductance;
    printf("RL Circuit Time Constant (Tau): %.2f seconds\n", timeConstant);
}

// Function to calculate resonant frequency of LC circuit
void resonantFrequency(double inductance, double capacitance)
{
    double frequency = 1 / (2 * PI * sqrt(inductance * capacitance));
    printf("Resonant Frequency: %.2f Hz\n", frequency);
}

// Function to design low-pass filter
void lowPassFilter(double cutoffFrequency)
{
    printf("Low-pass filter designed with a cutoff frequency of %.2f Hz\n", cutoffFrequency);
}

// Function to calculate impedance of RLC circuit
void rlcCircuitImpedance(double resistance, double inductance, double capacitance)
{
    double impedance = sqrt(pow(resistance, 2) + pow((1 / (2 * PI * capacitance)), 2));
    printf("RLC Circuit Impedance: %.2f ohms\n", impedance);
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

int length_converter()
{
    // 1.LENGTH CONVERSION
    float length, convertedLength;
    int choice;

    printf("Enter the length: ");
    scanf("%f", &length);

    printf("Choose the conversion:\n");
    printf("1. Meters to Centimeters\n");
    printf("2. Centimeters to Meters\n");
    printf("3. Meters to Inches\n");
    printf("4. Inches to Meters\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        convertedLength = length * 100; // meters to centimeters
        printf("%.2f meters is equal to %.2f centimeters.\n", length, convertedLength);
        break;
    case 2:
        convertedLength = length / 100; // centimeters to meters
        printf("%.2f centimeters is equal to %.2f meters.\n", length, convertedLength);
        break;
    case 3:
        convertedLength = length * 39.37; // meters to inches
        printf("%.2f meters is equal to %.2f inches.\n", length, convertedLength);
        break;
    case 4:
        convertedLength = length / 39.37; // inches to meters
        printf("%.2f inches is equal to %.2f meters.\n", length, convertedLength);
        break;
    case 5:
        printf("Exiting...\n");
        return 0;
    default:
        printf("Invalid choice.\n");
    }
}
int area_converter()
{
    float area, convertedArea;
    int choice;

    printf("Enter the area: ");
    scanf("%f", &area);

    printf("Choose the conversion:\n");
    printf("1. Square Meters to Square Centimeters\n");
    printf("2. Square Centimeters to Square Meters\n");
    printf("3. Square Meters to Square Feet\n");
    printf("4. Square Feet to Square Meters\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        convertedArea = area * 10000; // square meters to square centimeters
        printf("%.2f square meters is equal to %.2f square centimeters.\n", area, convertedArea);
        break;
    case 2:
        convertedArea = area / 10000; // square centimeters to square meters
        printf("%.2f square centimeters is equal to %.2f square meters.\n", area, convertedArea);
        break;
    case 3:
        convertedArea = area * 10.764; // square meters to square feet
        printf("%.2f square meters is equal to %.2f square feet.\n", area, convertedArea);
        break;
    case 4:
        convertedArea = area / 10.764; // square feet to square meters
        printf("%.2f square feet is equal to %.2f square meters.\n", area, convertedArea);
        break;
    case 5:
        printf("Exiting...\n");
        return 0;
    default:
        printf("Invalid choice.\n");
    }
}
int volume_converter()
{
    float volume, convertedVolume;
    int choice;

    printf("Enter the volume: ");
    scanf("%f", &volume);

    printf("Choose the conversion:\n");
    printf("1. Cubic Meters to Liters\n");
    printf("2. Liters to Cubic Meters\n");
    printf("3. Cubic Meters to Cubic Feet\n");
    printf("4. Cubic Feet to Cubic Meters\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        convertedVolume = volume * 1000; // cubic meters to liters
        printf("%.2f cubic meters is equal to %.2f liters.\n", volume, convertedVolume);
        break;
    case 2:
        convertedVolume = volume / 1000; // liters to cubic meters
        printf("%.2f liters is equal to %.2f cubic meters.\n", volume, convertedVolume);
        break;
    case 3:
        convertedVolume = volume * 35.315; // cubic meters to cubic feet
        printf("%.2f cubic meters is equal to %.2f cubic feet.\n", volume, convertedVolume);
        break;
    case 4:
        convertedVolume = volume / 35.315; // cubic feet to cubic meters
        printf("%.2f cubic feet is equal to %.2f cubic meters.\n", volume, convertedVolume);
        break;
    case 5:
        printf("Exiting...\n");
        return 0;
    default:
        printf("Invalid choice.\n");
    }
}
int mass_converter()
{
    float mass, convertedMass;
    int choice;

    printf("Enter the mass: ");
    scanf("%f", &mass);

    printf("Choose the conversion:\n");
    printf("1. Kilograms to Grams\n");
    printf("2. Grams to Kilograms\n");
    printf("3. Kilograms to Pounds\n");
    printf("4. Pounds to Kilograms\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        convertedMass = mass * 1000; // kilograms to grams
        printf("%.2f kilograms is equal to %.2f grams.\n", mass, convertedMass);
        break;
    case 2:
        convertedMass = mass / 1000; // grams to kilograms
        printf("%.2f grams is equal to %.2f kilograms.\n", mass, convertedMass);
        break;
    case 3:
        convertedMass = mass * 2.20462; // kilograms to pounds
        printf("%.2f kilograms is equal to %.2f pounds.\n", mass, convertedMass);
        break;
    case 4:
        convertedMass = mass / 2.20462; // pounds to kilograms
        printf("%.2f pounds is equal to %.2f kilograms.\n", mass, convertedMass);
        break;
    case 5:
        printf("Exiting...\n");
        return 0;
    default:
        printf("Invalid choice.\n");
    }
}
int temp_converter()
{
    float temperature, convertedTemperature;
    int choice;

    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    printf("Choose the conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        convertedTemperature = (temperature * 9 / 5) + 32; // Celsius to Fahrenheit
        printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature, convertedTemperature);
        break;
    case 2:
        convertedTemperature = (temperature - 32) * 5 / 9; // Fahrenheit to Celsius
        printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", temperature, convertedTemperature);
        break;
    case 3:
        convertedTemperature = temperature + 273.15; // Celsius to Kelvin
        printf("%.2f Celsius is equal to %.2f Kelvin.\n", temperature, convertedTemperature);
        break;
    case 4:
        convertedTemperature = temperature - 273.15; // Kelvin to Celsius
        printf("%.2f Kelvin is equal to %.2f Celsius.\n", temperature, convertedTemperature);
        break;
    case 5:
        convertedTemperature = (temperature + 459.67) * 5 / 9; // Fahrenheit to Kelvin
        printf("%.2f Fahrenheit is equal to %.2f Kelvin.\n", temperature, convertedTemperature);
        break;
    case 6:
        convertedTemperature = (temperature * 9 / 5) - 459.67; // Kelvin to Fahrenheit
        printf("%.2f Kelvin is equal to %.2f Fahrenheit.\n", temperature, convertedTemperature);
        break;
    case 7:
        printf("Exiting...\n");
        return 0;
    default:
        printf("Invalid choice.\n");
    }
}
int time_converter()
{
    float time, convertedTime;
    int choice;

    printf("Enter the time: ");
    scanf("%f", &time);

    printf("Choose the conversion:\n");
    printf("1. Hours to Minutes\n");
    printf("2. Minutes to Hours\n");
    printf("3. Hours to Seconds\n");
    printf("4. Seconds to Hours\n");
    printf("5. Minutes to Seconds\n");
    printf("6. Seconds to Minutes\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        convertedTime = time * 60; // hours to minutes
        printf("%.2f hours is equal to %.2f minutes.\n", time, convertedTime);
        break;
    case 2:
        convertedTime = time / 60; // minutes to hours
        printf("%.2f minutes is equal to %.2f hours.\n", time, convertedTime);
        break;
    case 3:
        convertedTime = time * 3600; // hours to seconds
        printf("%.2f hours is equal to %.2f seconds.\n", time, convertedTime);
        break;
    case 4:
        convertedTime = time / 3600; // seconds to hours
        printf("%.2f seconds is equal to %.2f hours.\n", time, convertedTime);
        break;
    case 5:
        convertedTime = time * 60; // minutes to seconds
        printf("%.2f minutes is equal to %.2f seconds.\n", time, convertedTime);
        break;
    case 6:
        convertedTime = time / 60; // seconds to minutes
        printf("%.2f seconds is equal to %.2f minutes.\n", time, convertedTime);
        break;
    case 7:
        printf("Exiting...\n");
        return 0;
    default:
        printf("Invalid choice.\n");
    }
}
int speed_converter()
{
    float speed, convertedSpeed;
    int choice;

    printf("Enter the speed: ");
    scanf("%f", &speed);

    printf("Choose the conversion:\n");
    printf("1. Kilometers per Hour to Meters per Second\n");
    printf("2. Meters per Second to Kilometers per Hour\n");
    printf("3. Miles per Hour to Meters per Second\n");
    printf("4. Meters per Second to Miles per Hour\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        convertedSpeed = speed * 0.2778; // kilometers per hour to meters per second
        printf("%.2f kilometers per hour is equal to %.2f meters per second.\n", speed, convertedSpeed);
        break;
    case 2:
        convertedSpeed = speed / 0.2778; // meters per second to kilometers per hour
        printf("%.2f meters per second is equal to %.2f kilometers per hour.\n", speed, convertedSpeed);
        break;
    case 3:
        convertedSpeed = speed * 0.447; // miles per hour to meters per second
        printf("%.2f miles per hour is equal to %.2f meters per second.\n", speed, convertedSpeed);
        break;
    case 4:
        convertedSpeed = speed / 0.447; // meters per second to miles per hour
        printf("%.2f meters per second is equal to %.2f miles per hour.\n", speed, convertedSpeed);
        break;
    case 5:
        printf("Exiting...\n");
        return 0;
    default:
        printf("Invalid choice.\n");
    }
}
int pressure_converter()
{
    float pressure, convertedPressure;
    int choice;

    printf("Enter the pressure: ");
    scanf("%f", &pressure);

    printf("Choose the conversion:\n");
    printf("1. Pascals to Kilopascals\n");
    printf("2. Kilopascals to Pascals\n");
    printf("3. Pascals to Bar\n");
    printf("4. Bar to Pascals\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        convertedPressure = pressure * 0.001; // pascals to kilopascals
        printf("%.2f pascals is equal to %.2f kilopascals.\n", pressure, convertedPressure);
        break;
    case 2:
        convertedPressure = pressure * 1000; // kilopascals to pascals
        printf("%.2f kilopascals is equal to %.2f pascals.\n", pressure, convertedPressure);
        break;
    case 3:
        convertedPressure = pressure * 0.00001; // pascals to bar
        printf("%.2f pascals is equal to %.2f bar.\n", pressure, convertedPressure);
        break;
    case 4:
        convertedPressure = pressure * 100000; // bar to pascals
        printf("%.2f bar is equal to %.2f pascals.\n", pressure, convertedPressure);
        break;
    case 5:
        printf("Exiting...\n");
        return 0;
    default:
        printf("Invalid choice.\n");
    }
}
int energy_converter()
{
    float energy, convertedEnergy;
    int choice;

    printf("Enter the energy: ");
    scanf("%f", &energy);

    printf("Choose the conversion:\n");
    printf("1. Joules to Calories\n");
    printf("2. Calories to Joules\n");
    printf("3. Joules to Kilowatt-hours\n");
    printf("4. Kilowatt-hours to Joules\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        convertedEnergy = energy * 0.239; // joules to calories
        printf("%.2f joules is equal to %.2f calories.\n", energy, convertedEnergy);
        break;
    case 2:
        convertedEnergy = energy / 0.239; // calories to joules
        printf("%.2f calories is equal to %.2f joules.\n", energy, convertedEnergy);
        break;
    case 3:
        convertedEnergy = energy * 2.778e-7; // joules to kilowatt-hours
        printf("%.2f joules is equal to %.10f kilowatt-hours.\n", energy, convertedEnergy);
        break;
    case 4:
        convertedEnergy = energy / 2.778e-7; // kilowatt-hours to joules
        printf("%.10f kilowatt-hours is equal to %.2f joules.\n", energy, convertedEnergy);
        break;
    case 5:
        printf("Exiting...\n");
        return 0;
    default:
        printf("Invalid choice.\n");
    }
}
int power_converter()
{
    float power, convertedPower;
    int choice;

    printf("Enter the power: ");
    scanf("%f", &power);

    printf("Choose the conversion:\n");
    printf("1. Watts to Kilowatts\n");
    printf("2. Kilowatts to Watts\n");
    printf("3. Watts to Horsepower\n");
    printf("4. Horsepower to Watts\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        convertedPower = power * 0.001; // watts to kilowatts
        printf("%.2f watts is equal to %.2f kilowatts.\n", power, convertedPower);
        break;
    case 2:
        convertedPower = power * 1000; // kilowatts to watts
        printf("%.2f kilowatts is equal to %.2f watts.\n", power, convertedPower);
        break;
    case 3:
        convertedPower = power * 0.001341; // watts to horsepower
        printf("%.2f watts is equal to %.2f horsepower.\n", power, convertedPower);
        break;
    case 4:
        convertedPower = power / 0.001341; // horsepower to watts
        printf("%.2f horsepower is equal to %.2f watts.\n", power, convertedPower);
        break;
    case 5:
        printf("Exiting...\n");
        return 0;
    default:
        printf("Invalid choice.\n");
    }
}
int angle_converter()
{
    float angle, convertedAngle;
    int choice;

    printf("Enter the angle: ");
    scanf("%f", &angle);

    printf("Choose the conversion:\n");
    printf("1. Degrees to Radians\n");
    printf("2. Radians to Degrees\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        convertedAngle = angle * 0.0174533; // degrees to radians
        printf("%.2f degrees is equal to %.2f radians.\n", angle, convertedAngle);
        break;
    case 2:
        convertedAngle = angle * 57.2958; // radians to degrees
        printf("%.2f radians is equal to %.2f degrees.\n", angle, convertedAngle);
        break;
    case 3:
        printf("Exiting...\n");
        return 0;
    default:
        printf("Invalid choice.\n");
    }
}
int force_converter()
{
    float angle, convertedAngle;
    int choice;

    printf("Enter the angle: ");
    scanf("%f", &angle);

    printf("Choose the conversion:\n");
    printf("1. Degrees to Radians\n");
    printf("2. Radians to Degrees\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        convertedAngle = angle * 0.0174533; // degrees to radians
        printf("%.2f degrees is equal to %.2f radians.\n", angle, convertedAngle);
        break;
    case 2:
        convertedAngle = angle * 57.2958; // radians to degrees
        printf("%.2f radians is equal to %.2f degrees.\n", angle, convertedAngle);
        break;
    case 3:
        printf("Exiting...\n");
        return 0;
    default:
        printf("Invalid choice.\n");
    }
}
int math_calcu()
{
    double num1, num2, result;
    char operation[10];
    printf("operations  (+, -, *, /, ^, sqrt, cbrt, root, rec, fact, abs, %%, sin, cos, tan, asin, acos, atan, sinh, cosh, tanh, ln, log, log10, exp, 10^x, 2^x): \n");
    while (1)
    {
        // Prompt user for number
        printf("Enter number (or 'exit' to quit): ");
        if (scanf("%lf", &num1) == 0)
        {
            // Invalid input, clear input buffer
            scanf("%*s");
            continue;
        }

        // Check if user wants to exit
        if (strcmp(operation, "exit") == 0)
        {
            printf("Exiting...\n");
            break;
        }

        while (1)
        {

            scanf("%s", operation);

            // Check if user wants to exit or continue with the calculation
            if (strcmp(operation, "exit") == 0)
            {
                printf("Exiting...\n");
                return 0;
            }
            else if (strcmp(operation, "#") == 0 || strcmp(operation, "*") == 0)
            {
                break;
            }

            // Perform different operations based on user input
            switch (operation[0])
            {
            case '+':
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = add(num1, num2);
                printf("%.2f + %.2f = %.2f\n", num1, num2, result);
                num1 = result;
                break;
            case '-':
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = subtract(num1, num2);
                printf("%.2f - %.2f = %.2f\n", num1, num2, result);
                num1 = result;
                break;
            case '*':
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = multiply(num1, num2);
                printf("%.2f * %.2f = %.2f\n", num1, num2, result);
                num1 = result;
                break;
            case '/':
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = divide(num1, num2);
                printf("%.2f / %.2f = %.2f\n", num1, num2, result);
                num1 = result;
                break;
            case '^':
                printf("Enter exponent: ");
                scanf("%lf", &num2);
                result = exponentiate(num1, num2);
                printf("%.2f ^ %.2f = %.2f\n", num1, num2, result);
                num1 = result;
                break;
            case 's':
                if (strcmp(operation, "sqrt") == 0)
                {
                    result = square_root(num1);
                    printf("sqrt(%.2f) = %.2f\n", num1, result);
                }
                else if (strcmp(operation, "sin") == 0)
                {
                    result = sine(num1);
                    printf("sin(%.2f) = %.2f\n", num1, result);
                }
                else
                {
                    printf("Invalid operation.\n");
                }
                num1 = result;
                break;
            case 'c':
                if (strcmp(operation, "cbrt") == 0)
                {
                    result = cube_root(num1);
                    printf("cbrt(%.2f) = %.2f\n", num1, result);
                }
                else if (strcmp(operation, "cos") == 0)
                {
                    result = cosine(num1);
                    printf("cos(%.2f) = %.2f\n", num1, result);
                }
                else
                {
                    printf("Invalid operation.\n");
                }
                num1 = result;
                break;
            case 't':
                if (strcmp(operation, "tan") == 0)
                {
                    result = tangent(num1);
                    printf("tan(%.2f) = %.2f\n", num1, result);
                }
                else if (strcmp(operation, "root") == 0)
                {
                    printf("Enter root: ");
                    scanf("%lf", &num2);
                    result = nth_root(num1, num2);
                    printf("root(%.2f, %.2f) = %.2f\n", num1, num2, result);
                }
                else if (strcmp(operation, "rec") == 0)
                {
                    result = reciprocal(num1);
                    printf("rec(%.2f) = %.2f\n", num1, result);
                }
                else if (strcmp(operation, "tanh") == 0)
                {
                    result = hyperbolic_tangent(num1);
                    printf("tanh(%.2f) = %.2f\n", num1, result);
                }
                else
                {
                    printf("Invalid operation.\n");
                }
                num1 = result;
                break;
            case 'f':
                if (strcmp(operation, "fact") == 0)
                {
                    result = factorialv2((int)num1);
                    printf("fact(%.2f) = %.2f\n", num1, result);
                }
                else
                {
                    printf("Invalid operation.\n");
                }
                num1 = result;
                break;
            case 'a':
                if (strcmp(operation, "abs") == 0)
                {
                    result = absolute_value(num1);
                    printf("abs(%.2f) = %.2f\n", num1, result);
                }
                else if (strcmp(operation, "asin") == 0)
                {
                    result = inverse_sine(num1);
                    printf("asin(%.2f) = %.2f\n", num1, result);
                }
                else if (strcmp(operation, "acos") == 0)
                {
                    result = inverse_cosine(num1);
                    printf("acos(%.2f) = %.2f\n", num1, result);
                }
                else
                {
                    printf("Invalid operation.\n");
                }
                num1 = result;
                break;
            case 'p':
                if (strcmp(operation, "%") == 0)
                {
                    result = percentage(num1);
                    printf("%.2f%% = %.2f\n", num1, result);
                }
                else if (strcmp(operation, "pow") == 0)
                {
                    printf("Enter power: ");
                    scanf("%lf", &num2);
                    result = power_of_10(num1);
                    printf("10^(%.2f) = %.2f\n", num1, result);
                }
                else
                {
                    printf("Invalid operation.\n");
                }
                num1 = result;
                break;
            case 'l':
                if (strcmp(operation, "ln") == 0)
                {
                    result = natural_logarithm(num1);
                    printf("ln(%.2f) = %.2f\n", num1, result);
                }
                else if (strcmp(operation, "log") == 0)
                {
                    result = common_logarithm(num1);
                    printf("log(%.2f) = %.2f\n", num1, result);
                }
                else if (strcmp(operation, "log10") == 0)
                {
                    result = base_10_logarithm(num1);
                    printf("log10(%.2f) = %.2f\n", num1, result);
                }
                else
                {
                    printf("Invalid operation.\n");
                }
                num1 = result;
                break;
            case 'e':
                if (strcmp(operation, "exp") == 0)
                {
                    result = exponential_function(num1);
                    printf("exp(%.2f) = %.2f\n", num1, result);
                }
                else
                {
                    printf("Invalid operation.\n");
                }
                num1 = result;
                break;
            default:
                printf("Invalid operation.\n");
            }
        }
    }
}

// prime number functions
void PrimeFactorization(int num)
{
    printf("Prime factors of the number : ");
    for (int i = 2; num > 1; i++)
    {
        while (num % i == 0)
        {
            printf("%d ", i);
            num = num / i;
        }
    }
}
// primality test function
int Mulmod(long long a, long long b, long long mod)
{
    long long x = 0, y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return (x % mod);
}
int modulo(long long base, long long exponent, long long mod)
{
    long long x = 1;
    long long y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            x = (x * y) % mod;
        }
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return (x % mod);
}
int Primalitytest(long long p, int iteration)
{
    int i;
    long long s;
    if (p < 2)
    {
        return 0;
    }
    if (p != 2 && p % 2 == 0)
    {
        return 0;
    }
    s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (i = 0; i < iteration; i++)
    {
        long long a = rand() % (p - 1) + 1, temp = s;
        long long mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = Mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            printf("not prime ");
        }
    }
    printf("prime ");
}
// for next & previous prime
int isprime(int n)
{
    int i, temp = 0;
    for (i = 2; i <= (n / 2); i++)
    {
        if (n % i == 0)
        {
            temp++;
            break;
        }
    }
    if (temp != 0 && n != 1)
    {
        return (0);
    }
    else
        return (1);
}
void Nextprime(int n)
{
    int prime = n, check = 0, t;
    while (check != 1)
    {
        prime++;
        t = isprime(prime);
        if (t == 1)
        {
            printf("\n Prime number after this number is : %d", prime);
            break;
        }
    }
}
void Previousprime(int n)
{
    int prime = n, check = 0, t;
    while (check != 1)
    {
        prime--;
        t = isprime(prime);
        if (t == 1)
        {
            printf("\n Prime number before this number is :%d", prime);
            break;
        }
    }
}
// prime number functions ended
// bitwise operator functions started
void bitwise_and(int num1, int num2)
{
    int a[10], i;
    int res = num1 & num2;
    for (i = 0; res > 0; i++)
    {
        a[i] = res % 2;
        res = res / 2;
    }
    printf("\n and operation result is");
    int z = 0;
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", a[i]);
        z++;
    }
    printf("\n");
    if (z == 0)
        printf(" 0 \n");
}
void bitwise_or(int num1, int num2)
{
    int a[10], i;
    int res = num1 | num2;
    for (i = 0; res > 0; i++)
    {
        a[i] = res % 2;
        res = res / 2;
    }
    printf("\n or operation result is");
    int z = 0;
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
        z++;
    }
    printf("\n");
    if (z == 0)
        printf(" 0 \n");
}
void bitwise_xor(int num1, int num2)
{
    int a[10], i;
    int res = num1 ^ num2;
    for (i = 0; res > 0; i++)
    {
        a[i] = res % 2;
        res = res / 2;
    }
    printf("\n xor operation result is");
    int z = 0;
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
        z++;
    }
    printf("\n");
    if (z == 0)
        printf(" 0 \n");
}
void bitwise_lshift(int num1, int num2)
{
    int a[10], i;
    int res = num1 << num2;
    for (i = 0; res > 0; i++)
    {
        a[i] = res % 2;
        res = res / 2;
    }
    printf("\n lshift operation result is");
    int z = 0;
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", a[i]);
        z++;
    }
    printf("\n");
    if (z == 0)
        printf(" 0 \n");
}
void bitwise_rshift(int num1, int num2)
{
    int binaryNum[10], i;
    int res = num1 >> num2;
    i = 0;
    while (res > 0)
    {
        // storing remainder in binary array
        binaryNum[i] = res % 2;
        res = res / 2;
        i++;
    }

    // printing binary array in reverse order
    int z = 0;
    for (int j = i - 1; j >= 0; j--)
    {

        printf("\n r shift operation result is %d", binaryNum[j]);
        z++;
    }
    if (z == 0)
        printf("\nrshift operation result is 0");
}

// main function
int main()
{
    int sizeM;
    int CGsum = 0;
    int Csum = 0;
    int n;
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

    server app = http_server();
    app.route(&app, "GET", "/", home);
    app.route(&app, "GET", "/stop", stop_server);
    app.route(&app, "GET", "/Resistorcolorcode", ResistorcolorcodeGET);
    app.route(&app, "POST", "/Resistorcolorcode", ResistorcolorcodePOST);
    app.route(&app, "GET", "/favicon.ico", send_logo);
    app.route(&app, "GET", "/static/*", send_static);

    printf(MAG "WELCOME TO OUR PROJECT CREATED BY GROUP P14- SCI-FI-CALCULATOR\n" RESET " We are \n"
               " 1. Nishanth Kumaran    ROLL NO: 2301PH12\n"
               " 2. MANISH KUMAR REDDY   ROLL NO:2301MC06\n"
               " 3. AWADHESH KUMAR SHARMA    ROLL NO: 2301ME63 \n"
               " 4. MITALI KUMARI   ROLL NO: 2301ME33\n"
               " 5. SAGAR KUMAR  ROLL NO: 2301MM28\n"
               " 6. LAKSH KUMAR SISODIYA   ROLL NO: 2302MC05\n"
               " 7. KIRAN KUMAR BOMMU  ROLL NO: 2302VL03\n"
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
               " Enter 7 for random number\n"
               " Enter 8 for CORE MATH Methods\n"
               " Enter 9 for statistics\n"
               " Enter 10 for Physics\n"
               " Enter 11 for Electronic\n"
               " Enter 12 for MATH Calculator\n"
               " Enter 13 for Prime Number Functions \n"
               " Enter 14 for Bitwise Operations \n"
               " Enter 99 for BETA GUI (AT PRESENT ONE FUNCTION IS WORKING)\n"
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
    case 7:
        printf(GRN "\nRandom Number generator\n" RESET
                   "How many numbers you want to generate : ");
        int _x, _min, _max;
        scanf("%d", &_x);
        printf("min: ");
        scanf("%d", &_min);
        printf("max: ");
        scanf("%d", &_max);
        
        for (int i = 0; i < _x; i++)
        {
            printf("%d\t", i);
            generate_random(_min, _max);
        }
        
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

        exponential(x);
        natural_log(x);
        log_base_10(x);
        power(PI, x);
        round_nearest(x);
        round_down(x);
        round_up(x);

        hyperbolicSine(x);
        hyperbolicCosine(x);
        hyperbolicTangent(x);

        break;
    case 9:
        printf("Enter the number of elements in the dataset: ");
        scanf("%d", &n);

        int *data = (int *)malloc(n * sizeof(int));

        printf("Enter the elements of the dataset:\n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &data[i]);
        }

        printf("Mean: %.2f\n", mean(data, n));
        printf("Median: %.2f\n", median(data, n));
        printf("Mode: %.2f\n", mode(data, n));
        printf("Standard Deviation: %.2f\n", standardDeviation(data, n));
        printf("Variance: %.2f\n", variance(data, n));

        free(data);

        break;
    case 10:
        printf("select the option\n");
        printf("1: final velocity with time\n");
        printf("2: displacement with time\n");
        printf("3: displacement with final velocity\n");
        printf("4: final velocity with displacement\n");
        printf("5: acceleration\n");
        printf("6: time\n");
        printf("7: length_converter\n");
        printf("8: area_converter\n");
        printf("9: volume_converter\n");
        printf("10: mass_converter\n");
        printf("11: temp_converter\n");
        printf("12: time_converter\n");
        printf("13: speed_converter\n");
        printf("14: pressure_converter\n");
        printf("15: energy_converter\n");
        printf("16: power_converter\n");
        printf("17: angle_converter\n");
        printf("18: force_converter\n");
        printf("enter the choice\n");
        int physics;
        float u, v, a, t, s;
        scanf("%d", &physics);
        switch (physics)
        {

        case 1:

            printf("enter the initial velocity: ");
            scanf("%f", &u);
            printf("enter the time: ");
            scanf("%f", &t);
            printf("enter the acceleration: ");
            scanf("%f", &a);

            v = final_velocity(u, t, a);

            printf(" final velocity is :%f", v);

            break;
        case 2:

            printf("enter the initial velocity: ");
            scanf("%f", &u);
            printf("enter the time: ");
            scanf("%f", &t);
            printf("enter the acceleration: ");
            scanf("%f", &a);

            s = displacement_with_time(t, u, a);

            printf(" final displacement is :%f", s);

            break;
        case 3:

            printf("enter the initial velocity: ");
            scanf("%f", &u);
            printf("enter the final velocity: ");
            scanf("%f", &v);
            printf("enter the acceleration: ");
            scanf("%f", &a);

            s = diplacement_with_velocity(v, u, a);

            printf(" final displacement is : %f", s);

            break;

        case 4:

            printf("enter the initial velocity: ");
            scanf("%f", &u);
            printf("enter the displacement: ");
            scanf("%f", &s);
            printf("enter the acceleration: ");
            scanf("%f", &a);

            v = finalvelocity_with_displacement(s, u, a);
            printf(" final velocity is : %f", v);
            break;
        case 5:

            printf("enter the initial velocity: ");
            scanf("%f", &u);
            printf("enter the final velocity: ");
            scanf("%f", &v);
            printf("enter the time: ");
            scanf("%f", &t);

            a = acceleration(u, v, t);
            printf("acceleration is : %f", a);
            break;
        case 6:
            printf("enter the initial velocity: ");
            scanf("%f", &u);
            printf("enter the final velocity: ");
            scanf("%f", &v);
            printf("enter the acceleration: ");
            scanf("%f", &a);

            t = Time(a, v, u);
            printf("time taken : %f", t);

            break;
        case 7:
            length_converter();
            break;
        case 8:
            area_converter();
            break;
        case 9:
            volume_converter();
            break;
        case 10:
            mass_converter();
            break;
        case 11:
            temp_converter();
            break;
        case 12:
            time_converter();
            break;
        case 13:
            speed_converter();
            break;
        case 14:
            pressure_converter();
            break;
        case 15:
            energy_converter();
            break;
        case 16:
            power_converter();
            break;
        case 17:
            angle_converter();
            break;
        case 18:
            force_converter();
            break;
        }
        break;
    case 11:
        int electonics;
        double value1, value2, capacitance;

        printf("Electronic Engineering Functions\n");
        printf("1. Resistor Color Code\n");
        printf("2. Capacitor Code\n");
        printf("3. Inductor Code\n");
        printf("4. Ohm's Law\n");
        printf("5. RC Circuit Time Constant\n");
        printf("6. RL Circuit Time Constant\n");
        printf("7. Resonant Frequency of LC Circuit\n");
        printf("8. Design Low-pass Filter\n");
        printf("9. Impedance of RLC Circuit\n");
        printf("Enter your choice: ");
        scanf("%d", &electonics);

        switch (electonics)
        {
        case 1:
            printf("Enter resistance value in ohms: ");
            scanf("%lf", &value1);
            resistorColorCodev2((int)value1);
            break;
        case 2:
            printf("Enter capacitance value in farads: ");
            scanf("%lf", &value1);
            capacitorCode(value1);
            break;
        case 3:
            printf("Enter inductance value in henrys: ");
            scanf("%lf", &value1);
            inductorCode(value1);
            break;
        case 4:
            ohmsLaw();
            break;
        case 5:
            printf("Enter resistance value in ohms: ");
            scanf("%lf", &value1);
            printf("Enter capacitance value in farads: ");
            scanf("%lf", &value2);
            rcCircuitTimeConstant(value1, value2);
            break;
        case 6:
            printf("Enter resistance value in ohms: ");
            scanf("%lf", &value1);
            printf("Enter inductance value in henrys: ");
            scanf("%lf", &value2);
            rlCircuitTimeConstant(value1, value2);
            break;
        case 7:
            printf("Enter inductance value in henrys: ");
            scanf("%lf", &value1);
            printf("Enter capacitance value in farads: ");
            scanf("%lf", &value2);
            resonantFrequency(value1, value2);
            break;
        case 8:
            printf("Enter cutoff frequency value in Hz: ");
            scanf("%lf", &value1);
            lowPassFilter(value1);
            break;
        case 9:
            printf("Enter resistance value in ohms: ");
            scanf("%lf", &value1);
            printf("Enter inductance value in henrys: ");
            scanf("%lf", &value2);
            printf("Enter capacitance value in farads: ");
            scanf("%lf", &capacitance);
            rlcCircuitImpedance(value1, value2, capacitance);
            break;
        default:
            printf("Invalid choice.\n");
        }

        break;
    case 12:
        math_calcu();
        break;
    case 13 :
        int i;
        printf(" Enter a integer \n");
        scanf("%d",&i);
        PrimeFactorization(i);
        Primalitytest(i,5);
        Previousprime(i);
        Nextprime(i);
        break;
   case 14 : 
        int num1,num2;
        printf("Enter first number in decimal system \n");
        scanf("%d",&num1);
        printf("Enter second number in decimal system \n");
        scanf("%d",&num2);
        bitwise_and(num1,num2);
        bitwise_or(num1,num2);
        bitwise_xor(num1,num2);
        bitwise_lshift(num1,num2);
        bitwise_rshift(num1,num2);
        break;
    case 99:
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        app.run(&app, HOST, PORT, DEBUG);
        break;
    default:
        printf("You have entered an Invalid Input.\n");
        break;
    }
    return 0;
}

// Function definitions
double add(double x, double y)
{
    return x + y;
}

double subtract(double x, double y)
{
    return x - y;
}

double multiply(double x, double y)
{
    return x * y;
}

double divide(double x, double y)
{
    if (y != 0)
    {
        return x / y;
    }
    else
    {
        printf("Error: Division by zero\n");
        return NAN;
    }
}

double exponentiate(double x, double y)
{
    return pow(x, y);
}

double square_root(double x)
{
    return sqrt(x);
}

double cube_root(double x)
{
    return cbrt(x);
}

double nth_root(double x, double n)
{
    return pow(x, 1.0 / n);
}

double reciprocal(double x)
{
    if (x != 0)
    {
        return 1.0 / x;
    }
    else
    {
        printf("Error: Reciprocal of zero\n");
        return NAN;
    }
}

double factorialv2(int n)
{
    if (n < 0)
    {
        printf("Error: Factorial of a negative number\n");
        return NAN;
    }
    else if (n == 0)
    {
        return 1;
    }
    else
    {
        double result = 1;
        for (int i = 1; i <= n; ++i)
        {
            result *= i;
        }
        return result;
    }
}

double absolute_value(double x)
{
    return fabs(x);
}

double percentage(double x)
{
    return x / 100.0;
}

double sine(double x)
{
    return sin(x);
}

double cosine(double x)
{
    return cos(x);
}

double tangent(double x)
{
    return tan(x);
}

double inverse_sine(double x)
{
    return asin(x);
}

double inverse_cosine(double x)
{
    return acos(x);
}

double inverse_tangent(double x)
{
    return atan(x);
}

double hyperbolic_sine(double x)
{
    return sinh(x);
}

double hyperbolic_cosine(double x)
{
    return cosh(x);
}

double hyperbolic_tangent(double x)
{
    return tanh(x);
}

double natural_logarithm(double x)
{
    return log(x);
}

double common_logarithm(double x)
{
    return log10(x);
}

double base_10_logarithm(double x)
{
    return log10(x);
}

double exponential_function(double x)
{
    return exp(x);
}

double power_of_10(double x)
{
    return pow(10, x);
}

double power_of_2(double x)
{
    return pow(2, x);
}

struct resistorcolor getResistorcolorcode(int R)
{
    struct resistorcolor result;

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
    result.first = digit1;
    result.second = digit2;
    result.multiplier = multiplier;
    result.tolerance = 0;
    return result;
}