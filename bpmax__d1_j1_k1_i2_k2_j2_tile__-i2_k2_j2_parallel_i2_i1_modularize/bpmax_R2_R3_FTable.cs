prog = ReadAlphabets("bpmax_R2_R3_FTable.ab");
subSystem = "bpmax_inner_reductions";

NormalizeReduction(prog, subSystem, "FTable_2D");
Normalize(prog);  
AShow(prog, subSystem);
AShow(prog, subSystem);
CheckProgram(prog);

outDir = "./src";
#setMemoryMap(prog, subSystem,   "NR_FTable", "NR_FTable1",    "(i1,j1,i2,j2->i1, j2)");
#setMemoryMap(prog, subSystem,   "NR_FTable_1", "NR_FTable2",  "(i1,j1i2,j2->i1, j2)");     

setSpaceTimeMap(prog, subSystem, "NR_FTable_2D",   "(i,j,k    ->  -i,    k,    j)", 
                                                   "(i,j      ->  -i,    i-1,  j)");                                                                           
setSpaceTimeMap(prog, subSystem, "NR_FTable_2D_1", "(i,j,k    ->  -i,    k,    j)", 
                                                   "(i,j      ->  -i,    i-1,  j)");                                                  
setSpaceTimeMap(prog, subSystem, "FTable_2D",      "(i,j      ->  -i,    j,    j)");  

  
 

#options = createTiledCGOptionForScheduledC();
#setDefaultDTilerConfiguration(prog, subSystem, 0, 2, "sequential");
generateScheduledCode(prog, subSystem, outDir);
                             
                                             