//
//  integration.cpp
//  Weibull
//


#include "integration.h"

Integration::Integration(const int &_intervals){
    this->intervals = _intervals;
}

double Integration::integrate(double (*pfun)(const double &x, const double y), const double &upBound, const double &lowBound, const double beta){
    double sum = 0;
    
    double intSize = (upBound - lowBound)/intervals;
    
    for (int i = 0; i<intervals; i++) {
        
        if(i == 0 || i == intervals-1){
            sum += (*pfun)((lowBound + i*intSize), beta);
                }
                else{
                    sum += ((*pfun)((lowBound + i*intSize), beta))*2;
                        }
    }
    return 0.5*sum*intSize;
}