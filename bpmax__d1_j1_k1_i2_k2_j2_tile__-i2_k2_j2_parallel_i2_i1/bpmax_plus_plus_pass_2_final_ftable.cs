prog = ReadAlphabets("bpmax_plus_plus_final_ftable.ab");

rootSystem = "bpmax";
subSystem  = "bpmax_k1_reductions";

NormalizeReduction(prog, rootSystem, "FTable");
Normalize(prog);  
#AShow(prog, subSystem);
CheckProgram(prog);

outDir = "./plus_plus";
CheckProgram(prog);



## PrintAST to figure out the label for the use equation that needs to be scheduled                                                 
#PrintAST(prog, rootSystem);
label="UseEquation_FTable_outer_k1_k2";
 
setMemoryMap(prog, rootSystem,   "NR_FTable", "NR_FTable1",   "(i1,j1,i2,j2->i1, j2)");
setMemoryMap(prog, rootSystem,   "NR_FTable_1", "NR_FTable2",   "(i1,j1,i2,j2->i1, j2)");                                        
                                                
setSpaceTimeMap(prog, rootSystem, "S1",          "(i,j               ->  0, j-i,     i,   0,      0,       0,     0)");
setSpaceTimeMap(prog, rootSystem, "S2",          "(i,j               ->  0, j-i,     i,   0,      0,       0,     0)");
setSpaceTimeMap(prog, rootSystem, label,        "(i1,j1             ->  1, j1-i1,   j1,  j1-4,   0,       0,    0)");
setSpaceTimeMap(prog, rootSystem, "FTable",      "(i1,j1,i2,j2       ->  1, j1-i1,   M,  i1,    -i2,    j2,    0)");
setSpaceTimeMap(prog, rootSystem, "NR_FTable",   "(i1,j1,i2,j2,k2    ->  1, j1-i1,   M,  i1,    -i2,    k2,    j2)", 
                                                 "(i1,j1,i2,j2       ->  1, j1-i1,   M,  i1,    -i2,    i2-1,  j2)");                                                                           
setSpaceTimeMap(prog, rootSystem, "NR_FTable_1", "(i1,j1,i2,j2,k2    ->  1, j1-i1,   M,  i1,    -i2,    k2,    j2)", 
                                                 "(i1,j1,i2,j2       ->  1, j1-i1,   M,  i1,    -i2,    i2-1,  j2)");                                                                           
                                             
                                             
                                                 
## Set space time map for the first input of the Use equation : FTable                                          
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, label, 0, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1, -1, -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1, -1, -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1, -1, -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, label, 0, 0, "FTable");


setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, label, 0, 1, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1, -1, -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-6,    -1, -1, -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1, -1, -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, label, 0, 1, "S1");



# Set space time map for the first output of the Use equation : FTable_outer_k1_k2                                          
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, label, 1, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      0, 0, 0)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-3,    0, 0, 0)",
     											"(i1,j1 ->  M+M,  -1,     -1,  -1,     0, 0, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, label, 1, 0, "FTable_outer_k1_k2");



#CheckProgram(prog);
setParallel(prog, rootSystem, "", "3");
generateScheduledCode(prog, rootSystem, outDir);
#generateVerificationCode(prog, rootSystem, outDir);

                             
                                             