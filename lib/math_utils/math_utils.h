#include <cmath>

template <class T>
T clip(T val, T lower_bound, T upper_bound)
{
    if (val < lower_bound)
        return lower_bound;
    if (val > upper_bound)
        return upper_bound;
    return val;
}