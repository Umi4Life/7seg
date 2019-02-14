#include "Quad7Segment.h"
#include "HC595.h"

// 0 means on 1 means off
//http://www.nutsvolts.com/magazine/article/using-seven-segment-displays-part-1
const int Quad7Segment::pattern[10] = { 
  //abcdefg
  0b000000110000, //0
  0b100111110000, //1
  0b001001010000, //2
  0b000011010000, //3
  0b100110010000, //4
  0b010010010000, //5
  0b010000010000, //6
  0b000111110000, //7
  0b000000010000, //8
  0b000110010000 //9
};
int buffer[4];

void Quad7Segment::setup(){
  shreg.pushn(0b00000010000,12);
  shreg.latch();
}

void Quad7Segment::update(){
  for(int i=0; i<4; i++){
    shreg.pushn(buffer[i],12);
    shreg.latch();
  }
}

void Quad7Segment::setNumber(int n){
  if(n<=9999){
    buffer[3] = pattern[((n/1000))]|8;
    buffer[2] = pattern[((n/100)%10)]|4;
    buffer[1] = pattern[((n/10)%10)]|2;
    buffer[0] = pattern[((n)%10)]|1;
  }
}

  
