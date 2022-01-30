prog = ReadAlphabets("bpmax_inner_reductions_finalize.ab");

system_bpmax_inner_reductions_finalize = "bpmax_inner_reductions_finalize";
system_bpmax_inner_reductions_diagonal_tile = "bpmax_inner_reductions_diagonal_tile";

CheckProgram(prog);
outDir = "./src";
PrintAST(prog, system_bpmax_inner_reductions_finalize);

NormalizeReduction(prog, system_bpmax_inner_reductions_finalize,      "FTable_C_section");
NormalizeReduction(prog, system_bpmax_inner_reductions_diagonal_tile, "FTable_C_section");
Normalize(prog);  

AShow(prog, system_bpmax_inner_reductions_finalize);
setMemoryMap(prog, system_bpmax_inner_reductions_finalize,    "NR_FTable_C_section",      "NR_FTable1",   "(i2,j2-> j2)");
setMemoryMap(prog, system_bpmax_inner_reductions_finalize,    "NR_FTable_C_section_1",    "NR_FTable2",   "(i2,j2-> j2)");
setMemoryMap(prog, system_bpmax_inner_reductions_finalize,    "FTable_C_pointwise_diag",  "FTable_C_section",   "(i2,j2-> i2, j2)");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_finalize, "FTable_C_pointwise_diag",  "(i,j   ->   -i,   0,  j,  j)");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_finalize, "NR_FTable_C_section",      "(i,j,k ->   -i,   1,  k,  j)", 
                                                      		                              "(i,j   ->   -i,   1, -1,  j)");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_finalize, "NR_FTable_C_section_1",    "(i,j,k ->   -i,   2,  k,  j)", 
                                                        	                              "(i,j   ->   -i,   2, -1,  j)");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_finalize, "FTable_C_section",         "(i,j   ->   -i,   2,  j,  j+1)");   
generateScheduledCode(prog, system_bpmax_inner_reductions_finalize, outDir);
generateMakefile(prog, system_bpmax_inner_reductions_finalize, outDir +"/mk_inner_reductions_finalize");




AShow(prog, system_bpmax_inner_reductions_diagonal_tile);
setSpaceTimeMap(prog, system_bpmax_inner_reductions_diagonal_tile, "NR_FTable_C_section",     "(i,j,k   ->   -i,    k,  j)", 
                                                      		                                  "(i,j     ->   -i,    j,    j)");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_diagonal_tile, "NR_FTable_C_section_1",   "(i,j,k   ->   -i,    k,    j)", 
                                                        	                                  "(i,j     ->   -i,    j,    j)");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_diagonal_tile, "FTable_C_section",        "(i,j     ->   -i,    j,  j+1)");   
generateScheduledCode(prog, system_bpmax_inner_reductions_diagonal_tile, outDir);
generateMakefile(prog, system_bpmax_inner_reductions_diagonal_tile, outDir + "/mk_inner_reductions_diagonal");

                             
                                             