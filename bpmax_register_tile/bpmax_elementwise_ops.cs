prog = ReadAlphabets("bpmax_elementwise_ops.ab");

rootSystem = "bpmax_elementwise_ops";
AShow(prog, rootSystem);
CheckProgram(prog);

outDir = "./src";

Normalize(prog); 
CheckProgram(prog);

AShow(prog, rootSystem);

use_FTable_C = "UseEquation_FTable_C";



setSpaceTimeMap(prog, rootSystem, "FTable_2D",    "(i, j    ->  0, i,  j, 0)");
setSpaceTimeMap(prog, rootSystem, use_FTable_C,  "( i, j    ->  1, i,  j, 0)");

                                                  
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, use_FTable_C, 0, 0, 
      											"(i, j -> -1,   -1,     -1,  -1 )",
      											"(i, j ->  1,    i,     -1,  -1 )",
      											"(i, j ->  M,   -1,     -1,  -1 )");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, use_FTable_C, 0, 0, "FTable_2D");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, use_FTable_C, 1, 0, 
      											"(i,j -> -1,    -1,     -1,   -1)",
      											"(i,j ->  1,     i,      j,  j-3)",
      											"(i,j ->  M+M,  -1,     -1,   -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, use_FTable_C, 1, 0, "FTable_4D");      

                                                                          

#setParallel(prog, rootSystem, "", "3");
generateScheduledCode(prog, rootSystem, outDir);

                             
                                             