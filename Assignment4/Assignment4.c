//Alan Birmaher
//COP 3211- Assignment 4
//Purpose: To perform GPA calculations and print them for the user.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    //Functions
    double mean(int totnum, double data[]);
    double maximum(int totnum, double data[]);
    double minimum(int totnum, double data[]);
    double var(int totnum, double data[]);
    double stdDeviation(int totnum, double data[]);
    int aboveVal(int totnum, double data[]);
    int underVal(int totnum, double data[]);
    void upSort(int totnum, double data[]);
    double median(int totnum, double data[]);

    //Variables
    double gpa = 0;
    double data[]={3.33, 3, 3.1, 3.93, 2.3, 2.31, 3.99, 2.8, 2.9, 3.7, 2.1, 2.75, 2.95};
    int i= 0;
    int totnum= 0;
    int num = 0;

    //Calculaate and print number of students
    totnum=sizeof(data)/sizeof(double);
    printf("The total number of students is %d\n", totnum);

    //Calculate and print the mean of the GPA's
    gpa= mean(totnum, data);
    printf("The average GPA for all students is %.2lf\n", gpa);

    //Calculate and print maximum gpa
    gpa= maximum(totnum, data);
    printf("The highest GPA for all students is %.2lf\n", gpa);

    //Calculation and print minimum gpa
    gpa= minimum(totnum, data);
    printf("The lowest GPA for all students is %.2lf\n", gpa);

    //Calculate and print variance
    gpa= var(totnum, data);
    printf("The variance of the GPA's for all students is %.2lf\n", gpa);

    //Calculate and print standard deviation
    gpa= stdDeviation(totnum, data);
    printf("The standard deviation of GPA for all students is %.2lf\n", gpa);

    //Calculate and print the number of students with GPA of 2.7 or higher
    num= aboveVal(totnum, data);
    printf("The number of students with GPA of 2.7 or above is %d\n", num);

    //Calculate and print the number of students with GPA of less than 2.7
    num= underVal(totnum, data);
    printf("The number of students with GPA under 2.7 is %d\n", num);

    //Calculate and print the GPA's in ascending order
    upSort(totnum, data);
    printf("The student record sorted in ascending GPA: \n");
    for(i=0; i< totnum; i++){
        printf("%.2lf ", data[i]);
    }
    printf("\n");

    //Caculate and print median GPA
    gpa= median(totnum, data);
    printf("The median GPA for all students is %.2f\n", gpa);

    //Keep it on screen
    system("PAUSE");

    //Return
    return 0;

}

//Mean value of GPA function
double mean(int totnum, double data[]){

    //Variables
    double total=0.0;
    double mean= 0.0;
    int j= 0;

    //Calculate total of GPA's
    for(j=0;j<totnum; j++){
        total += data[j];
    }

    //Calculate mean
    mean= total/totnum;

    //Return
    return mean;

}

//Max value of GPA Function
double maximum(int totnum, double data[]){

    //Variables
    double maximum = 0.0;
    int j=0;

    //Calculate value for max
    for(j=0; j<totnum; j++){

        if(j==0)
            maximum= data[j];

        else{

            if(data[j]> maximum)
                maximum = data[j];

        }

    }

    //Return
    return maximum;

}

//Min value of GPA function
double minimum(int totnum, double data[]){

    //Variables
    double minimum = 0.0;
    int j=0;

    //Calculate value for max
    for(j=0; j<totnum; j++){

        if(j==0)
            minimum= data[j];

        else{

            if(data[j]< minimum)
                minimum = data[j];

        }

    }

    //Return
    return minimum;

}

//Function calculating variance
double var(int totnum, double data[]){

    //Variables
    double meanVal= 0.0;
    double sum= 0.0;
    double variance= 0.0;
    int i= 0;

    //Calculations
    meanVal= mean(totnum, data);
    for(i=0; i<totnum; i++){
        sum+= (data[i] - meanVal)*(data[i]-meanVal);
    }
    variance= sum/(totnum-1);

    //Return
    return variance;

}

//Standard Deviation value of GPA function
double stdDeviation(int totnum, double data[]){

    //Variables
    double stdDeviation = 0.0;
    double variance = 0.0;

    //Calculations
    variance= var(totnum, data);
    stdDeviation= sqrt(variance);

    //Return
    return stdDeviation;

}

//Student with a 3.0 or over GPA function
int aboveVal(int totnum, double data[]){

    //Variables
    int counter=0;
    int j=0;

    //Calculate how many people had above a 3.0
    for(j=0; j<totnum; j++){

            if(data[j]>=2.7)
                counter++;

    }

    //Return
    return counter;

}

int underVal(int totnum, double data[]){

    //Variables
    int counter=0;
    int j=0;

    //Calculate how many people had above a 3.0
    for(j=0; j<totnum; j++){

            if(data[j]<2.7)
                counter++;

    }

    //Return
    return counter;

}

//Sort the GPA's Function
void upSort(int totnum, double data[]){

    //Variables
    int i = 0;
    int j = 0;
    double temp = 0.0;

    //Calculation
    for(i=0; i<= totnum-1; i++){

        for(j=0; j<= totnum-2; j++){

            if(data[j] > data[j+1]){

                temp= data[j];
                data[j]= data[j+1];
                data[j+1]= temp;

            }

        }

    }

}

//Median value of GPA functions
double median(int totnum, double data[]){

    //Variables
    double median=0.0;

    //Calculations
    if(totnum%2)
        median=data[totnum/2];
    else
        median= (data[totnum/2-1]+data[totnum/2])/2.0;

    //Return
    return median;

}
