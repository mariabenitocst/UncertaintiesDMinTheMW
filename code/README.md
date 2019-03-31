# Useful code

## J-factor

The Jfactor folder contains the c++ code for computing the J-factor at 
a given ROI (spherical/rectangular) centered at the Galactic center (GC) at each point of the likelihood profile table
given in **data/4dgrid_gammaXX.dat**.


### Dependencies 
 [Cuba 4.1](http://www.feynarts.de/cuba/)


## chi2_profile.ipynb

Computes the chi2 profile for the J-factor (equivalent to figure 6 in [Benito et al. 2019](https://arxiv.org/pdf/1901.02460.pdf)).

Takes as input **jfactorgrid_gammaXX.dat** (output from c++ code in Jfactor folder)


### Dependencies
python 2.7


