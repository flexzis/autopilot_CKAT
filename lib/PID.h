

class PID
{
    double kp, kd, ki;
    double min_err, max_err;
    double dt;
    public:

    PID(double kp, double kd, double ki,
        double min_err=0., double max_err=100., double dt = 0.001)
    : kp {kp},kd {kd}, ki {ki}, min_err {min_err}, max_err {max_err}, dt {dt}
    {}

    double calculate()
};