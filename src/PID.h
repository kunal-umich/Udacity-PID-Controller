#ifndef PID_H
#define PID_H

#include<vector>
class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();
  
  //void Twiddle();

 private:
  /**
   * PID Errors
   */
  double p_error;
  double i_error;
  double d_error;
  double prev_cte;

  /**
   * PID Coefficients
   */ 
  double Kp;
  double Ki;
  double Kd;
  
  /*bool twiddle;
  double best_error;
  int twiddle_state;
  int iterations;
  int index; //Index of twiddle state
  double tol; //tolerance for termination of twiddle step
  std::vector<double> p;
  std::vector<double> dp;*/ 
  

};

#endif  // PID_H