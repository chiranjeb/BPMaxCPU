prog = ReadAlphabets("bpmax_single_strand_point.ab");
outDir = "./src";

CheckProgram(prog);

system_bpmax_single_strand_diagonal_tile  = "bpmax_single_strand_diagonal_tile";
system_bpmax_single_strand_finalize = "bpmax_single_strand_finalize";

CheckProgram(prog);
outDir = "./src";
#PrintAST(prog, system_bpmax_single_strand_finalize);

NormalizeReduction(prog, system_bpmax_single_strand_finalize,      "S_C_I2_J2");
NormalizeReduction(prog, system_bpmax_single_strand_diagonal_tile, "S_C_I2_J2");
Normalize(prog);  

AShow(prog, system_bpmax_single_strand_finalize);


setMemoryMap(prog, system_bpmax_single_strand_finalize,    "NR_S_C_I2_J2",             "NR_S_C_I2_J2_1",   "(i2,j2-> j2)");
setMemoryMap(prog, system_bpmax_single_strand_finalize,    "NR_S_C_I2_J2_1",           "NR_S_C_I2_J2_2",   "(i2,j2-> j2)");
setMemoryMap(prog, system_bpmax_single_strand_finalize,    "S_C_pointwise_diag",       "S_C_I2_J2",   "(i2,j2-> i2, j2)");

setSpaceTimeMap(prog, system_bpmax_single_strand_finalize, "S_C_pointwise_diag",       "(i,j   ->   -i,   0,  j,  j)");
setSpaceTimeMap(prog, system_bpmax_single_strand_finalize, "NR_S_C_I2_J2",             "(i,j,k ->   -i,   1,  k,  j)", 
                                                      		                           "(i,j   ->   -i,   1, -1,  j)");
setSpaceTimeMap(prog, system_bpmax_single_strand_finalize, "NR_S_C_I2_J2_1",           "(i,j,k ->   -i,   2,  k,  j)", 
                                                      		                           "(i,j   ->   -i,   2, -1,  j)");
setSpaceTimeMap(prog, system_bpmax_single_strand_finalize, "S_C_I2_J2",                "(i,j   ->   -i,   3,  j,  j+1)");   
generateScheduledCode(prog, system_bpmax_single_strand_finalize, outDir);
generateMakefile(prog, system_bpmax_single_strand_finalize, outDir +"/mk_single_strand_finalize");




AShow(prog, system_bpmax_single_strand_diagonal_tile);
setSpaceTimeMap(prog, system_bpmax_single_strand_diagonal_tile, "NR_S_C_I2_J2",     "(i,j,k   ->   -i,    k,    j)", 
                                                      		                        "(i,j     ->   -i,  i-1,    j)");
setSpaceTimeMap(prog, system_bpmax_single_strand_diagonal_tile, "S_C_I2_J2",        "(i,j     ->   -i,    j,  j+1)");   
generateScheduledCode(prog, system_bpmax_single_strand_diagonal_tile, outDir);
generateMakefile(prog, system_bpmax_single_strand_diagonal_tile, outDir + "/mk_single_strand_diagonal");
                                  