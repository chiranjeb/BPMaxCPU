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
setSpaceTimeMap(prog, system_bpmax_inner_reductions_finalize, "NR_FTable_C_section",   "(i,j,k   ->   -i,    k,  j)", 
                                                      		                           "(i,j     ->   -i,    j,    j)");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_finalize, "NR_FTable_C_section_1", "(i,j,k   ->   -i,    k,    j)", 
                                                        	                           "(i,j     ->   -i,    j,    j)");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_finalize, "FTable_C_section",      "(i,j     ->   -i,    j,  j+1)");   
generateScheduledCode(prog, system_bpmax_inner_reductions_finalize, outDir);




AShow(prog, system_bpmax_inner_reductions_diagonal_tile);
setSpaceTimeMap(prog, system_bpmax_inner_reductions_diagonal_tile, "NR_FTable_C_section",     "(i,j,k   ->   -i,    k,  j)", 
                                                      		                                  "(i,j     ->   -i,    j,    j)");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_diagonal_tile, "NR_FTable_C_section_1",   "(i,j,k   ->   -i,    k,    j)", 
                                                        	                                  "(i,j     ->   -i,    j,    j)");
setSpaceTimeMap(prog, system_bpmax_inner_reductions_diagonal_tile, "FTable_C_section",        "(i,j     ->   -i,    j,  j+1)");   
generateScheduledCode(prog, system_bpmax_inner_reductions_diagonal_tile, outDir);

                             
                                             