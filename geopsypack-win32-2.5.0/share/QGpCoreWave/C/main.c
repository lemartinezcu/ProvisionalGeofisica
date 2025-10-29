
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <QGpCoreWave/FortranInterface.h>

int main(int argc, char ** argv)
{
  double h[]={10.0, 0.0};
  double vp[]={500.0, 2000.0};
  double vs[]={200.0, 500.0};
  double rho[]={2000.0, 2500.0};
  double frequency[]={0.2,
                      0.234420459506696, 
                      0.274764759176653,
                      0.322052405512188,
                      0.377478364427019,
                      0.44244325821409,
                      0.518588759480934,
                      0.60783907646264,
                      0.712449578052489,
                      0.83506378731208,
                      0.978780183695499,
                      1.14723050208974,
                      1.34467150729987,
                      1.57609256313398,
                      1.84734171437477,
                      2.16527346774811,
                      2.53792200633584,
                      2.97470421458702,
                      3.48665764439998,
                      4.08671943571388,
                      4.79005323997497,
                      5.61443240788236,
                      6.58068912462534,
                      7.71324084232695,
                      9.04070731272049,
                      10.5966338125674,
                      12.4203388378312,
                      14.5579076879663,
                      17.0633570483456,
                      20};
  double omega[30];
  double slowness[60];
  int nLayers=2;
  int nSamples=30;
  int nModes=2;
  int verbose=1;
  int group=0; // 1 to switch to group slowness
  int i;

  dispersion_curve_init_(&verbose);

  //
  // Computes fundamental and 1st higher mode for a 2-layer model
  //

  for(i=0; i<nSamples; i++) {
    omega[i]=2*M_PI*frequency[i];
  }

  //
  // Currently, the Fortran interface does not return if computation
  // was successful or not. If not, all slowness values are null.
  // This feature may evolve in the future.
  //

  dispersion_curve_rayleigh_(&nLayers, h, vp, vs, rho, &nSamples, omega, &nModes, slowness, &group);

  // Fondamental mode
  for(i=0; i<nSamples; i++) {
    if(slowness[i]>0.0) {
      printf("%lf %lf\n", frequency[i], 1.0/slowness[i]);
    }
  }

  // 1st higher mode, output only valid velocities
  for(i=0; i<nSamples; i++) {
    if(slowness[nSamples+i]>0.0) {
      printf("%lf %lf\n", frequency[i], 1.0/slowness[nSamples+i]);
    }
  }

  return 0;
}

