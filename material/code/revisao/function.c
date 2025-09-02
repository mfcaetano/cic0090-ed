#include <stdio.h>

//function signature
float compute_pair_average(float grade1, float grade2);
float compute_array_average(const float* grades, int n);


//function signature
float compute_pair_average(float grade1, float grade2){
    return (grade1 + grade2) / 2.0;
}


float compute_array_average(const float* grades, int n){
    float sum = 0.0;
    for(int i = 0; i < n; i++){
        sum += grades[i];
    }
    return sum / n; 
}


int main(){
    float g1 = 7.5, g2 = 8.0;
    float avg_pair = compute_pair_average(g1, g2);
    printf("Average of %.2f and %.2f is %.2f\n", g1, g2, avg_pair);

    float grades[] = {6.5, 7.0, 8.5, 9.0};
    int n = sizeof(grades) / sizeof(grades[0]);
    float avg_array = compute_array_average(grades, n);
    printf("Average of array is %.2f\n", avg_array);

    return 0;
}
