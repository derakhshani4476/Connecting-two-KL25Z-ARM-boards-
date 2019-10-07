#include "mbed.h"
#include <stdio.h>

//UARTSerial u1 (PTE0, PTE1 ,9600) ;
//UARTSerial u2 (PTE22, PTE23 ,9600) ;
Serial uart(PTE0,PTE1);
Serial pc(USBTX, USBRX);

float temps[] = {27,23.6,25.2,24.99,21.5,26,25,28,29,24.6,25.91,23.17,24.65,27.32,
23,29,27.51,22.6,27,26.45,26.15,27,29,24.6,25.91,23.17,24,17,
24.65,27.32,23,23.6,25.2,24.99,24.65,27.32,23,29,27.51,22.6,27,
26.45,26.15,27,29,24.6,25.91,23.17,24,17,24.65,27.32,23,23.6,
25.2,24.99,27,23.6,25.2,24.99,21.5,26,25,28
                  };
const int MAX = 1;
char buf1[MAX];
char buf2[MAX];
char command;
Thread thread1;
Thread thread2;
Thread thread4;
Thread thread5;
float temp2[64];
float temp3[32];
float x,average;
float timer[] = {};
//TextLCD lcd(PTA13, PTD5, PTD0, PTD1, PTD2, PTD3, TextLCD::LCD16x2); // RS, E, D4-D7
DigitalIn sw1(PTA5);
DigitalIn sw2(PTD2);
void task2();
void task4();
void send3();
void task5();



void read_commands(){
   if(uart.readable()){
          
          command = uart.getc();
          if(command == '2'){
              thread2.read(task2);
      
                   thread2.read(task2);
                   }
       else   if(command == '4'){
            
                  thread4.read(task4);
          }
           }
 }   

    
void update_time(){
    
    
    }
void task2(){
         //read temperture values from file
         //Receive  time from task1
              //if(uart.readable()){
//for (int i = 0; i < 1*sizeof(float); i++) {
  // *((char*)timer + i) = uart.getc();
  // pc.printf("%c",uart.getc());
   char x[5]={'a','b','c','d','e'};
   

    uart.putc(x[0]);
     uart.putc(x[1]);
      uart.putc(x[2]);
       uart.putc(x[3]);
    
    
pc.printf("task2");
         //send temp data to  board 1
      //   if(uart.writeable()){
               
            //   for (int i = 0; i < 64*sizeof(float); i++) {
            //uart.putc( *((char*)temps + i) );
           
                     
//}


         //read time
             //float current_time = timer[0];
    //set event for task3
    
   
    uart.putc('3');       
    //queue.call(send3);
    
 
     
    }
    
void task4(){
    
    pc.printf("task4 ");
    
    if(sw1 == 0){
        //display current temp and it's time (get data from task2 in  board 1)
        }
        
    else if(sw2 == 0){
        //display average temp and it's time  (get data from task3 in board 1)
        }
        
        task5();
    }

void task5(){  //do nothing
    }



int main() {
   
   
  
    while(1) {
        

    read_commands();

   
      
    }
}
