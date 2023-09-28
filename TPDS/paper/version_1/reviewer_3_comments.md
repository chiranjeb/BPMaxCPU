
# Major Comment 1:
    > The Broadwell platform used in testing had half the DRAM of the Coffee Lake platform, which was noted in Section 5.2.1 to be a limiting factor for performance.  Broadwell is not, to my knowledge, limited to only 16 GB of total DRAM; why not test with at least as much DRAM as the other platform to avoid differences that are not down to the chipset itself?  More broadly, the DRAM limitations arise from the size of the DP tables, which in turn comes from the input sequence sizes.  What is the justification for the sizes used?  If the goal is to model RNA interference, mature siRNAs are typically under 25 bases, rather than the 32 tested here.
[CM, SR] Response to Major Comment 1: 
    There are various types of RNA sequences, such as small viral RNAs (svRNA: 18-25nt), Piwi-interacting RNAs (piRNA; 24-30 nt), Transfer RNA (80 nucleotides), Transfer RNA (80 nt), Ribosomal RNA (1800-5000nt), mRNA ( 1300-1400 nt), including other human Gnomes (upto 20K) which are of interest. Interaction between a smaller RNA such as svRNA and any human Gnome is a critical use case. So, we have restricted the larger sequence length to 3000-4000 nt to limit the runtime of the experiments. Our experiments show no performance degradation when the larger sequence is bigger than 3000 nt with the Mono-parametric tiling. 

# Major Comment 2:
    In Section 5.1.1, the best performance was observed for the lowest second-level tile size tested (48).  Is there a reason not to test even lower tile sizes to verify that 48 is indeed a minimum value?  Also in this section, the authors fix the 3rd-level tile size, then test a variety of 2nd-level tile sizes.   On the other hand, Figure 12 tests different 3rd-level tile sizes for a fixed (much larger) 2nd-level size.  Why not test the cross product of 2nd- and 3rd-level tile sizes to identify joint parameters with overall best performance?
[CM, SR] Response to Major Comment 2: 
    We have re-run the register tiling benchmark. We fixed the first level tile size (N). We presented the experimental results with different values of R_a, R_b and the second level tile (N_tile) to explore the best register tile ( R_a, R_b) size.

# Major Comment 3:
     Section 5.3.2 states that a tile size of 192 works best over all inputs, but that it is too short for effective vectorization and so does not outperform prior work. I assume the intent is to contrast performance against the authors' hand-rolled vectorized kernels, but what prevents using a larger tile size for just plain [MPT] to enable better auto-vectorization?
[CM, SR] Response to Major Comment 3:
    "The problem with using a larger tile size for MPT would result in short and fat Loop-tiling which prevents effective cache utilization. The reason we showed the just MPT version is to contrast that MPT alone can't give the best performance without register tiling.


# Major Comment 4:
    The authors test three different versions of their hand-coded 3rd-level tiled code, labeled v1, v2, and v3.  The paper does not explain how these versions differ in implementation, and I did not see any supplementary file with such an explanation.  The authors should briefly summarize the differences among the three versions and then provide details in the supplementary text.
[CM, SR] Response to Major Comment 4:
    We had this under the Buffer Transformation Strategy Paragraph. We made a new section (3.4.3) to make it more obvious. Also, added the long with other improvements.



# Minor Comment 1:
    YMM registers are 256 bits wide not 32 as stated in the paper.
[CM, SR] Response to Minor Comment 1:
    Thank you for catching this. Section 4.3 , Third-level Tile Schedule, Second paragraph has been updated with correct Information.

# Minor Comment 2:
    The computation of the S_ij terms is never actually described.  I assume these are optimal single-stranded structures computed in a Nussinov-like fashion, but this should be made explicit, even if only in supplementary text. The figure that accompanied Equations 1-3 in the conference paper might also be profitably be used here to provide intuition for what the different terms of the BPMax recurrence are computing.
[CM, SR] Response to Minor Comment 2:
    We added a clarification indicating that S_ij is indeed a Nussionov-like term.

# Minor Comment 3:
    The double subscript notation in 3.4.1 (e.g., i_22) is never explained and is never used anywhere else that I noticed.  In the same paragraph, a tile is indexed as (i_{2+1}, j_2) -- is the former index supposed to be i_2 + 1?
[CM, SR] Response to Minor Comment 3:
    Added the equational definition of i_22. Regrading i_{2+1}, thank you so much, It is a great catch. Corrected.