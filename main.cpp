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



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main function.

int main(int argc, char **argv)
{
  double volt = -6.32;
  double volt2;
  uint channel = 0;
  Simple826 B826;
  B826.SetDacOutput(&channel, &volt);
  B826.GetDacOutput(&channel, &volt2);
  B826.GetDacOutput(&channel, &volt2);
  B826.GetDacOutput(&channel, &volt2);
  std::cout<<"Check this:     "<<volt2<<std::endl;

    return 0;
}



//////////////////////////////////