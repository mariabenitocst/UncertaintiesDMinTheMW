# Quantifying Astrophysical Uncertainties in the Galactic Dark Matter Distribution 

Here we make available the likelihood profile of the data-driven analysis presented in 
[Benito et al. 2020](https://arxiv.org/abs/2009.13523) ([published in PDU](https://doi.org/10.1016/j.dark.2021.100826)). This analysis is an update of our previous results presented in [Benito et al. 2019](https://arxiv.org/abs/1901.02460) ([published in JCAP](https://doi.org/10.1088/1475-7516/2019/03/033)), and it is motivated by recent determinations of Galactic parameters (namely Sun's galactocentric distance and circular velocity) from the [GRAVITY collaboration](https://arxiv.org/abs/1904.05721) and the [GAIA satellite](https://iopscience.iop.org/article/10.3847/1538-4357/aaf648).

### Brief Description

[Benito et al. 2020](https://arxiv.org/abs/2009.13523) quantifies astrophysical uncertainties that affect the determination of the distribution of dark matter (DM) in the Milky Way (MW) by means of the rotation curve (RC) method.
The input elements of our analysis are:
* [galkin](https://github.com/galkintool/galkin) compilation for the observed RC of our Galaxy;
* latest (AD 2020) constraints on the Sun's galactocentric distance and its circular velocity from the [GRAVITY collaboration](https://arxiv.org/abs/1904.05721) and the [GAIA satellite](https://iopscience.iop.org/article/10.3847/1538-4357/aaf648);
* large array of observationally inferred three-dimensional density profiles for each baryonic component of the Galaxy (stellar bulge, stellar disc and interstellar gas);
* DM halo described by a generalized Navarro-Frenk-White (gNFW), Einasto or Burkert density profile.

We perform a full marginalization over uncertainties on the Galactic parameters and over the lack of knowledge on the morphology and content of the baryonic components of the Galaxy. You can find a complete description of the analysis in [Benito et al. 2020](https://arxiv.org/abs/2009.13523) and [Benito et al. 2019](https://arxiv.org/abs/1901.02460).

### Content

The full likelihood of our analysis is released in tabular form (in the **data** folder) in a multidimensional grid in the parameters characterizing the DM distribution, namely:
* the scale radius Rs, the scale density ρs, the inner slope of the profile γ and the Sun's circular velocity V0 *for the gNFW density profile*.
* The scale radius Rs, the scale density ρs, the inner slope of the profile α and the Sun's circular velocity V0 *for the Einasto density profile*.
* And the core radius Rc, central density ρc and the Sun's circular velocity V0 *for the Burkert density profile*.

In the **data** folder, you can further find the full likelihood obtained in [Benito et al. 2019](https://arxiv.org/abs/1901.02460).


In the **code** folder, you can find some useful code for computing the J-factor at the Galactic centre for a spherical region of interest.

### Applications

The likelihood can be used to include the effect of uncertainties in the DM distribution in the MW while interpreting results of searches for an indirect DM signal in gamma-rays or neutrinos, from the Galactic center (GC), or the halo region surrounding it.

Further applications involve the interpation of results from local DM searches, like direct detection and anti-matter observations, or global fits combining local and GC searches.

### Credit

If you use this material, please don't forget to cite [Benito et al. 2020](https://arxiv.org/abs/2009.13523) and [Benito et al. 2019](https://doi.org/10.1088/1475-7516/2019/03/033). Please cite in bundle with [Pato et al. 2015](https://iopscience.iop.org/article/10.1088/1475-7516/2015/12/001) and [Benito et al. 2017](https://iopscience.iop.org/article/10.1088/1475-7516/2017/02/007/meta). 

Thanks :)

### Contact Information

Do not heasitate to contact one of us if there is any question related to this material. 
Here is our contact information:
* mariabenitocstATgmail.com
* alessandro.cuocoATunito.it 
* fabio.iocco.astroATgmail.com
