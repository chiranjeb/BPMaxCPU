prog = ReadAlphabets("bpmax.ab");

rootSystem = "bpmax";
subSystemOuter  = "bpmax_single_strand_s1" ;#"bpmax_outer_reductions";
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
equation_seq2_t = "UseEquation_seq2_t";
equation_s2_A = "UseEquation_S2_A";
equation_s2_B = "UseEquation_S2_B";
initialize_FTable = "UseEquation_FTable_C";
outer_reduction_label="UseEquation_FTable_outer";
inner_reduction_label="UseEquation_FTable";




#setMemoryMap(prog, rootSystem,   "NR_FTable", "NR_FTable1",   "(i1,j1,i2,j2->i1, j2)");
#setMemoryMap(prog, rootSystem,   "NR_FTable_1", "NR_FTable2",   "(i1,j1,i2,j2->i1, j2)");                                        
                                                
setSpaceTimeMap(prog, rootSystem, equation_s1,                "( i                ->  0,      i,   0,  0,     0)");
setSpaceTimeMap(prog, rootSystem, equation_s2,                "( i                ->  0,      i,   0,  0,     0)");
setSpaceTimeMap(prog, rootSystem, equation_seq2_t,            "( i                ->  0,      i,   0,  0,     0)");
setSpaceTimeMap(prog, rootSystem, equation_s2_A,              "( i, j             ->  0,      i,   j,  0,     0)");
setSpaceTimeMap(prog, rootSystem, equation_s2_B,              "( i, j             ->  0,      i,   j,  0,     0)");
setSpaceTimeMap(prog, rootSystem, initialize_FTable,          "( i, j             ->  1,      i,   j,  0,     0)");
setSpaceTimeMap(prog, rootSystem, outer_reduction_label,      "( i, j, k          ->  2,    j-i,   i,  k,     0)");
setSpaceTimeMap(prog, rootSystem, inner_reduction_label,      "( i, j             ->  2,    j-i,   M,  i,     1)");
#setSpaceTimeMap(prog, rootSystem, "FTable_A",                 "( i1, j1,i2,j2       -> -M,  j1-i1,  i1, i2,    j2)");
#setSpaceTimeMap(prog, rootSystem, "FTable_B",                 "( i1, j1,i2,j2       -> -M,  j1-i1,  i1, i2,    j2)");
                                                                          


                             



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


setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_s2_A, 0, 0, 
      											"(i, j -> -1,   -1,     -1,  -1, 0)",
      											"(i, j ->  1,    i,      j,  -1, 0)",
      											"(i, j ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_s2_A, 0, 0, "S2");
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_s2_A, 1, 0, 
      											"(i, j -> -1,   -1,     -1,  -1, 0)",
      											"(i, j ->  1,    i,      j,  -1, 0)",
      											"(i, j ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_s2_A, 1, 0, "S2_A");


setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_s2_B, 0, 0, 
      											"(i, j -> -1,   -1,     -1,  -1, 0)",
      											"(i, j ->  1,    i,      j,  -1, 0)",
      											"(i, j ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_s2_B, 0, 0, "S2");
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_s2_B, 1, 0, 
      											"(i, j -> -1,   -1,     -1,  -1, 0)",
      											"(i, j ->  1,    i,      j,  -1, 0)",
      											"(i, j ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_s2_B, 1, 0, "S2_B");




setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_seq2_t, 0, 0, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_seq2_t, 0, 0, "seq2");
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_seq2_t, 1, 0, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_seq2_t, 1, 0, "seq2_t");



################################ bpmax_elementwise_ops : FTable_C  ##############################
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
setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 0, 3, "S2");


setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, initialize_FTable, 1, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      0)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-3,    0)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 1, 0, "FTable_C");      



################################     FTable_outer  ##############################
# Set space time map for the first input of the Use equation : FTable                                          
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 0, "FTable_A");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 1, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 1, "FTable_B");

#setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 2, 
#      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
#      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
#      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
#setMemorySpaceForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 2, "FTable_C");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 2, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-6,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 2, "S1");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 1, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      0)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-3,    0)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 1, 0, "FTable_outer");




################################    FTable_final_reductions  ###########################

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 0, "FTable_C");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 1, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-6,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 1, "S2_A");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 2, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-6,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 2, "S2_B");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 3, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 3, "seq2");                             

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 1, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      0)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-3,    0)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 1, 0, "FTable");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 1, 1, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 1, 1, "FTable_A");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 1, 2, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 1, 2, "FTable_B");




CheckProgram(prog);
setParallel(prog, rootSystem, "", "3");
generateScheduledCode(prog, rootSystem, outDir);
#generateMakefile(prog, rootSystem, outDir);

                             
                                             