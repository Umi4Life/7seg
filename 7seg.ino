#include "HC595.h"
#include "Quad7Segment.h"
HC595 shreg(2,3,4,5);
const int pattern[10] = { 
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
Quad7Segment seg(2,3,4,5);
void setup() {
  Serial.begin(9600);
}

void loop() {
  int rd = analogRead(A0);
//  Serial.println(rd);
  seg.setNumber(rd);
  seg.update();
//  shreg.pushn(pattern[2]+8, 12);
//  shreg.latch();
//  seg.pushn(0b110100110100, 12);
//  seg.latch();
//  seg.pushn(0b100100110010, 12);
//  seg.latch();
//  seg.pushn(0b111000110001, 12);
//  seg.latch();

}
