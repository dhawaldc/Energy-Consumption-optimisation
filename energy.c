#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_TIME_STEPS 6
#define ENERGY_PER_TIME_STEP 10
#define MAX_TEMP 25
#define MIN_TEMP 18
#define ENERGY_COST 0.15

int main() {
    int i, j;
    float temperature[NUM_TIME_STEPS];
    float energy_cost[NUM_TIME_STEPS];
    float energy_usage[NUM_TIME_STEPS];
    float optimal_temperature[NUM_TIME_STEPS];

    for (i = 0; i < NUM_TIME_STEPS; i++) {
        temperature[i] = (float)(rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP);
    }

    for (i = 0; i < NUM_TIME_STEPS; i++) {
        energy_cost[i] = 0.0;
        energy_usage[i] = 0.0;
    }

    for (i = 0; i < NUM_TIME_STEPS; i++) {
        float min_cost = INFINITY;
        for (j = MIN_TEMP; j <= MAX_TEMP; j++) {
            float cost = 0.0;
            if (i > 0) {
                cost = energy_cost[i - 1] + ENERGY_COST * energy_usage[i - 1];
            }
            energy_usage[i] = ENERGY_PER_TIME_STEP * fabs(j - temperature[i]);
            energy_cost[i] = cost + ENERGY_COST * energy_usage[i];

            if (energy_cost[i] < min_cost) {
                min_cost = energy_cost[i];
                optimal_temperature[i] = j;
            }
        }
    }

    for (i = 0; i < NUM_TIME_STEPS; i++) {
        printf("Time step %d: Optimal temperature = %.2f degrees Celsius, Energy usage = %.2f kilowatt-hours\n",
               i, optimal_temperature[i], energy_usage[i]);
    }

    return 0;
}
