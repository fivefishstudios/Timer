#include "mbed.h"

Timer t;
Serial pc(USBTX, USBRX);  
DigitalOut led(PG_13); 

int main(){
  pc.baud(115200);
  
  t.start();                    // start timer
  pc.printf("Hello World!\n");  // do something
  t.stop();                     // stop timer
  // time difference == length of execution time
  pc.printf("Time to execute printf() is %f seconds \n", t.read());
  pc.printf("Time to execute printf() is %d microseconds \n\n", t.read_high_resolution_us());

  // to measure a new task, we need to rese timer.
  // otherwise time is just incremented/added to previous results
  t.reset();  

  t.start();    // start timer
  led = !led;   // do something 
  t.stop();     // stop timer
  // how long did that take?
  pc.printf("Time to execute gpio toggle is %f seconds \n", t.read());
  pc.printf("Time to execute gpio toggle is %d microseconds \n", t.read_high_resolution_us());

}

// OUTPUT
Hello World!
Time to execute printf() is 0.001052 seconds 
Time to execute printf() is 1052 microseconds 

Time to execute gpio toggle is 0.000003 seconds 
Time to execute gpio toggle is 3 microseconds 