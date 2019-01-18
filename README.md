# PID Controller
## Dependencies

-   cmake >= 3.5
-   All OSes:  [click here for installation instructions](https://cmake.org/install/)
-   make >= 4.1(mac, linux), 3.81(Windows)
    -   Linux: make is installed by default on most Linux distros
    -   Mac:  [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
    -   Windows:  [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
-   gcc/g++ >= 5.4
    -   Linux: gcc / g++ is installed by default on most Linux distros
    -   Mac: same deal as make - [install Xcode command line tools](([https://developer.apple.com/xcode/features/](https://developer.apple.com/xcode/features/))
    -   Windows: recommend using  [MinGW](http://www.mingw.org/)
-   [uWebSockets](https://github.com/uWebSockets/uWebSockets)
    -   Run either  `./install-mac.sh`  or  `./install-ubuntu.sh`.
    -   If you install from source, checkout to commit  `e94b6e1`, i.e.
        
        ```
        git clone https://github.com/uWebSockets/uWebSockets 
        cd uWebSockets
        git checkout e94b6e1
        
        ```
        
        Some function signatures have changed in v0.14.x. See  [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3)  for more details.
-   Simulator. You can download these from the  [project intro page](https://github.com/udacity/self-driving-car-sim/releases)  in the classroom.


## Basic Build Instructions

1.  Clone this repo.
2.  Make a build directory:  `mkdir build && cd build`
3.  Compile:  `cmake .. && make`
4.  Run it:  `./pid`

## Code

### Tuning

The tuning of the PID was made in an empiric way, as described by the Ziegler–Nichols tuning method. It is performed by setting the integral (Ki) and derivative gains to zero. The proportional gain, Kp, is then increased (from zero) until it reaches a "relatively" stable and consistent oscillations, even if the car was still leaving the road after some time when the road's bend is too curved.

By twiddling the parameters (first D and then I), the different values for the PID gains that were chosen are:
- Kp = 0.15
- Ki = 0.002
- Kd = 3.0

### Inputs/Outputs

The simulator provides to our program some inputs using JSON messages:
- Cross track error (cte)
- Steering angle (steering_angle)
- Vehicle's speed (speed)

After updating the error, the PID returns:
- Steering angle (steering_angle)
- Throttle (throttle), which is constant in our case.

### Results

![enter image description here](https://github.com/vincentbarrault/PID-controller/blob/master/res/PID.gif?raw=true)