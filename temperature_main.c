
#include "temperature.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <temperature> <scale>\n", argv[0]);
        printf("Scale options: C (Celsius), F (Fahrenheit), K (Kelvin)\n");
        return 1;
    }

    float input_temp = atof(argv[1]);
    char scale = argv[2][0];

    float celsius_temp;

    // Convert input to Celsius
    if (scale == 'C' || scale == 'c') {
        celsius_temp = input_temp;
    } else if (scale == 'F' || scale == 'f') {
        celsius_temp = fahrenheit_to_celsius(input_temp);
    } else if (scale == 'K' || scale == 'k') {
        celsius_temp = kelvin_to_celsius(input_temp);
    } else {
        printf("Invalid scale. Use 'C', 'F', or 'K'.\n");
        return 1;
    }

    // Convert to all scales
    float fahrenheit = celsius_to_fahrenheit(celsius_temp);
    float kelvin = celsius_to_kelvin(celsius_temp);

    // Classify and provide advisory
    const char* category = classify_temperature(celsius_temp);
    const char* advisory = get_advisory(category);

    // Output results
    printf("Converted Temperatures:\n");
    printf("Celsius: %.2f\n", celsius_temp);
    printf("Fahrenheit: %.2f\n", fahrenheit);
    printf("Kelvin: %.2f\n", kelvin);
    printf("\nClassification: %s\n", category);
    printf("Advisory: %s\n", advisory);

    return 0;
}
