#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  this->Kp = Kp_;
  this->Ki = Ki_;
  this->Kd = Kd_;

}

void PID::UpdateError(double cte) {
  // Update PID errors based on cte.
  double old_p_error = p_error;
  p_error = cte;
  i_error += cte;
  d_error = cte - old_p_error;
}

double PID::TotalError() {
  // Calculate and return the total error
  return - (Kp*p_error + Ki*i_error + Kd*d_error);
}