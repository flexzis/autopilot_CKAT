#include "base_filter.h"
#include "math_utils.h"

// DigitalLPF implements the filter math
template <class T>
class DigitalLPF
{
public:
    DigitalLPF():
        _output{T()}
    {}
    // add a new raw value to the filter, retrieve the filtered result
    T apply(const T &sample, float cutoff_freq, float dt);
    T apply(const T &sample);

    void compute_alpha(float sample_freq, float cutoff_freq);
    
    // get latest filtered value from filter (equal to the value returned by latest call to apply method)
    const T &get() const;
    void reset(T value);
    void reset()
    {
        initialised = false;
    }

private:
    T _output;
    float alpha = 1.0f;
    bool initialised;
};

template <class T>
T DigitalLPF<T>::apply(const T &sample) {
    _output += (sample - _output) * alpha;
    if (!initialised) {
        initialised = true;
        _output = sample;
    }
    return _output;
}

template <class T>
void DigitalLPF<T>::compute_alpha(float sample_freq, float cutoff_freq) {
    if (sample_freq <= 0) {
        alpha = 1;
    } else {
        alpha = calc_lowpass_alpha_dt(1.0/sample_freq, cutoff_freq);
    }
}

// get latest filtered value from filter (equal to the value returned by latest call to apply method)
template <class T>
const T &DigitalLPF<T>::get() const {
    return _output;
}

template <class T>
void DigitalLPF<T>::reset(T value) { 
    _output = value;
    initialised = true;
}

// LPF base class
template <class T>
class LowPassFilter
{
public:
    LowPassFilter();
    LowPassFilter(float cutoff_freq);
    LowPassFilter(float sample_freq, float cutoff_freq);

    // change parameters
    void set_cutoff_frequency(float cutoff_freq);
    void set_cutoff_frequency(float sample_freq, float cutoff_freq);

    // return the cutoff frequency
    float get_cutoff_freq(void) const;
    T apply(T sample, float dt);
    T apply(T sample);
    const T &get() const;
    void reset(T value);
    void reset(void) { _filter.reset(); }

protected:
    float _cutoff_freq;

private:
    DigitalLPF<T> _filter;
};


// add a new raw value to the filter, retrieve the filtered result
template <class T>
T DigitalLPF<T>::apply(const T &sample, float cutoff_freq, float dt)
{
    if (cutoff_freq <= 0.0f || dt <= 0.0f)
    {
        _output = sample;
        return _output;
    }
    float rc = 1.0f/(M_2PI*cutoff_freq);
    alpha = clip(dt/(dt+rc), 0.0f, 1.0f);
    _output += (sample - _output) * alpha;
    if (!initialised)
    {
        initialised = true;
        _output = sample;
    }
    return _output;
}

////////////////////////////////////////////////////////////////////////////////////////////
// LowPassFilter
////////////////////////////////////////////////////////////////////////////////////////////

// constructors
template <class T>
LowPassFilter<T>::LowPassFilter() :
    _cutoff_freq(0.0f) {}

template <class T>
LowPassFilter<T>::LowPassFilter(float cutoff_freq) :
    _cutoff_freq(cutoff_freq) {}

template <class T>
LowPassFilter<T>::LowPassFilter(float sample_freq, float cutoff_freq)
{
    set_cutoff_frequency(sample_freq, cutoff_freq);
}

// change parameters
template <class T>
void LowPassFilter<T>::set_cutoff_frequency(float cutoff_freq) {
    _cutoff_freq = cutoff_freq;
}

template <class T>
void LowPassFilter<T>::set_cutoff_frequency(float sample_freq, float cutoff_freq) {
    _cutoff_freq = cutoff_freq;
    _filter.compute_alpha(sample_freq, cutoff_freq);
}

// return the cutoff frequency
template <class T>
float LowPassFilter<T>::get_cutoff_freq(void) const {
    return _cutoff_freq;
}

template <class T>
T LowPassFilter<T>::apply(T sample, float dt) {
    return _filter.apply(sample, _cutoff_freq, dt);
}

template <class T>
T LowPassFilter<T>::apply(T sample) {
    return _filter.apply(sample);
}

template <class T>
const T &LowPassFilter<T>::get() const {
    return _filter.get();
}

template <class T>
void LowPassFilter<T>::reset(T value) {
    _filter.reset(value);
}