#include "PID.h"
#include<iostream>
#include<vector>
#include<numeric>
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
   
   Kp = Kp_;
   Ki = Ki_;
   Kd = Kd_;
  
   i_error = 0.0;
   p_error = 0.0;
   d_error = 0.0;
   prev_cte = 0.0;
  
   
   
   //Initialize variables for implmenting twiddle
   //twiddle = true;  // Set it to true to ontain tuned PID parameters
   //best_error  = 10000;  
   //twiddle_state = 0; 
   //iterations = 0;
   //index = 0; 
   //tol = 0.01;
   //p = {0.2,0.002,2.0};  //Initial PID values obtained after manual tuning
   //dp = {0.01, 0.01, 0.01};
  
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */

  p_error = cte;
  d_error = cte - prev_cte;  // Taking delta_t as 1 
  i_error += cte;
  prev_cte = cte;
  
  //if(twiddle)
  //   Twiddle();
  
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  //std::cout<<"p_error:"<<p_error<<"d_error:"<<d_error<<"i_error:"<<i_error<<std::endl;
  //std::cout<<"Kp:"<<Kp<<"Ki:"<<Ki<<"Kd:"<<i_error<<std::endl;
  double total_error = -Kp*p_error - Kd*d_error - Ki*i_error;
  return total_error;  // TODO: Add your total error calc here!
}

/*void PID::Twiddle()
{
  // Reference for Twiddle implementation : https://knowledge.udacity.com/questions/294721
  double sum = dp[0] + dp[1] + dp[2];
  std::cout<<"sum:"<<std::endl;
  if(sum>tol)
  {
     if (twiddle_state == 0)
     {
        best_error = TotalError();
        p[index] += dp[index];
        twiddle_state = 1;
     }
    
     else if (twiddle_state == 1) 
     {
       if (TotalError() < best_error) 
       {
          best_error = TotalError();
          dp[index] *= 1.1;
          index = (index + 1) % 3; //rotate over the 3 vector indice
          p[index] += dp[index];
          twiddle_state = 1;
       }
       else 
       {
          p[index] -= 2 * dp[index];
          if (p[index] < 0) 
          {
            p[index] = 0;
            index = (index + 1) % 3;
          }
          twiddle_state = 2;
       }
     } 
    
     else
     { //twiddle_state_ = 2
       if (TotalError() < best_error)
       {
         best_error = TotalError();
         dp[index] *= 1.1;
         index = (index + 1) % 3;
         p[index] += dp[index];
         twiddle_state = 1;
       }
       else
       {
         p[index] += dp[index];
         dp[index] *= 0.9;
         index = (index + 1) % 3;
         p[index] += dp[index];
         twiddle_state = 1;
       }
     }
    
     iterations+=1;
     std::cout<<"Sum: "<<sum <<" , iterations - "<<iterations<<std::endl;
     std::cout<<"Tuned PID values: ("<<p[0]<<","<<p[2]<<","<<p[1]<<");"<<std::endl;
  }  
    
  else
  {
    std::cout<<"iterations : "<<iterations<<std::endl;
    std::cout<<"Final Tuned PID values: ("<<p[0]<<","<<p[2]<<","<<p[1]<<");"<<std::endl;
    twiddle = false;
  }  
}    */
        
  
  
  