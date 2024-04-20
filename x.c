#include<stdio.h>
#include<stdlib.h>
#include<math.h>



void resistorColorCode(int resistance) {
    
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
void capacitorCode(double capacitance) {
    // Array of capacitor codes
    char *code[] = {"pF", "nF", "uF", "mF"};
    
    // Calculating capacitor code index
    int idx = 0;
    while (capacitance >= 1000) {
        capacitance /= 1000;
        idx++;
    }
    
    // Displaying capacitor code
    printf("Capacitor Code: %.2f %s\n", capacitance, code[idx]);
}

// Function to calculate inductor code
void inductorCode(double inductance) {
    // Array of inductor codes
    char *code[] = {"nH", "uH", "mH", "H"};
    
    // Calculating inductor code index
    int idx = 0;
    while (inductance >= 1000) {
        inductance /= 1000;
        idx++;
    }
    
    // Displaying inductor code
    printf("Inductor Code: %.2f %s\n", inductance, code[idx]);
}

// Function to calculate Ohm's Law (Voltage, Current, Resistance)
void ohmsLaw() {
    double voltage, current, resistance;
    int choice;
    printf("Choose which values you have:\n");
    printf("1. Voltage and Resistance\n");
    printf("2. Current and Resistance\n");
    printf("3. Voltage and Current\n");
    scanf("%d", &choice);
    
    switch(choice) {
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
void rcCircuitTimeConstant(double resistance, double capacitance) {
    double timeConstant = resistance * capacitance;
    printf("RC Circuit Time Constant (Tau): %.2f seconds\n", timeConstant);
}

// Function to calculate RL circuit time constant
void rlCircuitTimeConstant(double resistance, double inductance) {
    double timeConstant = resistance / inductance;
    printf("RL Circuit Time Constant (Tau): %.2f seconds\n", timeConstant);
}

// Function to calculate resonant frequency of LC circuit
void resonantFrequency(double inductance, double capacitance) {
    double frequency = 1 / (2 * M_PI * sqrt(inductance * capacitance));
    printf("Resonant Frequency: %.2f Hz\n", frequency);
}

// Function to design low-pass filter
void lowPassFilter(double cutoffFrequency) {
    printf("Low-pass filter designed with a cutoff frequency of %.2f Hz\n", cutoffFrequency);
}

// Function to calculate impedance of RLC circuit
void rlcCircuitImpedance(double resistance, double inductance, double capacitance) {
    double impedance = sqrt(pow(resistance, 2) + pow((1 / (2 * M_PI * capacitance)), 2));
    printf("RLC Circuit Impedance: %.2f ohms\n", impedance);
}

double mean(int data[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

// Function to calculate median
double median(int data[], int n) {
    int tempArray[n];
    for (int i = 0; i < n; i++) {
        tempArray[i] = data[i];
    }
    int middle = n / 2;
    if (n % 2 == 0) {
        return (tempArray[middle - 1] + tempArray[middle]) / 2.0;
    } else {
        return tempArray[middle];
    }
}

// Function to compare elements for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to calculate mode
double mode(int data[], int n) {
    qsort(data, n, sizeof(int), compare);

    int modeCount = 0, maxCount = 0, modeValue = data[0], prevValue = data[0];

    for (int i = 1; i < n; i++) {
        if (data[i] == prevValue) {
            modeCount++;
        } else {
            if (modeCount > maxCount) {
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
double standardDeviation(int data[], int n) {
    double meanValue = mean(data, n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(data[i] - meanValue, 2);
    }
    return sqrt(sum / n);
}

// Function to calculate variance
double variance(int data[], int n) {
    double meanValue = mean(data, n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(data[i] - meanValue, 2);
    }
    return sum / n;
}


float final_velocity(float u,float t,float a)
{
    float v=u+a*t;
    return v;
}

float displacement_with_time(float t,float u,float a)
{
float s=u*t+0.5*a*t*t;
return s;

}

float diplacement_with_velocity(float v,float u,float a)
{
 float x=v*v-u*u;
 float s=x/(a*2);
 return s;

}
float finalvelocity_with_displacement(float s,float u,float a)
{
  float v=sqrt(2*a*s+u*u);

  return v;
}

float acceleration(float u,float v,float t)
{
float a=(v-u)/t;
return a;
}

float time(float a,float v,float u)
{
float t=(v-u)/a;
return t;

}




int main() {
   
   
   int type;
    printf("select\n");
    
   printf("electronics function =1 \n");
   printf("physics functions = 2\n");
   printf("statistics = 3\n");
   
   scanf("%d",&type);

   switch(type) {
     

    case 1:
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

    switch (electonics) {
        case 1:
            printf("Enter resistance value in ohms: ");
            scanf("%lf", &value1);
            resistorColorCode((int)value1);
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

    return 0;
    break;
    case 4:
          float u,v,a,t,s;

int physics;

printf("select the option\n");

printf ("1:final velocity with time\n");
printf("2: displacement with time\n");
printf("3: displacement with final velocity\n ");
printf("4 : final velocity with displacement\n");
printf("5 : acceleration\n");
printf("6 : time\n");
printf("enter the choice\n");

scanf("%d",&physics);


switch (physics){
    

   case 1:

   printf("enter the initial velocity");
   scanf("%f",&u);
   printf("enter the time");
   scanf("%f",&t);
    printf("enter the acceleration");
    scanf("%f",&a);

   v= final_velocity(u,t,a);

   printf(" final velocity is :%f",v);

break; 
 case 2:

   printf("enter the initial velocity");
   scanf("%f",&u);
   printf("enter the time");
   scanf("%f",&t);
    printf("enter the acceleration");
    scanf("%f",&a);

   s=displacement_with_time(t,u,a);

   printf(" final displacement is :%f",s);

break;
case 3:


  printf("enter the initial velocity");
   scanf("%f",&u);
   printf("enter the final velocity");
   scanf("%f",&v);
    printf("enter the acceleration");
    scanf("%f",&a);

   s=diplacement_with_velocity(v,u,a);

   printf(" final displacement is : %f",s);

break;

case 4:


 printf("enter the initial velocity");
   scanf("%f",&u);
   printf("enter the displacement");
   scanf("%f",&s);
    printf("enter the acceleration");
    scanf("%f",&a);

  v=finalvelocity_with_displacement(s,u,a);
printf(" final velocity is : %f",v);
break;
case 5:

 printf("enter the initial velocity");
   scanf("%f",&u);
   printf("enter the final velocity");
   scanf("%f",&v);
    printf("enter the time");
    scanf("%f",&t);

a=acceleration(u,v,t);
printf("acceleration is : %f",a);
break;
case 6:
 printf("enter the initial velocity");
   scanf("%f",&u);
   printf("enter the final velocity");
   scanf("%f",&v);
    printf("enter the acceleration");
    scanf("%f",&a);

t=time(a,v,u);
printf("time taken : %f",t);

break;

}
    break;

    case 3:
    int n;
    printf("Enter the number of elements in the dataset: ");
    scanf("%d", &n);

    int *data = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the dataset:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    printf("Mean: %.2f\n", mean(data, n));
    printf("Median: %.2f\n", median(data, n));
    printf("Mode: %.2f\n", mode(data, n));
    printf("Standard Deviation: %.2f\n", standardDeviation(data, n));
    printf("Variance: %.2f\n", variance(data, n));

    free(data);

    break;
   }  
}
