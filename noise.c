#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLING_RATE 48000
#define NUM_SECONDS 5
#define NUM_SAMPLES (NUM_SECONDS * SAMPLING_RATE)

int main(void) {
	FILE *file = fopen("noise.raw", "wb");

	srand(time(NULL));

	for (int i = 0; i < NUM_SAMPLES; i++) { 
		float sample = .9 * (2 * ((float)rand()/(float)RAND_MAX)) - 1;
		fwrite(&sample, sizeof(float), 1, file);
	}
	fclose(file);
}

//Creates a 5-second file (`noise.raw`) containing white noise. 32-bit 48k floating point raw PCM. 
//You can play this back with SoX like this:
//play -c 1 -r 48000 -b 32 -e float -t raw out.raw