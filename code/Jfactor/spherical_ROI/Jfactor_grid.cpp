/*****************************************************************************
    Scan a grid in (rhos, rs) and compute the J-factor at each point

******************************************************************************/

#include "cuba.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;

/***********************************************************************//**
 * @brief J-factor
 ***************************************************************************/
double jfactor(double R0,
               double alpha, 
               double rhos, 
               double rs,
               double smax,
               double theta_max);


/***********************************************************************//**
@brief J-factor (in a sphere radius theta, centered at GC) grid

@OBSERVATIONS UNITS OF THE J-FACTOR ARE GEV²/CM⁵
***************************************************************************/
void jfactorgrid_fixed_gamma(double gamma,
                             double theta)
{
    vector <double> chi, rhos, Rs, R0;
    string line;
    // Chi2 marginalised over baryonic morphology for each R0
    std::ostringstream filename;
    filename << "../../../data/gNFW/"
             << "4dgrid_gamma" << ("%.1f", gamma) << ".dat";
    std::fstream in(filename.str().c_str(), ios::in);
    if (in.is_open())
    {
        // Read input file
        while (getline(in, line))
        {
            if (line.empty() || line[0] == '#')
                continue;
            double r = 0., g = 0., rho = 0., _Rs = 0., _chi = 0.;
            sscanf(line.c_str(), "%lf %lf %lf %lf %lf", &r, &g, &rho, &_Rs, 
                   &_chi);
            R0.push_back(r);
            rhos.push_back(rho);
            Rs.push_back(_Rs);
            chi.push_back(_chi);
        } 
    }
    in.close();

    double smax = 400.;

    std::ostringstream file_out;
    file_out << "jfactorgrid_gamma" << gamma << ".dat";
    std::ofstream out(file_out.str().c_str());
    if (out.is_open())
    {
        out.precision(11);
        out << "# chi2  Jfactor[GeV2/cm5]" << endl;
        for (int i = 0; i < int(rhos.size()); i++)
        {
            out << chi[i] << "  " 
                << jfactor(R0[i], gamma, rhos[i], Rs[i], smax, theta)
                << endl;
        }
    }
    out.close();

    // Return
    return;
}


/***********************************************************************//**
    MAIN FUNCTION
***************************************************************************/
int main(int argc, char* argv[])
{
    // TWO INPUT PARAMETERS:
    // (1)  Inner slope gNFW (gamma)
    // (2)  radius of sphere (theta)
    double gamma = atof(argv[1]);
    double theta = atof(argv[2]);

    jfactorgrid_fixed_gamma(gamma, theta);

    // Return
    return 0;
}


