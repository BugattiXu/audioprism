#ifndef _REAL_DFT_HPP
#define _REAL_DFT_HPP

#include <vector>
#include <complex>

#include <fftw3.h>

class RealDft {
  public:
    enum class WindowFunction { Hanning, Hamming, Rectangular };

    RealDft(unsigned int N, WindowFunction wf);
    ~RealDft();

    /* Compute new DFT magnitude based on samples */
    void compute(std::vector<std::complex<double>> &dft, const std::vector<double> &samples);

    /* Get DFT size */
    unsigned int getSize();
    /* Get Window Function */
    WindowFunction getWindowFunction();

    /* Set DFT size */
    void setSize(unsigned int N);
    /* Set Window Function */
    void setWindowFunction(WindowFunction wf);

  private:
    unsigned int N;
    WindowFunction windowFunction;
    fftw_plan plan;
    double *wsamples;
    fftw_complex *dft;
    std::vector<double> window;
};

std::ostream &operator<<(std::ostream &os, const RealDft::WindowFunction &wf);
std::string to_string(const RealDft::WindowFunction &wf);

#endif

