prog = ReadAlphabets("bpmax.ab");

rootSystem = "bpmax";
subSystemOuter  = "bpmax_outer_reductions";
subSystemInner  = "bpmax_inner_reductions";


AShow(prog, subSystemOuter);

outDir = "./src";

#NormalizeReduction(prog, rootSystem, "FTable");
Normalize(prog); 
CheckProgram(prog);

AShow(prog, rootSystem);


## PrintAST to figure out the label for the use equation that needs to be scheduled                                                 
PrintAST(prog, rootSystem);
equation_s1 = "UseEquation_S1";
equation_s2 = "UseEquation_S2";
#initialize_FTable = "UseEquation_FTable";
outer_reduction_label="UseEquation_FTable_outer_reductions";
inner_reduction_label="UseEquation_FTable_inner_reductions";


 
#setMemoryMap(prog, rootSystem,   "NR_FTable", "NR_FTable1",   "(i1,j1,i2,j2->i1, j2)");
#setMemoryMap(prog, rootSystem,   "NR_FTable_1", "NR_FTable2",   "(i1,j1,i2,j2->i1, j2)");                                        
                                                
#setSpaceTimeMap(prog, rootSystem, "S1",                       "(i,j               ->  0,    0,   j-i,   i,     0,      0,     0)");
#setSpaceTimeMap(prog, rootSystem, "S2",                       "(i,j               ->  0,    0,   j-i,   i,     0,      0,     0)");

setSpaceTimeMap(prog, rootSystem, equation_s1,                "( i                ->  i,    0,     0,     0,   0)");
setSpaceTimeMap(prog, rootSystem, equation_s2,                "( i                ->  i,    0,     0,     0,   0)");
#setSpaceTimeMap(prog, rootSystem, initialize_FTable,         "(i1,j1             ->  1, j1-i1,   i1,  j1-5,   0)");
setSpaceTimeMap(prog, rootSystem, outer_reduction_label,      "(i1,j1             ->  1, j1-i1,   i1,  0,   0)");
setSpaceTimeMap(prog, rootSystem, inner_reduction_label,      "(i1,j1             ->  1, j1-i1,   i1,  1,   0)");

setSpaceTimeMap(prog, rootSystem, "FTable",                   "(i1,j1,i2,j2       ->  -M, j1-i1,  i1 ,   i2,  j2)");

#setSpaceTimeMap(prog, rootSystem, "NR_FTable",   "(i1,j1,i2,j2,k2    ->  1, j1-i1,   M,   i1,    -i2,    k2,    j2)", 
#                                                 "(i1,j1,i2,j2       ->  1, j1-i1,   M,   i1,    -i2,    i2-1,  j2)");                                                                           
#setSpaceTimeMap(prog, rootSystem, "NR_FTable_1", "(i1,j1,i2,j2,k2    ->  1, j1-i1,   M,   i1,    -i2,    k2,    j2)", 
#                                                 "(i1,j1,i2,j2       ->  1, j1-i1,   M,   i1,    -i2,    i2-1,  j2)");                                                                           


################################ initialize_FTable  ##############################
#setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 0, 
#      											"(i -> -1,   -1,     -1,  -1, 0)",
#      											"(i ->  1,    i,     -1,  -1, 0)",
#      											"(i ->  M,   -1,     -1,  -1, 0)");
#setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 0, "seq1");

#setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 1, 
#      											"(i -> -1,   -1,     -1,  -1, 0)",
#      											"(i ->  1,    i,     -1,  -1, 0)",
#      											"(i ->  M,   -1,     -1,  -1, 0)");
#setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 1, "seq2");                             

#setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 2, 
#      											"(i -> -1,   -1,     -1,  -1, 0)",
#      											"(i ->  1,    i,     -1,  -1, 0)",
#      											"(i ->  M,   -1,     -1,  -1, 0)");
#setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 2, "S1");


#setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 3, 
#      											"(i -> -1,   -1,     -1,  -1, 0)",
#      											"(i ->  1,    i,     -1,  -1, 0)",
#      											"(i ->  M,   -1,     -1,  -1, 0)");
#setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 3, "S2");



#setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 1, 0, 
#      											"(i1,j1 -> -1,   -1,     -1,  -1,      0)",
#      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-3,    0)",
#      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     0)");
#setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 1, 0, "FTable");

                                             


################################     S1  ##############################
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_s1, 0, 0, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_s1, 0, 0, "seq1");                       
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_s1, 1, 0, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_s1, 1, 0, "S1");


################################   S2  ##############################
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_s2, 0, 0, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_s2, 0, 0, "seq2");
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_s2, 1, 0, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_s2, 1, 0, "S2");





################################     FTable_outer_reductions  ##############################
# Set space time map for the first input of the Use equation : FTable                                          
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 0, "FTable");
# Set space time map for the first output of the Use equation : S1                                          
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 1, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-6,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 1, "S1");
# Set space time map for the first output of the Use equation : FTable_outer_reductions                                          
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 1, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      0)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-3,    0)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 1, 0, "FTable_outer_reductions");




################################    FTable_final_reductions  ###########################
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 0, "FTable");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 1, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 1, "seq1");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 2, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 2, "seq2");


setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 3, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-6,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 3, "S1");

# Set space time map for the first input of the Use equation : S2                                         
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 4, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-6,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 4, "S2");


# Set space time map for the first output of the Use equation : FTable_final_reductions                                          
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 1, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      0)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-3,    0)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 1, 0, "FTable_inner_reductions");




CheckProgram(prog);
setParallel(prog, rootSystem, "", "3");
generateScheduledCode(prog, rootSystem, outDir);

                             
                                             