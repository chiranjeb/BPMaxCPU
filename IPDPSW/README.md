# BPMax CPU Version 1
    This repository contains the first optimized CPU versions of the BPMax.

  '@INPROCEEDINGS{9460635,
  author={Mondal, Chiranjeb and Rajopadhye, Sanjay},
  booktitle={2021 IEEE International Parallel and Distributed Processing Symposium Workshops (IPDPSW)}, 
  title={Accelerating the BPMax Algorithm for RNA-RNA Interaction}, 
  year={2021},
  volume={},
  number={},
  pages={228-237},
  doi={10.1109/IPDPSW52791.2021.00042}}'

## Building the code
    Please go inside the source code folder specific to a version you are interested in and type the following commands
    make        : build "bpmax" program
    make clean  : clean all the build artifacts.

## Source Code (./source/*)
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
