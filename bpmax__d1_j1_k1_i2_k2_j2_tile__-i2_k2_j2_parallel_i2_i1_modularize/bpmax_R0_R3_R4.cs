prog = ReadAlphabets("bpmax_R0_R3_R4.ab");
subSystem = "bpmax_outer_reductions";

NormalizeReduction(prog, subSystem, "FTable_2D");
Normalize(prog);  
AShow(prog, subSystem);
AShow(prog, subSystem);
CheckProgram(prog);

outDir = "./src";
setMemorySpace(prog, subSystem, "FTable_2D", "NR_FTable_2D, NR_FTable_2D_1, NR_FTable_2D_2");
setSpaceTimeMap(prog, subSystem, "NR_FTable_2D",     "(i,j,k1,k2 ->  k1,    i,       k2,    j)", 
                                                    "(i,j      ->  -1,     i,       0,     j)");
setSpaceTimeMap(prog, subSystem, "NR_FTable_2D_1",  "(i,j,k1   ->   k1,    i,       i,     j)", 
                                                    "(i,j      ->  -1,     i,       0,     j)");                                                 
setSpaceTimeMap(prog, subSystem, "NR_FTable_2D_2",  "(i,j,k1   ->   k1,    i,       i,     j)", 
                                                    "(i,j      ->  -1,     i,       0,     j)");    
setSpaceTimeMap(prog, subSystem, "FTable_2D",        "(i,j      ->   M,     i,       j,     0)");   

options = createTiledCGOptionForScheduledC();
setDefaultDTilerConfiguration(prog, subSystem, 1, 3, "sequential");
generateScheduledCode(prog, subSystem, options, outDir);                                       