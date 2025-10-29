!
! Initialize global variables. If you share global variables between inversion runs and if
! runs can modify these global variables, you must be careful of correctly lock ressources.
! If you want to avoid such problems, make sure than common variables are written only during
! initialization or do not start more than one run at a time inside dinver.
        subroutine dinver_init_global()

        end

!
! Initialize parameters and eventually misfit computation
        subroutine dinver_init_run( forward )
!
! forward is a C pointer (use here as a reference)
! use it only as the first argument of dinver_* subroutines
!
! For 32bit platforms uncomment next line
!        integer        forward
! For 64bit platforms uncomment next line
        integer*2      forward

        call dinver_set_parameter_count( forward, 2 )
        call dinver_set_range( forward, 1, -5.0, 5.0, 0, 0)
        call dinver_set_range( forward, 2, -5.0, 5.0, 0, 0)
        call dinver_add_greater_than_condition( forward, 2, 1.0, 1, 2.0 )
        end

!
! This is the heart of the problem, enter here the forward and the misfit computation.
! You can set ok to false if the input model contains unconsistent information.
! By default it is set to true.
        subroutine dinver_forward( nd, model, ok, misfit )

        integer               nd
        real*4                model(nd)
        real*4                misfit
        logical               ok

        if (model(1)*model(1)+model(2)*model(2) >= 25.0) then
          ok = .false.
          return
        endif

        misfit = 22
        do i = 1, nd
          misfit=misfit+model(i)*model(i)-10*cos(2*3.14159265359*model(i))-1
        enddo

        end

