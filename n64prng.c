#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
typedef uint16_t u16;
typedef uint32_t u32;

// gSeed can be u32 or u16
u16 gSeed = 1;
u16 prng(){
    gSeed ^= (gSeed << 7);
    gSeed ^= (gSeed >> 9);
    gSeed ^= (gSeed << 8);
    return (u16)gSeed;
}
int test(bool preview){
	int number_of_values = 65536;
	bool generated[number_of_values];
	memset(generated, 0, sizeof generated);
	
	if (preview){
		printf("First 20 values with seed 0: ");
	}
	
	for (int i = 0; i < number_of_values; ++i){
		u16 s = prng();
		generated[s] = true;
		// we also preview the first 20 values of the generator.
		if (preview && i < 20) printf("%d ", s);
	}
	int number_of_values_generated = 0;
	for (int i = 0; i < number_of_values; ++i){
		number_of_values_generated += generated[i];
	}
	return number_of_values_generated;
}

// Driver function to test
int main(){
	double average = 0.0; 
	//  mass test
	int max_generated_values = 0, max_seed = 0, min_generated_values = 65536, min_seed = 0;
	for (u32 i = 0; i < 65536; ++i){
		gSeed = i;
		u32 number_of_values_generated = test(false);
		if (number_of_values_generated > max_generated_values){
			max_generated_values = number_of_values_generated;
			max_seed = i;
		}
		else if (number_of_values_generated < min_generated_values){
			min_generated_values = number_of_values_generated;
			min_seed = i;
		}
		printf("Seed %d generated %d values\n", i, number_of_values_generated);
		average += number_of_values_generated;
	}
	printf("The most amount of values generated is by seed %d, with %d values.\n", max_seed, max_generated_values);
	printf("The least amount of values generated is by seed %d, with %d values.\n", min_seed, min_generated_values);
	printf("On average, a seed generates %f values.\n", average / 65536);
	// demo
	gSeed = 0;
	test(true);
	printf("\n"); // we need to move to the next line
}
