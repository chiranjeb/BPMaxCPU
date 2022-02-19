prog = ReadAlphabets("bpmax.ab");

rootSystem = "bpmax";

outDir = "./src";

Normalize(prog); 
CheckProgram(prog);

AShow(prog, rootSystem);


## PrintAST to figure out the label for the use equation that needs to be scheduled                                                 
PrintAST(prog, rootSystem);
equation_s1            = "UseEquation_S1";
equation_s2            = "UseEquation_S2_A";
equation_seq2_t        = "UseEquation_seq2_t";
initialize_FTable      = "UseEquation_FTable_C";
inner_reduction_label  = "UseEquation_FTable_A";
equation_FTable_output = "UseEquation_FTable";
outer_reduction_label  = "UseEquation_FTable_outer";


setSpaceTimeMap(prog, rootSystem, equation_s1,                "( i           ->  0,      0,   i,   0, 0)");
setSpaceTimeMap(prog, rootSystem, equation_seq2_t,            "( i           ->  0,      1,   i,   0, 0)");
setSpaceTimeMap(prog, rootSystem, equation_s2,                "( i           ->  0,      2,   i,   0, 0)");
setSpaceTimeMap(prog, rootSystem, initialize_FTable,          "( i, j        ->  2,    j-i,   i,   0, 1)");
setSpaceTimeMap(prog, rootSystem, outer_reduction_label,      "( i, j, k     ->  2,    j-i,   i,   k, 2)");
setSpaceTimeMap(prog, rootSystem, inner_reduction_label,      "( i, j        ->  2,    j-i,   M,   0, i)");
setSpaceTimeMap(prog, rootSystem, equation_FTable_output,     "( i, j        ->  3,      i,   j,   0, 0)");


################################   S1   #################################################
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
################################   Transformed seq2   #################################################
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



################################   S2  #################################################
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_s2, 0, 0, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_s2, 0, 0, "seq2_t");
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_s2, 1, 0, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_s2, 1, 0, "S2_A");
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_s2, 1, 1, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_s2, 1, 1, "S2_B");
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_s2, 1, 2, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_s2, 1, 2, "S2_C");


################################   Init  #################################################
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
setMemorySpaceForUseEquationOptimization(prog, rootSystem, initialize_FTable, 1, 0, "FTable_C");      


##################################### Outer Reductions ##################################

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 0, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 0, "seq1");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 1, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-6,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 1, "S1");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 2, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 2, "FTable_A");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 3, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 3, "FTable_B");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 4, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 0, 4, "FTable_C");


setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 1, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      0)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-3,    0)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, outer_reduction_label, 1, 0, "FTable_outer");




################################    FTable_final_reductions  ###########################
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 0, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 0, "seq2");    
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
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-6,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 3, "S2_C");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 4, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 0, 4, "FTable_C");


setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 1, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 1, 0, "FTable_A");
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 1, 1, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, inner_reduction_label, 1, 1, "FTable_B");

################################   Transform  output #################################################
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_FTable_output, 0, 0, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_FTable_output, 0, 0, "FTable_C");
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_FTable_output, 1, 0, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_FTable_output, 1, 0, "FTable");


CheckProgram(prog);
setParallel(prog, rootSystem, "", "4");
generateScheduledCode(prog, rootSystem, outDir);
#generateMakefile(prog, rootSystem, outDir);
#generateWrapper(prog, rootSystem, outDir);


                             
                                             