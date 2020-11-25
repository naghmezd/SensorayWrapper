#include <iostream>
#include <vector>
#include "simple826.hpp"
#include <unistd.h>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "forcesensor.hpp"
#include <chrono>  // for high_resolution_clock

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main function.

int main(int argc, char **argv)
{
  ForceSensor Force;
  Vector6FT ft_1;
  int numSample =4;//Number of samples needed to get average in buffer
 
  int frequency =1000;
  Force.FTSetOffset(1000);//Get the offset from the first 1000 data

   // Record start time
  auto start = std::chrono::high_resolution_clock::now();
  for (int i=0;i<frequency;i++){
    ft_1=Force.GetCurrentFT(numSample) ;
    //std::cout<<ft_1[2]<<std::endl;
  }
  auto finish = std::chrono::high_resolution_clock::now();  
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>( finish - start ).count();
  std::cout << "Each loop"<<duration/(frequency*1000.0);
    return 0;
}

