#include "time_utils.h"
#include <cmath>

template <class T>
class PID
{
    double kp, kd, ki;
    double min_outp, max_outp;
    unsigned long last_t;
    double last_err;
    double last_derivative; 
    double integrator;
    bool first_time;
    // anything over 20 Hz will be considered as noise
    static const uint8_t fCut = 20;  

    public:
    PID(double _kp = 0.,
        double _kd = 0.,
        double _ki = 0.,
        double _min_err = 0.,
        double _max_err = 100.,
        double _imax = 0.)

    : kp {_kp}, kd {_kd}, ki {_ki}
    , min_err {_min_outp}, max_err {_max_outp}
    , imax {_imax}, last_derivative { 0. }, first_time{ true }
    {}

    double GetOutput(double val, double target_val)
    {
        double err = val - target_val;
        double p_out = kp * error;
        double dt = get_time() - last_time;

        double d_out = 0.;
        if (!first_time && !(dt == 0))
            d_out = kd * (err - last_err) / dt;

        last_err = err;
        integrator += dt * error;
        double 
        return kp * err + kd * (err - err_old) + ki * (err);
    }
};