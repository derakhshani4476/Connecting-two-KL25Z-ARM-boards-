#include "mbed.h"
#include <stdio.h>
#include "rtos.h"



Serial uart (PTE0,PTE1);
Serial pc(USBTX, USBRX);
Thread thread1;
Thread thread3;
char c;
char command;
Timer timer1;
int counter = 0;
int count = 0;
int num [4];
void task1();
void task3();
void send2();
void send4();
void task5();
int total = 0; 
float temparray[32]={};
int average = 0;
float flo; 
int count1;
int char2int(char c);
Thread *RX_THREAD_POINTER;
int  sum=0;

// Rx Interupt routine
/*
void Rx_interrupt(void){
    uart.attach(NULL);                  // Disable Rx interrupt
    (*RX_THREAD_POINTER).signal_set(0x1); // dereference of RX_THREAD_POINTER
}
 */
 // Read received chars from UART
 /*
void rx_thread(void const *argument){
    while (true) {
        // Signal flags that are reported as event are automatically cleared.
        Thread::signal_wait(0x1);
        while (! (uart.readable())) {
          //pc.putc(uart.getc());             // read data from UART
          command = uart.getc();
          printf("%c",command);
   
        }
        uart.attach(&Rx_interrupt);             // Enable Rx interrupt
    }
}
*/
void task5(){
  }
  int char2int(char c){
        
        if (c =='0'){
             return 0;
             }
        else if(c=='1'){
            return 1;
            }
         else if(c=='2'){
           return 2;
           }
            else if(c=='3'){
            return 3;
            }
            else if(c=='4'){
            return 4;
            }
            else if(c=='5'){
            return 5;
            }
            else if(c=='6'){
            return 6;  
            }
            else if(c=='7'){
            return 7;
            }
            else if(c=='8'){
            return 8;
            }
            else if(c=='9'){
            return 9;
            }
       
        }

void task1(){
    
    timer1.read();
    counter ++;
    if(counter%50==0){
              if(uart.writeable())
              uart.putc('2');
            }
    if(counter%10==0){   
    if(uart.writeable())
        uart.putc('4');
        }  
        
        pc.printf("task1 ");
 }   
void task3(){
   
while(!(uart.readable()));
command = uart.getc();


 for(int i=0;i<32;i++){
   for(int j=3;j>-1;j--){
       
         num[j] = char2int(command); 
  
      }
         sum =sum+ ( num[3]*1000+ num[2]*100+ num[1]*10+ num[0]);
       //printf("sum is : \r\n%d",sum); 
     
      }
      average = (sum/3200);
        printf(" average is :%d\r\n",average);
     //uart.putc(average);
   printf("task3");
  
  task5();

}
     


int main() {
  
  char c;
  
   
   while (1){
     timer1.start();
     thread1.start(task1);
     count1++;
     if(count1%50 == 0){


     thread3.start(task3);
       } 
        wait(0.1);
   }

}
