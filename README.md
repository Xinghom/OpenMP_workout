# OpenMP on Cori

- # Intro

    This repo is created for practicing parallel processing by OpenMP on Cori SuperComputer.


- # Specific small projects details

    - **pi_calculator**
        
        > How to compile on Cori
        cc -std=c++11 -qopenmp [source.cpp] -o pi

        > We can simply run the program via "./pi" \
          But I want to let it run on computer node through slurm script.

        > So, you can check my .slurm in the folder \
          After finishing slurm, just use command below, then it would be in the job queue on Cori
        ```
        sbatch run.slurm
        ```

        - Strong and Weak Scaling Study (1 node - 64 cores)
            > Firstly, Let's see the results: \
              Runs on **1** computation node \
                 with **64** cores 

                Threads Num: 1
                3.14159
                Milliseconds since start: 2139
                Threads Num: 2
                3.14159
                Milliseconds since start: 1083
                Threads Num: 4
                3.14159
                Milliseconds since start: 588
                Threads Num: 8
                3.14159
                Milliseconds since start: 331
                Threads Num: 16
                3.14159
                Milliseconds since start: 236
                Threads Num: 32
                3.14159
                Milliseconds since start: 191
                Threads Num: 64
                3.14159
                Milliseconds since start: 120
                Threads Num: 128
                3.14159
                Milliseconds since start: 154
                Threads Num: 256
                3.14159
                Milliseconds since start: 202
                Threads Num: 512
                3.14159
                Milliseconds since start: 217


                threads	time	Strong Scaling	Weak Scale
                1	        2139	1	            1
                2	        1083	0.987534626	    1.975069252
                4	        588	 0.9094387755	3.637755102
                8	        331	 0.8077794562	6.46223565
                16	        236	 0.5664724576	9.063559322
                32	        191	 0.3499672775	11.19895288
                64	        120	 0.278515625	    17.825
                128	        154	 0.1085125812	13.88961039
                256	        202	 0.04136370668	10.58910891
                512	        217	 0.01925223214	9.857142857

            - Strong Scaling Study (1 node - 64 cores)
                
                > The strong scaling efficiency (as a percentage of linear) is given as: \
                    S = t1 / ( N * tN ) * 100% \
                   (t1 is sequential code time; N is the number of computation elements; tN is the time for processing with N elements.)
                
                ![Strong Scaling Study](/pi_calculator/pi_Strong.png)

            - Weak Scaling Study (1 node - 64 cores)

                > The weak scaling efficiency (as a percentage of linear) is given as: \
                    W = ( t1 / tN ) * 100%

                ![Weak Scaling Study](/pi_calculator/pi_Weak.png)
            
            


    - **matrix_multiplication**
        
        It would randomly generate a large 1600x1600 matrix, then square it.
        
        > 2 version for this: 
             >> 1. Parallel in outer loop 
             >> 2. Parallel in inner loop
        
        - Strong Scaling Study:

        ![Mat Strong Scaling Study](/matrix_multiplication/mat_sqr_strongS.png)

        - **Outer version VS Inner version**

        ```
        Threads	time(ms)	Outer Version Strong Scaling efficient
        1	1546	    1
        2	766	    1.009138381
        4	400	    0.96625
        8	233	    0.8293991416
        16	150	    0.6441666667
        32	109	    0.443233945
        64	103	    0.234526699
        128	163	    0.07409892638

        Threads	time(ms)	Inner Version Strong Scaling efficient
        1	32385	    1
        2	7830	    2.068007663
        4	6791	    1.192202916
        8	7985	    0.5069661866
        16	9718	    0.2082797386
        32	15355	    0.06590890589
        64	19157	    0.02641413713
        128	90842	    0.002785141372
        ``` 

        > Obviously, outer loop version is much faster than inner version for the same number of computing threads. \
          Outer loop version can be more efficiently accelerated.


- # Note:
    ```
    Problems: 

    1. adding { , cannot be directly added follow the line "#pragam"   - Fixed

    2. build-in arry datatype cannot handle large 2-D array -> segmentation fault - Fixed

    3. operater* overload for smart usage - Fixed
    ```