# BPMax CPU Latest Version

This repository contains two different optimized CPU version of the BPMax.

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


## Source Code
    BPMax Monoparametric Tile (MPT) +  Register Tile (RT) schedule (Tiled) + On the fly data transformation ([MPT+RT]:v3):
                                        bpmax_register_tile/bpmax_complete_otf_transform_all/src
    

#Previous Version

## Running the code
    After the code is built, you can execute "bpmax". There are many ways to invoke the program. 
    For quick measurement you can invoke the following command where M is the length of the first 
    sequence and N is the length of the second sequence. 
              command : bpmax M N 32 4 N
    The code randomly generates two sequences to compute the F-Table score.
    If you have sequences in a text file, then you may want to pass those directly to the program .
              command : ./bpmax sequence1.txt sequence2.txt 32 4 N
    sequence1 and sequence2 are the text file containing the neucleotide sequence A, U, G, C.


## Source Code
    BPMax Hybrid schedule (Tiled)   :   bpmax__d1_j1_k1_i2_k2_j2_tile__-i2_k2_j2_parallel_i2_i1/src 
    BPMax Hybrid schedule           :   bpmax__d1_j1_k1_i2_k2_j2__-i2_k2_j2_parallel_i2_i1/src 
    BPMax Fine-grain                :   bpmax__-i1_j1_k1_-i2_k2_j2__-i2_k2_j2_parallel_-i2/src
    BPMax Coarse-grain              :   bpmax__d1_i1_k1_i2_k2_j2__-i2_k2_j2_parallel_i1/src 
    Double Max-plus                 :   R0

## Compilation script
### BPMax Hybrid schedule(Tiled) :
    Subsystem  :   bpmax__d1_j1_k1_i2_k2_j2_tile__-i2_k2_j2_parallel_i2_i1/bpmax_k1_k2_reductions.ab
                   bpmax__d1_j1_k1_i2_k2_j2_tile__-i2_k2_j2_parallel_i2_i1/bpmax_pass_1_k1_k2_reductions.cs
    Root System:   bpmax__d1_j1_k1_i2_k2_j2_tile__-i2_k2_j2_parallel_i2_i1/bpmax_final_ftable.ab
                   bpmax__d1_j1_k1_i2_k2_j2_tile__-i2_k2_j2_parallel_i2_i1/bpmax_pass_2_final_ftable.cs
   
### BPMax Hybrid schedule : 
       bpmax__d1_j1_k1_i2_k2_j2__-i2_k2_j2_parallel_i2_i1/bpmax_float.ab
       bpmax__d1_j1_k1_i2_k2_j2__-i2_k2_j2_parallel_i2_i1/bpmax__d1_j1_k1_i2_k2_j2__-i2_k2_j2_parallel_i2_i1.cs
    
###  BPMax Fine-grain:
       bpmax__-i1_j1_k1_-i2_k2_j2__-i2_k2_j2_parallel_-i2/bpmax_float.ab
       bpmax__-i1_j1_k1_-i2_k2_j2__-i2_k2_j2_parallel_-i2/bpmax__-i1_j1_k1_-i2_k2_j2__-i2_k2_j2_parallel_-i2.cs
   
###  BPMax Coarse-grain :
       bpmax__d1_i1_k1_i2_k2_j2__-i2_k2_j2_parallel_i1/bpmax_float.ab
       bpmax__d1_i1_k1_i2_k2_j2__-i2_k2_j2_parallel_i1/bpmax__d1_i1_k1_i2_k2_j2__-i2_k2_j2_parallel_i1.cs
       

## AlphaZ resource
 AlphaZ resource can be found at https://www.cs.colostate.edu/AlphaZ/wiki/doku.php.
