#include <stdio.h>
// #include <conio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

// to run in windows : `gcc main_onefile.c -lws2_32 && ./a.exe`

#ifdef _WIN32

#pragma comment(lib, "ws2_32.lib") // Link with ws2_32.lib
#define InitializeWinsock                      \
    WSADATA wsa;                               \
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) \
    {                                          \
        printf("WSAStartup failed\n");         \
        return 1;                              \
    }
#define ClearWinsock WSACleanup()

#include <winsock2.h>
#include <ws2tcpip.h> // Include ws2tcpip.h for inet_ntop


#else


#define closesocket close
#define InitializeWinsock
#define SOCKET int
#define ClearWinsock
#define min(a, b) (a > b) ? b : a

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>    // For close()
#include <arpa/inet.h> // For inet_ntop()

#endif


#define HOST "0.0.0.0" // "localhost"
#define PORT 5000
#define DEBUG 0

#define PI 3.1415926536
#define SIZE 10
#define BUFFER_SIZE 4096
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

typedef struct _server server;
typedef struct _str str;
typedef struct _list list;
typedef void (*Callback)(server *, str *response, list *headers, str *content_buffer);

struct _server_node
{
    char *method;
    char *path;
    Callback callback;
    struct _server_node *next;
};

struct _server
{
    struct _server_node *head;
    struct _server_node *tail;
    int length;
    int debug;
    int _stop;
    // void (*print)(struct _str*); // print method
    void (*route)(struct _server *, char *, char *, Callback callback);
    int (*run)(struct _server *, char *, int, int);
    void (*stop)(struct _server *);
    // char* (*get)(struct _list*, char*);
};

struct _server http_server();

int find(char *s, char *value);
int findchar(char *s, char value);
size_t get_file_size(FILE *fptr);
void send_file(str *response, char *filename);
void send_file_with_header(str *response, char *filename, char *header);

// Function to convert a request string to an integer representation
int _server_request_to_int(const char *str);

void _server_route(struct _server *self, char *method, char *path, Callback callback);
int _server_run(struct _server *self, char *host, int port, int debug);
void _server_stop(struct _server *self);
void _server_debug(struct _server *self, const char *, ...);
// String()
struct _str_chunk
{
    char *data;
    int length;
    struct _str_chunk *next;
};

struct _str
{
    struct _str_chunk *head;
    struct _str_chunk *tail;
    int length;
    void (*print)(struct _str *); // print method
    void (*append_format)(struct _str *, const char *, ...);
    void (*append)(struct _str *, char *); // Append object to the end of the string.
    void (*append_byte)(struct _str *, char *, int);
    void (*free)(struct _str *);        // Free the string.
    void (*clear)(struct _str *);       // Clear the string
    void (*raw)(struct _str *, char *); // copy the string to the buffer
    void (*get_chunk)(struct _str *, int, char *, int);
};

void _str_data__repr__(char *);
void _str_print(struct _str *);
void _str_append_format(struct _str *, const char *, ...);
void _str_append(struct _str *, char *);
void _str_append_byte(struct _str *, char *, int);
void _str_raw(struct _str *, char *);
void _str_clear(struct _str *);
void _str_get_chunk(struct _str *, int, char *, int);
struct _str String();

// List()
typedef struct _list_data
{
    char *key;
    char *value;
} Header;

struct _list_node
{
    struct _list_data *data;
    struct _list_node *next;
};

struct _list
{
    struct _list_node *head;
    struct _list_node *tail;
    int length;
    void (*print)(struct _list *);                       // print method
    void (*append)(struct _list *, struct _list_data *); // Append object to the end of the list.
    void (*free)(struct _list *);                        // Free the list.
    char *(*get)(struct _list *, char *);
};

// custom functions
char *_list_get_header(struct _list *, char *);

// utility functions
void _list_data__repr__(struct _list_data *);
struct _list_data *_list_data_copy(struct _list_data *);
void _list_data_free(struct _list_data *);

