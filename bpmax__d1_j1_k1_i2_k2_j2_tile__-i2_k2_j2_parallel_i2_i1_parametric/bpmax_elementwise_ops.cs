prog = ReadAlphabets("bpmax_elementwise_ops.ab");

rootSystem = "bpmax_elementwise_ops";
AShow(prog, rootSystem);
CheckProgram(prog);

outDir = "./src";

Normalize(prog); 
CheckProgram(prog);

AShow(prog, rootSystem);

initialize_FTable = "UseEquation_FTable_4D";


#setSpaceTimeMap(prog, rootSystem, "FTable_4D",    "(i, j    -> i,  j)");
                                                  
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 0, 
      											"(i, j -> -1,   -1,     -1,  -1, 0)",
      											"(i, j ->  1,    i,     -1,  -1, 0)",
      											"(i, j ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 0, "seq1");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 1, 
      											"(i, j -> -1,   -1,     -1,  -1, 0)",
      											"(i, j ->  1,    i,     -1,  -1, 0)",
      											"(i, j ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 1, "seq2");                             

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 2, 
      											"(i, j -> -1,   -1,     -1,  -1, 0)",
      											"(i, j ->  1,    i,      j,  -1, 0)",
      											"(i, j ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 2, "S1");


setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 3, 
      											"(i1, j1 -> -1,   -1,     -1,  -1, 0)",
      											"(i1, j1->  1,    i1,     j1,  -1, 0)",
      											"(i1, j1->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 3, "S2");


setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 4, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      0)",
      											"(i1,j1 ->  1,    i1,    j1,  j1-3,    0)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 4, "FTable_6D");



setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 1, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      0)",
      											"(i1,j1->  1,    i1,      j1,  j1-3,    0)",
      											"(i1,j1->  M+M,  -1,     -1,  -1,     0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 1, 0, "FTable_4D");      

                                                                          

#setParallel(prog, rootSystem, "", "3");
generateScheduledCode(prog, rootSystem, outDir);

                             
                                             