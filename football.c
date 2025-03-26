#include "football.h"


// Define possible NFL scoring values
const int SCORES[] = {2, 3, 6, 7};
const int NUM_SCORES = 4;

// Function to count the number of ways to achieve a given score
int count_combinations(int points) {
    int count = 0;
    
    // Iterate through all possible combinations of scores
    for (int num_safeties = 0; num_safeties * 2 <= points; num_safeties++) {
        for (int num_field_goals = 0; num_safeties * 2 + num_field_goals * 3 <= points; num_field_goals++) {
            for (int num_touchdowns = 0; num_safeties * 2 + num_field_goals * 3 + num_touchdowns * 6 <= points; num_touchdowns++) {
                for (int num_td_extra = 0; num_safeties * 2 + num_field_goals * 3 + num_touchdowns * 6 + num_td_extra * 1 <= points; num_td_extra++) {
                    if (num_safeties * 2 + num_field_goals * 3 + num_touchdowns * 6 + num_td_extra * 1 == points) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

// Function to print all possible ways to achieve a given score
void print_combinations(int points) {
    printf("Possible scoring combinations for %d points:\n", points);
    
    // Iterate through all possible combinations
    for (int num_safeties = 0; num_safeties * 2 <= points; num_safeties++) {
        for (int num_field_goals = 0; num_safeties * 2 + num_field_goals * 3 <= points; num_field_goals++) {
            for (int num_touchdowns = 0; num_safeties * 2 + num_field_goals * 3 + num_touchdowns * 6 <= points; num_touchdowns++) {
                for (int num_td_extra = 0; num_safeties * 2 + num_field_goals * 3 + num_touchdowns * 6 + num_td_extra * 1 <= points; num_td_extra++) {
                    if (num_safeties * 2 + num_field_goals * 3 + num_touchdowns * 6 + num_td_extra * 1 == points) {
                        printf("%d Safeties, %d Field Goals, %d Touchdowns, %d Extra Points\n", 
                               num_safeties, num_field_goals, num_touchdowns, num_td_extra);
                    }
                }
            }
        }
    }
}
