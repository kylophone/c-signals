#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLING_RATE 48000
#define NUM_SECONDS 5
#define NUM_SAMPLES (NUM_SECONDS * SAMPLING_RATE)
#define FREQ 1000

int main(void) {
	FILE *file = fopen("sine.raw", "wb");

	for (int i = 0; i < NUM_SAMPLES; i++) { 
		float sample = sin(2 * M_PI * FREQ * i / SAMPLING_RATE);
		fwrite(&sample, sizeof(float), 1, file);
	}
	fclose(file);
}

//Creates a 5-second file (`sine.raw`) containing a 1k sine tone. 32-bit floating point raw PCM. 
//You can play this back with SoX like this:
//play -c 1 -r 48000 -b 32 -e float -t raw out.raw