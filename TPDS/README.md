# BPMax CPU Latest Version
    This repository contains the latest optimized CPU versions of the BPMax.

## Building the code
    Please go inside the source code folder specific to a version you are interested in and type the following commands
    make        : build "bpmax" program
    make clean  : clean all the build artifacts.


## Running the code
    After the code is built, you can execute "bpmax". There are many ways to invoke the program. 
    For quick measurement you can invoke the following command where M is the length of the first 
    sequence and N is the length of the second sequence. N_sec indicates the mono-parametric tile size
    for each inner trianglular table. R_a and R_b indicates register tile sizes. Typically, N_sec 
    should be divisible by R_b.
    
              Command : bpmax M N N_sec R_a R_b
              
      Example Command : bpmax 16 750 48 3 24
                        bpmax 32 2500 48 3 24
      
    The code randomly generates two sequences to compute the F-Table score.
    If you have sequences in a text file, then you may want to pass those directly to the program .
              command : ./bpmax sequence1.txt sequence2.txt N_sec R_a R_b
    sequence1 and sequence2 are the text file containing the neucleotide sequence A, U, G, C.


## Source code (./source/release/)
    BPMax Monoparametric Tile (MPT) + Register Tile (RT) + No on the fly data transformation ([MPT+RT]:v1): MPT_RT_V1/bpmax_complete_otf_none/src
    BPMax Monoparametric Tile (MPT) + Register Tile (RT) + On the fly data transformation FTable + S2 ([MPT+RT]:v2): MPT_RT_V2/bpmax_complete_otf_ftable_s2/src
    BPMax Monoparametric Tile (MPT) + Register Tile (RT) + On the fly data transformation FTable ([MPT+RT]:v3): MPT_RT_V3/bpmax_complete_otf_ftable/src
    BPMax Monoparametric Tile (MPT) : MPT/bpmax_no_register_tile
                                        
## Compilation scripts
    BPMax Monoparametric Tile (MPT) + Register Tile (RT) + No on the fly data transformation ([MPT+RT]:v1): MPT_RT_V1/bpmax_complete_otf_none/compilation_scripts
    BPMax Monoparametric Tile (MPT) + Register Tile (RT) + On the fly data transformation FTable + S2 ([MPT+RT]:v2): MPT_RT_V2/bpmax_complete_otf_ftable_s2/compilation_scripts
    BPMax Monoparametric Tile (MPT) + Register Tile (RT) + On the fly data transformation FTable ([MPT+RT]:v3): MPT_RT_V3/bpmax_complete_otf_ftable/compilation_scripts
            

 # AlphaZ resource
 AlphaZ resource can be found at https://www.cs.colostate.edu/AlphaZ/wiki/doku.php.
