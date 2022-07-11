class PID
{
    double kp, kd, ki;
    double min_err, max_err;
    double dt;
    int N;
    
    public:
    PID(double kp, double kd, double ki,
        double min_err=0., double max_err=100.,
        double dt = 0.001, int N = 10)
    : kp {kp}, kd {kd}, ki {ki}
    , min_err {min_err}, max_err {max_err}
    , dt {dt}, N{N}
    {}

    double calculate(double val, double des_val)
    {
        double err = val - des_val;
        return kp * err;
    }
};