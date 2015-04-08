#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLING_RATE 48000
#define NUM_SECONDS 5
#define NUM_SAMPLES (NUM_SECONDS * SAMPLING_RATE)
#define FREQ 1000

int main(void) {
	FILE *file = fopen("sawtooth.raw", "wb");
	
	for (int i = 0; i < NUM_SAMPLES; i++) { 
		float sample = 0;

		for (int harmonic = 1; (FREQ * harmonic) <= (SAMPLING_RATE / 2); harmonic += 1) {
			sample += -1 * sin(2 * M_PI * harmonic * FREQ * i / SAMPLING_RATE) / harmonic;
		}

		sample *= (1.0 / 2);
		
		fwrite(&sample, sizeof(float), 1, file);
	}
	fclose(file);
}

//Creates a 5-second file (`sawtooth.raw`) containing a 1k square tone. 32-bit 48k floating point raw PCM. 
//You can play this back with SoX like this:
//play -c 1 -r 48000 -b 32 -e float -t raw sawtooth.raw