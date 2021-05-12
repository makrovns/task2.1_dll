#include "sin_library.h"

    namespace {
       
        double pow(double x, int power) 
        {
            double step = x;
       
            if (power == 0) {
                step = 1;
            }
        
            for (int i = 1; i < power; i++) 
            {
                step *= x;
            }
            
            return step;
        }

        double factorial(double n) 
        {
            if (n == 0)
                return 1;
            
            return n * factorial(n - 1);
        }

    }
    
   
    double mysin::sin(double angl) 
    {
        double sinx = 0;
        
        for (size_t i = 1; i < 15; ++i) 
        {
            sinx += ((pow((-1), ( i - 1)) * pow((angl),( 2 * i - 1))) / (factorial(2 * i - 1)));
        }
        
        return sinx;
    }