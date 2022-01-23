prog = ReadAlphabets("bpmax_R0_R3_R4.ab");
subSystem = "bpmax_outer_reductions";

Normalize(prog);  
#AShow(prog, subSystem);
CheckProgram(prog);

outDir = "./src";

r0_r3_r4_FTable = "UseEquation_FTable_4D_dummy";


setSpaceTimeMap(prog, subSystem, r0_r3_r4_FTable,   "(i                 ->   -1,  i,  0,     0)");
setSpaceTimeMap(prog, subSystem, "FTable_4D",       "(i1, j1, i2, j2    ->   i1, j1,  i2, j2)");

                                                  
setSpaceTimeMapForUseEquationOptimization(prog, subSystem, r0_r3_r4_FTable, 0, 0, 
      											          "(i -> -1,   -1,     -1,  -1)",
      											          "(i ->  1,    i,      0,  -1)",
      											          "(i->  M,   -1,     -1,  -1)");
setMemorySpaceForUseEquationOptimization(prog, subSystem, r0_r3_r4_FTable, 0, 0, "S1");


setSpaceTimeMapForUseEquationOptimization(prog, subSystem, r0_r3_r4_FTable, 0, 1, 
      											          "(i1 -> -1,   -1,     -1,  -1)",
      											          "(i1 ->  1,    i1,    0,  -3)",
      											          "(i1 ->  M+M,  -1,     -1,  -1)");
setMemorySpaceForUseEquationOptimization(prog, subSystem, r0_r3_r4_FTable, 0, 1, "FTable_6D");



setSpaceTimeMapForUseEquationOptimization(prog, subSystem, r0_r3_r4_FTable, 1, 0, 
      											          "(i1 -> -1,   -1,     -1,  -1    )",
      											          "(i1->  1,    i1,      0,  -3    )",
      											          "(i1->  M+M,  -1,     -1,  -1    )");
setMemorySpaceForUseEquationOptimization(prog, subSystem, r0_r3_r4_FTable, 1, 0, "FTable_4D_dummy");

                                                                          
generateScheduledCode(prog, subSystem, outDir);

                                       