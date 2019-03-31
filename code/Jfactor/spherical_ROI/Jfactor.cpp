/*****************************************************************************
Computes the J-factor for a generalized NFW profile in a spherical sphere
(with radius theta_max) centred at the Galactic centre (GC).

The J-factor is the integral of the density profile's square over the line of 
sight.

It is a 2-dimensional integral integrated over theta
and s or line of sight up to a maximum value s_max.

The generalized NFW dark matter density profile is characterized by 3 free 
parameters:
(1) the local dark matter density rho_0
(2) the inner slope alpha
(3) the scale radius

OUTPUT:
(1) J-factor value (GeV²/cm⁵)


Uses cuba library for integration

******************************************************************************/

#include "cuba.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
using namespace std;

/* __ Member definitions _________________________________________________ */
// Integral variables
#define NDIM 2
#define NCOMP 1  // number of components of the integral 
                 // integral[NCOMP], error[NCOMP], prob[NCOMP]
#define USERDATA NULL
#define NVEC 1

#define EPSREL 1e-3
#define EPSABS 1e-11

#define VERBOSE 0 // control de information on integrals print in terminal
#define LAST 4
#define MINEVAL 0
#define MAXEVAL 100000 

#define STATEFILE NULL
#define SPIN NULL

#define KEY 13   // Key -> 0, chooses the basic integration rule: 
                 // Key = 7,9,11,13 selects the cubature rule of degree Key.
                 // Note: degree-11 rule is available only in 3 dimensions,
                 // the degree-13 rule only in 2 dimensions.

/* __ Structure definitions ______________________________________________ */
struct params {double R0;
               double alpha; 
               double rhos; 
               double rs;
               double smax;
               double theta_max;};

/***********************************************************************//**
 * @brief J-factor integrand
 ***************************************************************************/
static int Integrand (const int *  ndim, 
                      const double xx[],
                      const int *  ncomp, 
                      double       ff[], 
                      void *       userdata) 
{
    params p = *(params*) userdata;

    //The integration's interval is [0,1]^3. Therefore, rescale
    double sp     = p.smax * xx[0];
    double thetap = p.theta_max * xx[1];
    #define f   ff[0]

    double r      = sqrt(pow(p.R0,2)+pow(sp,2)-2*p.R0*sp*cos(thetap));

    f = pow(p.rhos*pow(r/p.rs, -p.alpha)*pow(1+r/p.rs, -3+p.alpha), 2)*
        sin(thetap)*p.theta_max*(2*M_PI)*p.smax;
    // Return
    return 0;
}

/***********************************************************************//**
 * @brief J-factor
 ***************************************************************************/
double jfactor(double R0,
               double alpha, 
               double rhos, 
               double rs,
               double smax,
               double theta_max)
{
    params p = {R0, alpha, rhos, rs, smax, theta_max};

    int comp, nregions, neval, fail;
    double integral[NCOMP], error[NCOMP], prob[NCOMP];

    Cuhre(NDIM, NCOMP, Integrand, &p, NVEC,
          EPSREL, EPSABS, VERBOSE | LAST,
          MINEVAL, MAXEVAL, KEY,
          STATEFILE, SPIN,
          &nregions, &neval, &fail, integral, error, prob);

    /*printf("CUHRE RESULT:\tnregions %d\tneval %d\tfail %d\n",
           nregions, neval, fail);
    for( comp = 0; comp < NCOMP; ++comp )
        printf("CUHRE RESULT:\t%.8f +- %.8f\tp = %.3f\n\n",
               integral[comp], error[comp], prob[comp]);*/

    comp = NCOMP-1;

    // conversion factor : 1 kpc = 3.0857e21 cm
    // Return
    return integral[comp]*(3.0857e21);
}


/**************************************************
    MAIN FUNCTION
***************************************************/
/*
int main()
{
    double smax       = 400.;
    // Radius of sphere [radians]
    double theta_max  = 2.*M_PI/180.;
    // Sun galactocentric distance
    double R0         = 8.33;
    // DM parameters
    double alpha      = 1.; 
    double rs         = 24.42;
    double rho0       = 0.3; 

    double Jfactor = jfactor(R0, alpha, rho0, rs, smax, theta_max);
    cout << Jfactor << endl;

// The units of the J-factor are GeV²/cm⁵

return 0;
}
*/
