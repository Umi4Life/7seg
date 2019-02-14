#ifndef QUAD7SEGMENT_H
#define QUAD7SEGMENT_H
#include "HC595.h"

class Quad7Segment{
  public:
    Quad7Segment(int ser, int srClk, int rClk, int srClr):
      shreg(ser,srClk,rClk,srClr){};
    static const int pattern[10];
    void setup();
    void update();
    void setNumber(int n);
   //add other stuff if you need
  private:
    HC595 shreg;
    int buffer[4];
};

#endif
