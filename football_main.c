#include "football.h"


int main(int argc, char *argv[]) {
    // Ensure proper command-line usage
    if (argc != 2) {
        printf("Usage: %s <score>\n", argv[0]);
        return 1;
    }

    // Convert argument to integer
    int points = atoi(argv[1]);
    
    // Validate input
    if (points < 2) {
        printf("Invalid input: Score must be 2 or higher.\n");
        return 1;
    }

    // Call functions from football.c
    int combinations = count_combinations(points);
    printf("Total possible combinations: %d\n", combinations);
    print_combinations(points);

    return 0;
}
