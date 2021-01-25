prog = ReadAlphabets("bpmax_k1_k2_reductions.ab");
subSystem = "bpmax_k1_k2_reductions";

NormalizeReduction(prog, subSystem, "_FTable");
Normalize(prog);  
AShow(prog, subSystem);
CheckProgram(prog);

outDir = "./src";
setMemorySpace(prog, subSystem, "_FTable", "NR__FTable, NR__FTable_1, NR__FTable_2, _FTable");
setSpaceTimeMap(prog, subSystem, "NR__FTable",      "(i,j,k1,k2 ->  k1,    i,       k2,    j)", 
                                                    "(i,j      ->  -1,     i,       0,     j)");
setSpaceTimeMap(prog, subSystem, "NR__FTable_1",    "(i,j,k1   ->   k1,    i,       i,     j)", 
                                                    "(i,j      ->  -1,     i,       0,     j)");                                                 
setSpaceTimeMap(prog, subSystem, "NR__FTable_2",    "(i,j,k1   ->   k1,    i,       i,     j)", 
                                                    "(i,j      ->  -1,     i,       0,     j)");    
setSpaceTimeMap(prog, subSystem, "_FTable",         "(i,j      ->   M,     i,       j,     0)");   

#options = createTiledCGOptionForScheduledC();
#setDefaultDTilerConfiguration(prog, subSystem, 1, 3, "sequential");
#generateScheduledCode(prog, subSystem, options, outDir);
generateScheduledCode(prog, subSystem, outDir);
                             
                                             