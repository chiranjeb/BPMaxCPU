
# Major Comment 1:
    My main concern is regarding how the computational problem is framed, its context (not so well) described, and the "accessibility" of the results from this paper to people who may want to use them (i.e. bioinformatics researchers wanting to evaluate RRI). For someone who does not know details about how RRI is computed, there is very little context given - it would be very helpful to try and explain what needs to be computed for RRI conceptually (this is currently too superficial), and how steps or structures in the dynamic programming formulation of the solution can be related to the original "physics problem". There is so little explanation of this currently, that the meaning of N and M are not defined, and when it comes to the performance evaluation section, the choice for actual values of N and M are unclear (why N>>M in particular, except for tests in section 5.1.1 where M=N - why? are the results still representative?). Finally, since the proposed algorithms and parameters to be optimized are highly involved, a domain scientist can't really be expected to understand these - yet they could greatly benefit from the results. Therefore it would greatly improve the accessibility of the results if some simple heuristics could be provided for picking these parameters for given input sizes, with the ability to refine them for more technically adept users.

    [CM, SR] Response to Major Comment 1: 
    1. Thank you for the comments on the background of RRI. We limited the discussion to the background since the literature is vast. We have referenced many relevant documents, expecting readers to dig into them if interested. We have focused on describing our work as much details as possible. 
    2. The meaning of M and N have been clarified on the first use (in the abstract). Also, added clarification in Section 
    3. There are various types of RNA sequences, such as small viral RNAs (svRNA: 18-25nt), Piwi-interacting RNAs (piRNA; 24-30 nt), Transfer RNA (80 nucleotides), Transfer RNA (80 nt), Ribosomal RNA (1800-5000nt), mRNA ( 1300-1400 nt), including other human Gnomes (upto 20K) which are of interest. Interaction between a smaller RNA such as svRNA and any human Gnome is a critical use case. So, we have restricted the larger sequence length to 3000-4000 nt to limit the runtime of the experiments. Our experiments show no performance degradation when the larger sequence is bigger than 3000 nt with the Mono-parametric tiling. 

# Major Comment 2:
    The authors dismiss the use of GPUs as having too little memory - modern HPC GPUs released in the past 5 years have actually more RAM as the CPU test systems in the paper... Nevertheless, I am not suggesting you should implement this for GPUs, but not having enough memory is not a great excuse.
    
    [CM, SR] Response to Major Comment 2: 
    We did not mean to dismiss the use of GPUs for too little memory. Reworded the last paragraph of the Section 2.1.
    We wanted to highlight some of the challenges the previous GPU optimizations faced. Memory requirements of RRI grow exponentially with larger sequences since the memory complexity is very O(N^4M^4). Yes, the latest GPUs can provide 100s of GBs, but some of the latest CPU-based systems with more than TB+ RAM are also exceedingly common. We observe that more memory with CPU is probably more common than GPU due to cost. and having a CPU implementation provides a larger problem instance to be run between cost-comparable CPUs and GPUs.

# Major Comment 3:
    In the performance analysis section, the effect of changing clock frequency (turbo) makes it particularly challenging to directly compare results, especially single-core and multi-core results, peak flops mismatch the theoretical ones, etc. I think it would be helpful to try and switch off turbo in the BIOS and make measurements that way. The authors demonstrate a very good fraction of peak compute on a single core, which is significantly reduced as one moves to multiple cores, but the reasons for this are not detailed or explored - please give some evidence of where the bottleneck shifts.
    
    [CM, SR] Response to Major Comment 3:
    We have re-run the experiments and do not see much difference between the ratio of GFLOPs (8 cores: 1 core) between turbo on and off. Experimental data can be found at (https://github.com/chiranjeb/BPMaxCPU/blob/master/TPDS/paper/version_2/latex/Accelerating%20RNA-RNA%20Interaction%20for%20Machine%20Peak/content/figures/gflops_ratio.png, https://github.com/chiranjeb/BPMaxCPU/blob/master/TPDS/paper/version_2/latex/Accelerating%20RNA-RNA%20Interaction%20for%20Machine%20Peak/content/figures/bpmax_single_core_turbo_on_off.png) We conclude that the reason we do not get linear scale up with multi-core is primarily due to two reasons: OMP thread scheduling overhead and reduction in available L3 cache when all the threads are active. 

# Major Comment 4:
    Only 256 bit vectors are considered - 512 bit vectors are conspicuously missing, even though Intel server chips have had those for 8 years now. At the least there should be a brief discussion of how that would affect parametrization.

    [CM, SR] Response to Major Comment 4:
    Thank you for bringing this up. We consider that the scope of 512-bit vectors is significantly large. It involves a new register tiling kernel along with parameter space exploration. We would like to consider this as a follow-up version and other improvements.


# Minor Comment 1:
    YMM registers are 256 bits wide not 32 as stated in the paper.
    
    [CM, SR] Response to Minor Comment 1:
    Thank you for catching this. Section 4.3, Third-level Tile Schedule, Second paragraph has been updated with correct Information.

# Minor Comment 2:
    Fig 13 is missing some data labels.
    
    [CM, SR] Response to Minor Comment 2:
    We wanted to avoid the clutter, but we see the inconsistencies. Updated the Figure to show only the last data point.

# Minor Comment 3:
    In section 5.1.1 you fix the register tile parameter and move on the explore second-level sizes - are these independent of each other?
    
    [CM, SR] Response to Minor Comment 3:
    Section 5.1.1. Clarified. With rerun, the register tiling benchmark. We fixed the first level tile size (N). But to explore the best register tile ( R_a, R_b), we presented the experimental results with different R_a, R_b, and the second level tile (N_tile) sizes.