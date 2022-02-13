prog = ReadAlphabets("bpmax_inner_triangle_point.ab");

system_bpmax_inner_reductions_finalize = "bpmax_inner_reductions_finalize";
system_bpmax_inner_reductions_diagonal_tile = "bpmax_inner_reductions_diagonal_tile";

CheckProgram(prog);
outDir = "./src";
#PrintAST(prog, system_bpmax_inner_reductions_finalize);

NormalizeReduction(prog, system_bpmax_inner_reductions_finalize,      "C_I2_J2");
NormalizeReduction(prog, system_bpmax_inner_reductions_diagonal_tile, "C_I2_J2");
Normalize(prog);  

AShow(prog, system_bpmax_inner_reductions_finalize);
setMemoryMap(prog, system_bpmax_inner_reductions_finalize,    "NR_C_I2_J2",        "NR_C_I2_J2",     "(i2,j2-> j2)");
setMemoryMap(prog, system_bpmax_inner_reductions_finalize,    "NR_C_I2_J2_3",      "NR_C_I2_J2_3",     "(i2,j2-> j2)");

#setMemoryMap(prog, system_bpmax_inner_reductions_finalize,    "NR_C_I2_J2_1",      "C_I2_J2",     "(i2,j2-> i2, j2)");
#setMemoryMap(prog, system_bpmax_inner_reductions_finalize,    "NR_C_I2_J2_2",      "C_I2_J2",     "(i2,j2-> i2, j2)");


setMemorySpace(prog, system_bpmax_inner_reductions_finalize,    "C_I2_J2", "C_pointwise_diag, NR_C_I2_J2_1, NR_C_I2_J2_2, C_I2_J2");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_finalize, "NR_C_I2_J2_1",      "(i,j,k ->   -2N_tile,    i,   k,  j)", 
                                                      		                       "(i,j   ->   -2N_tile,    i,  -1,  j)");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_finalize, "NR_C_I2_J2_2",      "(i,j,k ->   -2N_tile+1,  i,   k,  j)", 
                                                      		                       "(i,j   ->   -2N_tile+1,  i,   -1,  j)");

setSpaceTimeMap(prog, system_bpmax_inner_reductions_finalize, "C_pointwise_diag",  "(i,j   ->   -i,   0,  j,  j)");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_finalize, "NR_C_I2_J2",        "(i,j,k ->   -i,   1,  k,  j)", 
                                                      		                       "(i,j   ->   -i,   1, -1,  j)");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_finalize, "NR_C_I2_J2_3",      "(i,j,k ->   -i,   2,  k,  j)", 
                                                        	                       "(i,j   ->   -i,   2, -1,  j)");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_finalize, "C_I2_J2",           "(i,j   ->   -i,   3,  j,  j+1)");  



 
generateScheduledCode(prog, system_bpmax_inner_reductions_finalize, outDir);
generateMakefile(prog, system_bpmax_inner_reductions_finalize, outDir +"/mk_r1_r2_finalize");




AShow(prog, system_bpmax_inner_reductions_diagonal_tile);
setSpaceTimeMap(prog, system_bpmax_inner_reductions_diagonal_tile, "NR_C_I2_J2",     "(i,j,k   ->   -i,    k,    j)", 
                                                      		                         "(i,j     ->   -i,  i-1,    j)");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_diagonal_tile, "NR_C_I2_J2_1",   "(i,j,k   ->   -i,    k,    j)", 
                                                        	                         "(i,j     ->   -i,  i-1,    j)");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_diagonal_tile, "C_I2_J2",        "(i,j     ->   -i,    j,  j+1)");   
generateScheduledCode(prog, system_bpmax_inner_reductions_diagonal_tile, outDir);
generateMakefile(prog, system_bpmax_inner_reductions_diagonal_tile, outDir + "/mk_r1_r2_finalize");

                             
                                             