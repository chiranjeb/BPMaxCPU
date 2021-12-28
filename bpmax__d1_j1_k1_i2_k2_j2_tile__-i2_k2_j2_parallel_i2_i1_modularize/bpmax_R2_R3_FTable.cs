prog = ReadAlphabets("bpmax_R2_R3_FTable.ab");
subSystem = "bpmax_inner_reductions";

NormalizeReduction(prog, subSystem, "_FTable");
Normalize(prog);  
AShow(prog, subSystem);
AShow(prog, subSystem);
CheckProgram(prog);

outDir = "./src";
#setMemoryMap(prog, subSystem,   "NR_FTable", "NR_FTable1",    "(i1,j1,i2,j2->i1, j2)");
#setMemoryMap(prog, subSystem,   "NR_FTable_1", "NR_FTable2",  "(i1,j1i2,j2->i1, j2)");     

setSpaceTimeMap(prog, subSystem, "NR__FTable",   "(i,j,k    ->  1, -i,    k,    j)", 
                                                 "(i,j      ->  1, -i,    i-1,  j)");                                                                           
setSpaceTimeMap(prog, subSystem, "NR__FTable_1", "(i,j,k    ->  1, -i,    k,    j)", 
                                                 "(i,j      ->  1, -i,    i-1,  j)");                                                  
setSpaceTimeMap(prog, subSystem, "_FTable",      "(i,j      ->  1, -i,    j,    0)");  

  
 

#options = createTiledCGOptionForScheduledC();
#setDefaultDTilerConfiguration(prog, subSystem, 3, 3, "sequential");
generateScheduledCode(prog, subSystem, outDir);
                             
                                             