void _list_print(struct _list *);
void _list_append(struct _list *, struct _list_data *);
void _list_remove(struct _list *, struct _list_data *);
void _list_index(struct _list *, struct _list_data *);
void _list_free(struct _list *);
struct _list List();


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
void home(server *self, str *response, list *headers, str *content_buffer){
    send_file(response, "templates/index.html");
}
void ResistorcolorcodeGET(server *self, str *response, list *headers, str *content_buffer){
    send_file(response, "templates/Resistorcolorcode.html");
}
void ResistorcolorcodePOST(server *self, str *response, list *headers, str *content_buffer){
    char body[content_buffer->length];
    content_buffer->raw(content_buffer, body);
    int value;

    // Search for the "value" key and extract the integer following it
    if (sscanf(body, "{\"value\":%d}", &value) != 1) {
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
void send_static(server *self, str *response, list *headers, str *content_buffer){
    int pos = findchar(headers->head->data->value, ' '); 
    char url[pos];
    for (int i = 1; i < pos; i++) url[i-1] = headers->head->data->value[i];
    url[pos-1] = '\0';
    send_file(response, url);   
}
void send_logo(server *self, str *response, list *headers, str *content_buffer){
    str header_buffer = String();
    header_buffer.append(&header_buffer, "HTTP/1.1 200 OK\r\n");
    header_buffer.append(&header_buffer, "Accept-Ranges: bytes\r\n");
    FILE *fptr;
    fptr = fopen("static/favicon.ico", "rb");
    if (fptr == NULL) {
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
void stop_server(server *self, str *response, list *headers, str *content_buffer){
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
               " Enter 9 for statistics\n"
               " Enter 10 for Physics\n"
               " Enter 11 for Electronic\n"
               " Enter 12 for MATH Calculator\n"
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


struct resistorcolor getResistorcolorcode(int R){   
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



















// TODO add streaming support to server
// you can use send_data(response) func then clear response to add streaming
// DONE add /path/* support to server
// TODO add request.method and * inplace of POST/GET in app(&app, method)
// TODO add good pipeline
// TODO fix bugs like file not closing after request is done...

int find(char *s, char *value)
{
    int i = 0;
    int pos = -1;
    while (s[i] != '\0' && pos == -1)
    {
        if (s[i] == value[0])
        {
            int j = 0;
            while (value[j] != '\0')
            {
                if (value[j] != s[i + j])
                    break;
                j++;
            }
            if (value[j] == '\0')
                pos = i;
        }
        i++;
    }
    return pos;
}
int findchar(char *s, char value)
{
    int i = 0;
    int pos = -1;

    while (s[i] != '\0' && pos == -1)
    {

        if (s[i] == value)
            pos = i;

        i++;
    }

    return pos;
}

// Function to convert a request string to an integer representation
int _server_request_to_int(const char *str)
{
    // Example: Convert "GET" to 1, "POST" to 2, etc.

    if (strcmp(str, "GET") == 0)
        return 1;

    else if (strcmp(str, "POST") == 0)
        return 2;

    return 0; // Default case
}

// void route_post(str *response, list *headers, str *data){
//     int pos = findchar(headers->head->data->value, ' ');
//     char url[pos+1];
//     for (int i = 0; i < pos; i++) url[i] = headers->head->data->value[i];
//     url[pos] = '\0';
//     printf("URL: %s\n", url);
//     char data_raw[data->length];
//     data->raw(data, data_raw);

//     if (strcmp(url, "/") == 0) {
//         response->append(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
//         response->append(response, "Hello world! POST<br>");
//         response->append(response, data_raw);
//         response->append(response, "<br>");
//         response->append(response, headers->head->data->value);
//     }
//     else {
//         response->append(response, "HTTP/1.1 404 NOT FOUND\r\nContent-Type: text/html\r\n\r\n");
//         response->append(response, "Not Fount");
//     }
// }

void _server_debug(struct _server *self, const char *format, ...)
{
    if (self->debug)
    {
        va_list args;

        va_start(args, format);
        printf(CYN "DEBUG: " MAG);

        vprintf(format, args);

        printf("\n" RESET);

        va_end(args);
    }
}

void _server_route(struct _server *self, char *method, char *path, Callback callback)
{
    struct _server_node *node = (struct _server_node *)malloc(sizeof(struct _server_node));
    // char* copied_method = (char*)malloc(sizeof(char)*(strlen(method) + 1)); // +1 for the null terminator
    // strcpy(copied_method, method);
    // char* copied_path = (char*)malloc(sizeof(char)*(strlen(path) + 1)); // +1 for the null terminator
    // strcpy(copied_path, path);
    node->callback = callback;

    node->method = method;
    node->path = path;

    if (self->head == NULL)
    {

        self->head = node;
        self->tail = node;
    }
    else
    {

        self->tail->next = node;
        self->tail = node;
    }
    // printf("%s\n", node->path);
    self->length++;
}
int _server_run(struct _server *self, char *host, int port, int debug)
{
    // Initialize Winsock
    InitializeWinsock;

    SOCKET server_sock, client_sock;
    struct sockaddr_in server, client;

    socklen_t client_len;
    char client_ip[INET_ADDRSTRLEN]; // Buffer to store client IP address
    char buffer[BUFFER_SIZE + 1];    // Buffer to store received data

    self->debug = debug;

    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    { // INVALID_SOCKET == ~0

        perror("Socket creation failed");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;

    if (strcmp(host, "0.0.0.0") == 0)
        server.sin_addr.s_addr = INADDR_ANY;
    else if (strcmp(host, "localhost") == 0)
        server.sin_addr.s_addr = inet_addr("127.0.0.1");
    else
        server.sin_addr.s_addr = inet_addr(host);

    server.sin_port = htons(port);

    // Bind
    if (bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        // SOCKET_ERROR == -1

        perror("Bind failed");
        return 1;
    }

    printf(RED "*" CYN " Basic HTTP Server in C\n");

    if (debug)
        printf(RED "*" CYN " Debug mode: " GRN "on\n");
    else
        printf(RED "*" CYN " Debug mode: " GRN "off\n");

    printf(RED "WARNING:" RESET CYN " This is a development server. Do not use it in a production deployment.\n");

    if (strcmp(host, "0.0.0.0") == 0)
    {

        printf(RED "*" CYN " Running on all addresses " GRN "(0.0.0.0)\n");

        printf(RED "*" CYN " Running on " YEL "http://127.0.0.1:%d\n", port);
        // printf(RED"*"CYN" Running on "YEL"http://10.19.12.191:%d\n", port);
    }

    else
    {
        printf(RED "*" CYN " Running on " YEL "http://127.0.0.1:%d\n", port);
    }

    _server_debug(self, "Server is set to debug mode");

    // Listen
    listen(server_sock, 5);

    // Accept and handle connections
    while (1)
    {

        client_len = sizeof(client);
        client_sock = accept(server_sock, (struct sockaddr *)&client, &client_len);

        if (client_sock < 0)
        {
            // INVALID_SOCKET == ~0

            printf("Accept failed\n");
            return 1;
        }

        // Print client address
        inet_ntop(AF_INET, &client.sin_addr, client_ip, INET_ADDRSTRLEN);

        _server_debug(self, "Client connected from: %s:%d", client_ip, ntohs(client.sin_port));

        str header_buffer = String();
        str content_buffer = String();

        // Receive request header from client
        while (1)
        {
            int bytes_received = recv(client_sock, buffer, sizeof(buffer) - 1, 0);

            if (bytes_received <= 0)
                break;

            buffer[bytes_received] = '\0'; // Null-terminate the received data

            // int nlpos = findchar(buffer, '\n');
            // while (nlpos != -1){
            // buffer[nlpos] = '\0';
            // printf("FIND: %s\n", buffer);
            // buffer[nlpos] = '\n';
            // break;
            // }
            // printf("`%s`\n", buffer);

            header_buffer.append(&header_buffer, buffer);
            // printf("LEN: %d\n", header_line_buffer.length);

            // char raw_header[16+1];
            // header_line_buffer.get_chunk(&header_line_buffer, 0, raw_header,16);
            // raw_header[16] = '\0';
            // printf("DATA 1: `%s`\n", raw_header);
            // Check if we've received the end of the header (double CRLF)

            char raw_header[header_buffer.length];

            header_buffer.raw(&header_buffer, raw_header);

            int pos = find(raw_header, "\r\n\r\n");

            if (pos != -1)
            {
                // printf("We Found the end of the header %d\n", pos);
                // printf("Total length: %d\n", header_buffer.length);

                char content_tmp[BUFFER_SIZE + 1];

                int idx = 0;
                for (int i = pos + 4; i < header_buffer.length; i++)
                {

                    content_tmp[idx] = raw_header[i];
                    idx++;
                }

                content_tmp[idx] = '\0';

                content_buffer.append(&content_buffer, content_tmp);

                raw_header[pos + 4] = '\0';

                header_buffer.clear(&header_buffer);
                header_buffer.append(&header_buffer, raw_header);

                // printf("LEN: %d but total len: %d\n", strlen(raw_header), header_line_buffer.length);
                // header_line_buffer.print(&header_line_buffer);

                break;
            }
        }

        char raw_header[header_buffer.length];
        header_buffer.raw(&header_buffer, raw_header);

        list headers = List();

        // printf("\n------------------------------------\n%c", raw_header[0]);

        char tmp[header_buffer.length];
        int idx = 0;

        for (int i = 1; i < header_buffer.length - 2; i++)
        {

            tmp[idx] = raw_header[i - 1];

            if (raw_header[i - 1] == '\r' && raw_header[i] == '\n')
            {

                tmp[idx + 1] = '\0';

                int pos = findchar(tmp, ' ');
                tmp[pos] = '\0';

                char value[idx - pos + 1];
                for (int i = 0; i < idx - pos + 1; i++)
                    value[i] = tmp[pos + i + 1];

                value[idx - pos - 1] = '\0'; // changing \r to \0

                char key[strlen(tmp) + 1];
                strcpy(key, tmp);

                Header header;
                header.key = key;
                header.value = value;

                // printf("{%s : %s}\n", key, value);
                // printf("KEY: `%s`LEN: %d\n\n", key, strlen(key));
                // printf("VALUE: `%s`LEN: %d\n\n", value, strlen(value));

                headers.append(&headers, &header);

                tmp[pos] = ' ';

                idx = -1;
                i++;
            }
            idx++;
        }

        // printf("\n\nRequest header:\n");
        // headers.print(&headers);
        // header_buffer.print(&header_buffer);
        // printf("Request body:\n");
        // header_buffer.print(&content_buffer);

        str response = String();

        // printf(BLU "%s" RESET " - - " GRN "%s" RESET " \"%s\"\n", client_ip, headers.head->data->key, headers.head->data->value);

        int flag_not_found = 1;
        struct _server_node *node = self->head;

        int pos = findchar(headers.head->data->value, ' ');
        // TODO split by ? and many more characters
        char url[pos + 1];

        for (int i = 0; i < pos; i++)
            url[i] = headers.head->data->value[i];

        url[pos] = '\0';

        while (node != NULL)
        {
            if (strcmp(headers.head->data->key, node->method) == 0)
            {
                // checking for /*

                int pos_path_not_star = find(node->path, "/*");
                char path_not_star[strlen(node->path) + 1];

                strcpy(path_not_star, node->path);
                path_not_star[pos_path_not_star] = '\0';

                if (strcmp(url, node->path) == 0)
                {

                    if (strcmp(headers.head->data->key, "POST") == 0)
                    {

                        int content_length = atoi(headers.get(&headers, "Content-Length:"));
                        while (content_length > content_buffer.length)
                        {

                            int bytes_received = recv(client_sock, buffer, min(sizeof(buffer) - 1, (content_length - content_buffer.length)), 0);
                            if (bytes_received <= 0)
                                break;

                            buffer[bytes_received] = '\0';
                            content_buffer.append(&content_buffer, buffer);
                        }
                    }

                    node->callback(self, &response, &headers, &content_buffer);
                    flag_not_found = 0;

                    break;
                }
                else if ((pos_path_not_star != -1) && (strcmp(url, path_not_star) != 0) && (find(url, path_not_star) != -1))
                {

                    if (strcmp(headers.head->data->key, "POST") == 0)
                    {

                        int content_length = atoi(headers.get(&headers, "Content-Length:"));

                        while (content_length > content_buffer.length)
                        {

                            int bytes_received = recv(client_sock, buffer, min(sizeof(buffer) - 1, (content_length - content_buffer.length)), 0);
                            if (bytes_received <= 0)
                                break;

                            buffer[bytes_received] = '\0';
                            content_buffer.append(&content_buffer, buffer);
                        }
                    }
                    node->callback(self, &response, &headers, &content_buffer);
                    flag_not_found = 0;

                    break;
                }
            }
            node = node->next;
        }
        if (flag_not_found == 1)
        {
            response.append(&response, "HTTP/1.1 404 NOT FOUND\r\n\r\n");

            response.append(&response, "ERROR : 404 NOT FOUND");
        }
        // char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\nHello world!";
        // TODO this is make error as size is larger
        // char response_raw[response.length];

        char *response_raw = (char *)malloc(response.length + 1);
        response.raw(&response, response_raw);

        // Send response
        send(client_sock, response_raw, response.length, 0);

        pos = findchar(response_raw + 9, ' '); // 9 for HTTP/1.1 
        response_raw[pos + 9] = '\0';
        if (flag_not_found == 1)
            printf(BLU "%s" RESET " - " RED "%s" RESET " - " GRN "%s" RESET " \"%s\"\n", client_ip, response_raw + 9, headers.head->data->key, headers.head->data->value);
        else
            printf(BLU "%s" RESET " - " GRN "%s" RESET " - " GRN "%s" RESET " \"%s\"\n", client_ip, response_raw + 9, headers.head->data->key, headers.head->data->value);

        // if(flag_not_found == 1) printf(RED "ERROR:" RESET " NOT FOUND\n");
        response_raw[pos + 9] = ' ';

        free(response_raw);

        // _server_debug(self, RESET"%s "MAG"Socket connection closed", client_ip);
        _server_debug(self, "Socket connection closed");

        // Close client socket
        closesocket(client_sock);
        headers.free(&headers);

        // line_buffer.free(&line_buffer);
        header_buffer.free(&header_buffer);
        content_buffer.free(&content_buffer);
        if (self->_stop==1) return 0;
    }

    // Close server socket
    closesocket(server_sock);
    ClearWinsock;
    return 0;
}

void _server_stop(struct _server *self){
    self->_stop = 1;
}

struct _server http_server()
{
    struct _server s;
    s.head = NULL;
    s.tail = NULL;

    s.length = 0;
    s.debug = 0;
    s._stop = 0;
    s.route = _server_route;
    s.stop = _server_stop;
    s.run = _server_run;
    return s;
}

size_t get_file_size(FILE *fptr)
{
    fseek(fptr, 0L, SEEK_END);

    int file_size = ftell(fptr);
    rewind(fptr); // fseek(fptr, 0L, SEEK_SET);

    return file_size;
}
void send_file(str *response, char *filename)
{
    FILE *fptr;
    fptr = fopen(filename, "rb");

    if (fptr == NULL)
    {
        response->append(response, "HTTP/1.1 404 NOT FOUND\r\n\r\n");

        response->append(response, "ERROR : 404 NOT FOUND");
        printf("ERROR : 404 NOT FOUND\n");

        fclose(fptr);
        return;
    }
    size_t file_size = get_file_size(fptr);
    // Allocate memory to store file data
    char *file_data = (char *)malloc(file_size + 1);

    if (file_data == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(fptr);

        free(file_data);
        exit(EXIT_FAILURE);
    }

    // Read the entire file into memory
    size_t bytes_read = fread(file_data, 1, file_size, fptr);
    if (bytes_read != file_size)
    {
        printf("Error reading file.\nSize: %d\tRead: %d\n", file_size, bytes_read);

        fclose(fptr);
        free(file_data);

        exit(EXIT_FAILURE);
    }
    file_data[file_size] = '\0'; // Null-terminate the string // file_size + 1
    // response->append(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");

    response->append(response, "HTTP/1.1 200 OK\r\n\r\n");
    response->append_byte(response, file_data, file_size);

    fclose(fptr);
    free(file_data);
}

// TODO: add similar to jinja2 support
// void render_template(str *response, char *filename, ...)

void send_file_with_header(str *response, char *filename, char *header)
{
    FILE *fptr;
    fptr = fopen(filename, "rb");

    if (fptr == NULL)
    {
        response->append(response, "HTTP/1.1 404 NOT FOUND\r\n\r\n");
        response->append(response, "ERROR : 404 NOT FOUND");

        fclose(fptr);
        return;
    }
    size_t file_size = get_file_size(fptr);
    // Allocate memory to store file data
    char *file_data = (char *)malloc(file_size + 1);
    if (file_data == NULL)
    {

        printf("Memory allocation failed.\n");
        fclose(fptr);

        free(file_data);
        exit(EXIT_FAILURE);
    }
    // Read the entire file into memory
    size_t bytes_read = fread(file_data, 1, file_size, fptr);
    if (bytes_read != file_size)
    {

        printf("Error reading file.\nSize: %d\tRead: %d\n", file_size, bytes_read);
        fclose(fptr);

        free(file_data);
        exit(EXIT_FAILURE);
    }

    file_data[file_size] = '\0'; // Null-terminate the string // file_size + 1
    // response->append(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");

    response->append(response, header);
    response->append_byte(response, file_data, file_size);

    fclose(fptr);
    free(file_data);
}

// String()
void _str_data__repr__(char *data)
{
    printf("%s", data);
}

// Function of List
void _str_print(struct _str *self)
{
    // print method
    struct _str_chunk *node = self->head;
    if (node != NULL)
    {
        while (node->next != NULL)
        {

            _str_data__repr__(node->data);
            node = node->next;
        }

        _str_data__repr__(node->data);
    }

    printf("\n");
}
// TODO:
void _str_append_format(struct _str *self, const char *format, ...)
{
    va_list args;
    va_start(args, format);

    // Determine the length of the formatted string
    int len = vsnprintf(NULL, 0, format, args);
    // Reset args to use it again

    va_end(args);
    va_start(args, format);

    // Allocate memory for the formatted string (+1 for null terminator)
    char *copied_data = (char *)malloc(sizeof(char) * (len + 1));

    // Format the string into the buffer

    vsprintf(copied_data, format, args);
    va_end(args);
    struct _str_chunk *node = (struct _str_chunk *)malloc(sizeof(struct _str_chunk));
    node->data = copied_data;
    node->length = -1;
    node->next = NULL;

    if (self->head == NULL)
    {
        self->head = node;
        self->tail = node;
    }

    else
    {
        self->tail->next = node;
        self->tail = node;
    }

    // printf("Size of `%s` is %d\n", data, strlen(data));
    self->length += strlen(copied_data);
}
void _str_append(struct _str *self, char *data)
{
    // Append object to the end of the list.
    struct _str_chunk *node = (struct _str_chunk *)malloc(sizeof(struct _str_chunk));
    char *copied_data = (char *)malloc(sizeof(char) * (strlen(data) + 1)); // +1 for the null terminator

    if (copied_data == NULL)
    {

        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    strcpy(copied_data, data);
    node->data = copied_data;
    node->length = -1;
    node->next = NULL;

    if (self->head == NULL)
    {
        self->head = node;
        self->tail = node;
    }

    else
    {
        self->tail->next = node;
        self->tail = node;
    }

    // printf("Size of `%s` is %d\n", data, strlen(data));
    self->length += strlen(data);
}
void _str_append_byte(struct _str *self, char *data, int len)
{
    // Append object to the end of the list.
    struct _str_chunk *node = (struct _str_chunk *)malloc(sizeof(struct _str_chunk));
    char *copied_data = (char *)malloc(sizeof(char) * (len));

    if (copied_data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < len; i++)
        copied_data[i] = data[i];

    node->data = copied_data;
    node->length = len;
    node->next = NULL;

    if (self->head == NULL)
    {
        self->head = node;
        self->tail = node;
    }

    else
    {
        self->tail->next = node;
        self->tail = node;
    }

    self->length += len;
}
void _str_append_char(struct _str *self, char ch)
{
}
void _str_raw(struct _str *self, char *output)
{
    struct _str_chunk *node = self->head;
    output[0] = '\0';
    int idx = 0;

    if (node != NULL)
    {
        while (node->next != NULL)
        {
            if (node->length == -1)
            {

                int i = 0;
                while (node->data[i] != '\0')
                {

                    output[idx] = node->data[i];
                    i++;
                    idx++;
                }
            }

            else
            {

                for (int i = 0; i < node->length; i++)
                {
                    output[idx] = node->data[i];
                    idx++;
                }
            }
            // strcat(output, node->data);
            node = node->next;
        }
        if (node->length == -1)
        {
            int i = 0;
            while (node->data[i] != '\0')
            {

                output[idx] = node->data[i];
                i++;
                idx++;
            }
            output[idx] = '\0';
        }
        else
        {

            for (int i = 0; i < node->length; i++)
            {
                output[idx] = node->data[i];
                idx++;
            }
        }
        // strcat(output, node->data);
    }
    // strcat(output, '\0');
}
void _str_clear(struct _str *self)
{
    struct _str_chunk *node = self->head;
    self->length = 0;
    if (node == NULL)
        return;

    while (node->next != NULL)
    {
        struct _str_chunk *next = node->next;

        free(node->data);
        free(node);
        node = next;
    }

    free(node->data);
    free(node);

    self->head = NULL;
    self->tail = NULL;
}
void _str_get_chunk(struct _str *self, int index, char *output, int length)
{
    struct _str_chunk *node = self->head;

    output[0] = '\0';

    if (node == NULL)
    {
        printf("ERROR: _str_get_chunk node is NULL maybe size is smaller than index");
        return;
    }
    for (int i = 0; i < index; i++)
    {
        node = node->next;
        if (node == NULL)
        {

            printf("ERROR: _str_get_chunk node is NULL maybe size is smaller than index");
            return;
        }
    }

    for (int i = 0; i < length; i++)
        output[i] = node->data[i];
}

// Function to initialize a test structure with default values
struct _str String()
{
    struct _str s;
    s.head = NULL;
    s.tail = NULL;
    s.length = 0;

    s.print = _str_print;
    s.append_format = _str_append_format;
    s.append = _str_append;

    s.append_byte = _str_append_byte; // TODO: this helps to add music and images support as \0 reset a string
    s.free = _str_clear;
    s.clear = _str_clear;

    s.raw = _str_raw;
    s.get_chunk = _str_get_chunk;
    return s;
}

// List()

void _list_data__repr__(struct _list_data *data)
{
    printf("{ %s : %s }", data->key, data->value);
}

struct _list_data *_list_data_copy(struct _list_data *data)
{
    struct _list_data *copied_data = (struct _list_data *)malloc(sizeof(struct _list_data));

    char *copied_data_key = (char *)malloc(sizeof(char) * (strlen(data->key) + 1));     // +1 for the null terminator
    char *copied_data_value = (char *)malloc(sizeof(char) * (strlen(data->value) + 1)); // +1 for the null terminator

    strcpy(copied_data_key, data->key);
    strcpy(copied_data_value, data->value);

    copied_data->key = copied_data_key;
    copied_data->value = copied_data_value;

    return copied_data;
}
void _list_data_free(struct _list_data *data)
{
    free(data->value);
    free(data->key);
};

char *_list_get_header(struct _list *self, char *key)
{
    struct _list_node *node = self->head;
    if (node != NULL)
    {
        while (strcmp(node->data->key, key) && node->next != NULL)
            node = node->next;
    }

    else
        printf("ERROR: Invalid get key\n");

    return node->data->value;
}

// Function of List
void _list_print(struct _list *self)
{
    // print method
    struct _list_node *node = self->head;
    printf("[\n\t");

    if (node != NULL)
    {
        while (node->next != NULL)
        {
            _list_data__repr__(node->data);
            printf(", \n\t");
            // printf("%d, ", node->data);
            node = node->next;
        }

        _list_data__repr__(node->data);
        printf("\n]\n");

        // printf("%d]\n", node->data);
    }
    else
        printf("]\n");
}
void _list_append(struct _list *self, struct _list_data *data)
{
    // Append object to the end of the list.
    struct _list_node *node = (struct _list_node *)malloc(sizeof(struct _list_node));
    node->data = _list_data_copy(data);
    node->next = NULL;

    if (self->head == NULL)
    {
        self->head = node;
        self->tail = node; // TODO;
    }
    else
    {
        self->tail->next = node;
        self->tail = node;
    }

    self->length++;

    // printf("DATA: %d ", self->head->data);
    // printf("LEN: %d\n", self->length);
}
void _list_remove(struct _list *self, struct _list_data *data)
{
    // Remove first occurrence of value.
    // Raises ValueError if the value is not present.
}
void _list_index(struct _list *self, struct _list_data *data)
{
    // Return first index of value. -1 if the value is not present.
}
void _list_free(struct _list *self)
{
    struct _list_node *node = self->head;
    self->length = 0;
    if (node == NULL)
        return;

    while (node->next != NULL)
    {
        struct _list_node *next = node->next;
        _list_data_free(node->data);

        free(node->data);
        free(node);
        node = next;
    }

    free(node);

    self->head = NULL;
    self->tail = NULL;
}

// Function to initialize a test structure with default values
struct _list List()
{
    struct _list l;
    l.head = NULL;
    l.tail = NULL;

    l.length = 0;

    l.print = _list_print;
    l.append = _list_append;
    l.free = _list_free;
    l.get = _list_get_header;

    return l;
}

// TODO: Implement json parsing and more
// struct _jsonify{
//     int length;
//     struct _jsonify next;

// };