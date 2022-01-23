prog = ReadAlphabets("bpmax_r0_single.ab");
subSystem = "bpmax_max_r0_single";

Normalize(prog);  
AShow(prog, subSystem);
CheckProgram(prog);
#PrintAST(prog);

outDir = "./src";

r0_r3_r4_instance = "UseEquation_FTable_6D";


setSpaceTimeMap(prog, subSystem, r0_r3_r4_instance,   "(i, j                     ->   i,    j,     0,  0,   0, 0)");
setSpaceTimeMap(prog, subSystem, "FTable_6D",         "(i1, j1, i2, j2, i3, j3   ->   i1,  j1,     i2, j2, i3, j3)");
setSpaceTimeMap(prog, subSystem, "FTable_6D_3",         "(i1, j1, i2, j2, i3, j3   ->   i1,  j1,     i2, j2, i3, j3)");

setMemoryMap(prog, subSystem,   "FTable_6D_3", "FTable_6D_3",   "(i2,j2,i3,j3,i4,j4-> i2, j2, j3, i3, i4, j4)");
setMemoryMap(prog, subSystem,   "FTable_6D",   "FTable_6D",     "(i2,j2,i3,j3,i4,j4-> i2, j2, i3, j3, j4, i4)");


                                                  
setSpaceTimeMapForUseEquationOptimization(prog, subSystem, r0_r3_r4_instance, 0, 0, 
      											          "(i,j -> -1,   -1,     -1,  -1, 0, 0)",
      											          "(i,j ->  1,    i,    j,  -3, 0, 0)",
      											          "(i,j ->  M+M,  -1,     -1,  -1, 0, 0)");
setMemorySpaceForUseEquationOptimization(prog, subSystem, r0_r3_r4_instance, 0, 0, "FTable_6D_1");

setSpaceTimeMapForUseEquationOptimization(prog, subSystem, r0_r3_r4_instance, 0, 1, 
      											          "(i,j -> -1,   -1,     -1,  -1, 0, 0)",
      											          "(i,j ->  1,    i,    j,  -3, 0, 0)",
      											          "(i,j ->  M+M,  -1,     -1,  -1, 0, 0)");
setMemorySpaceForUseEquationOptimization(prog, subSystem, r0_r3_r4_instance, 0, 1, "FTable_6D_2");


setSpaceTimeMapForUseEquationOptimization(prog, subSystem, r0_r3_r4_instance, 1, 0, 
      											          "(i,j -> -1,   -1,     -1,  -1, 0, 0    )",
      											          "(i,j->  1,    i,      j,  -3, 0, 0    )",
      											          "(i,j->  M+M,  -1,     -1,  -1, 0, 0    )");
setMemorySpaceForUseEquationOptimization(prog, subSystem, r0_r3_r4_instance, 1, 0, "FTable_6D");

                                                                          
generateScheduledCode(prog, subSystem, outDir);
generateWrapper(prog, subSystem, outDir);

                                       