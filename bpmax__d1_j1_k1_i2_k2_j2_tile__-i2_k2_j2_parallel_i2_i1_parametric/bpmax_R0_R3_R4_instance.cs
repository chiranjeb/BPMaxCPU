prog = ReadAlphabets("bpmax_R0_R3_R4_instance.ab");
subSystem = "bpmax_max_r0_r3_r4_instance";

Normalize(prog);  
AShow(prog, subSystem);
CheckProgram(prog);
#PrintAST(prog);

outDir = "./src";

r0_r3_r4_instance = "UseEquation_FTable_4D";


setSpaceTimeMap(prog, subSystem, r0_r3_r4_instance,   "(i, j   ->   -1,  i,  j,     0)");

                                                  
setSpaceTimeMapForUseEquationOptimization(prog, subSystem, r0_r3_r4_instance, 0, 0, 
      											          "(i1 -> -1,   -1,     -1,  -1)",
      											          "(i1 ->  1,    i1,    0,  -3)",
      											          "(i1 ->  M+M,  -1,     -1,  -1)");
setMemorySpaceForUseEquationOptimization(prog, subSystem, r0_r3_r4_instance, 0, 0, "FTable_6D");



setSpaceTimeMapForUseEquationOptimization(prog, subSystem, r0_r3_r4_instance, 1, 0, 
      											          "(i1 -> -1,   -1,     -1,  -1    )",
      											          "(i1->  1,    i1,      0,  -3    )",
      											          "(i1->  M+M,  -1,     -1,  -1    )");
setMemorySpaceForUseEquationOptimization(prog, subSystem, r0_r3_r4_instance, 1, 0, "FTable_4D");

                                                                          
generateScheduledCode(prog, subSystem, outDir);

                                       