        implicit none

        integer nLayers
        integer nSamples
        integer nModes
        integer i
        integer verbose
        integer group

        real*8 h(2)
        real*8 vp(2)
        real*8 vs(2)
        real*8 rho(2)
        real*8 frequency(30)
        real*8 omega(30)
        real*8 slowness(60)

        data frequency/0.2,
     &                 0.234420459506696, 
     &                 0.274764759176653,
     &                 0.322052405512188,
     &                 0.377478364427019,
     &                 0.44244325821409,
     &                 0.518588759480934,
     &                 0.60783907646264,
     &                 0.712449578052489,
     &                 0.83506378731208,
     &                 0.978780183695499,
     &                 1.14723050208974,
     &                 1.34467150729987,
     &                 1.57609256313398,
     &                 1.84734171437477,
     &                 2.16527346774811,
     &                 2.53792200633584,
     &                 2.97470421458702,
     &                 3.48665764439998,
     &                 4.08671943571388,
     &                 4.79005323997497,
     &                 5.61443240788236,
     &                 6.58068912462534,
     &                 7.71324084232695,
     &                 9.04070731272049,
     &                 10.5966338125674,
     &                 12.4203388378312,
     &                 14.5579076879663,
     &                 17.0633570483456,
     &                 20/
        data h/10.0,0.0/
        data vp/500.0,2000.0/
        data vs/200.0,500.0/
        data rho/2000.0,2500.0/
        data verbose/1/
c       1 to switch to group slowness 
        data group/0/

        call dispersion_curve_init(verbose)

c
c       Computes fundamental and 1st higher mode for a 2-layer model
c
        nLayers=2
        nSamples=30
        nModes=2

        do i=1,nSamples
          omega(i)=2*3.141592*frequency(i)
        end do

c       Currently, the Fortran interface does not return if computation
c       was successful or not. If not, all slowness values are null.
c       This feature may evolve in the future.
        call dispersion_curve_rayleigh(nLayers, h, vp, vs, rho,
     &                                 nSamples, omega,
     &                                 nModes, slowness, group)

c       Fundamental mode        
        do i=1,nSamples
          if(slowness(i).gt.0.0)then
            write(*,*)' ',frequency(i),'    ',1/slowness(i)
          end if
        end do

c       1st higher mode, output only valid velocities 
        do i=1,nSamples
          if(slowness(nSamples+i).gt.0.0)then
            write(*,*)' ',frequency(i),'    ',1/slowness(nSamples+i)
          end if
        end do
        
        end
