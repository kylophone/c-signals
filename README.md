# c-signals
Example audio oscillators in C. Each oscillator is implemeted in less than 30 lines of C. 

:: <a href = "sine.c">SINE</a> :: <a href = "square.c">SQUARE</a>  :: <a href = "noise.c">NOISE</a> :: <a href = "sawtooth.c">SAWTOOTH</a> :: <a href="triangle.c">TRIANGLE</a> ::

## Usage
Compile and run. 
```
gcc ./sine.c -o sine
./sine
```
This will create a 32-bit floating point 48kHz raw PCM file called `sine.raw`.

## Playing back with SoX
```
play -c 1 -r 48000 -b 32 -e float -t raw sine.raw
```
