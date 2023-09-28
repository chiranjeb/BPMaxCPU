prog = ReadAlphabets("bpmax_ftable_init.ab");

rootSystem = "bpmax_init";
AShow(prog, rootSystem);
CheckProgram(prog);

outDir = "./src";

Normalize(prog); 
CheckProgram(prog);

AShow(prog, rootSystem);
initialize_FTable      = "UseEquation_FTable_C_I1_J1";



setSpaceTimeMap(prog, rootSystem, initialize_FTable,         "(i, j   ->   0, i,   j)");

#setSpaceTimeMap(prog, rootSystem, "FTable_C_I1_J1_I2_J2",    "(i, j    ->  0, i,  j, 0)");
setSpaceTimeMap(prog, rootSystem, initialize_FTable,         "(i, j   ->   0, i,   j)");

#setSpaceTimeMap(prog, rootSystem, initialize_FTable,    "(i, j    ->  0, i,  j, 0)");




setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 0, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 0, "seq1");
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 1, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 1, "seq2_t");                             
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 2, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 2, "S1");


setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 3, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 3, "S2_C");
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 1, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      0)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-3,    0)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 1, 0, "FTable_C_I1_J1");      


setMemorySpace(prog,  "bpmax_ftable_init", "FTable_C_I1_J1_I2_J2", "FTable_C_I1_J1_I2_J2_l, FTable_C_I1_J1_I2_J2");
#setSpaceTimeMap(prog, "bpmax_ftable_init", "FTable_C_I1_J1_I2_J2",    "(i, j    ->  1, i, j)");
setSpaceTimeMap(prog, "bpmax_ftable_init", "FTable_C_I1_J1_I2_J2_l",  "(i, j    ->  i, j)");


setParallel(prog, rootSystem, "", "0");
generateScheduledCode(prog, rootSystem, outDir);

                             
                                             