prog = ReadAlphabets("bpmax_R1_R2_FTable.ab");


#AShow(prog, subSystem);
CheckProgram(prog);

outDir = "./src";

inner_reduction_system = "bpmax_inner_reductions";
CheckProgram(prog);

outDir = "./src";

inner_diagonal_label   = "UseEquation_FTable_C_0";
r1_instance_label      = "UseEquation_FTable_C_1";
r2_instance_label      = "UseEquation_FTable_C_2";
inner_red_final_label  = "UseEquation_FTable_C_3";
FTable_r_tile_format_A = "UseEquation_FTable_A";
FTable_r_tile_format_B = "UseEquation_FTable_B";




setSpaceTimeMap(prog, inner_reduction_system,  inner_diagonal_label,    "(i, j     ->   -i,    j,  0,  j )");
setSpaceTimeMap(prog, inner_reduction_system,  r1_instance_label,       "(i, j, k  ->   -i,    k,  3,  j )");
setSpaceTimeMap(prog, inner_reduction_system,  r2_instance_label,       "(i, j, k  ->   -i,    k,  4,  j )");
setSpaceTimeMap(prog, inner_reduction_system,  inner_red_final_label,   "(i, j     ->   -i,    j,  0,  j )");
setSpaceTimeMap(prog, inner_reduction_system,  FTable_r_tile_format_B,  "(i, j     ->   -i,    j,  1,  j )");
setSpaceTimeMap(prog, inner_reduction_system,  FTable_r_tile_format_A,  "(i, j     ->   -i,    j,  2,  j )");



############################################### FTable_C_0 #################################################
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, inner_diagonal_label, 0, 0, 
      											"(i -> -1,   -1,     -1)",
      											"(i ->  1,    i,     -1)",
      											"(i ->  N,   -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, inner_diagonal_label, 0, 0, "seq2_t");
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, inner_diagonal_label, 0, 1, 
      											"(i1,j1 -> -1,   -1,    -1  )",
      											"(i1,j1 ->  1,  -i1,  j1-7  )",
      											"(i1,j1 ->  N,  -1,     -1  )");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, inner_diagonal_label, 0, 1, "S2_C");
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, inner_diagonal_label, 1, 0, 
      											"(i1,j1 -> -1,   -1,     -1 )",
      											"(i1,j1 ->  1,  -i1,   j1-6 )",
      											"(i1,j1 ->  N,   -1,     -1 )");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, inner_diagonal_label, 1, 0, "FTable_C_0");


############################################### max_plus(S2_A, FTable_B)  #################################################
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, r1_instance_label, 0, 0, 
      											"(i, j -> -1,   -1,     -1,  -1)",
      											"(i, j ->  1,    i,      j,   0)",
      											"(i, j ->  N,   -1,     -1,  -1)");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, r1_instance_label, 0, 0, "S2_A");

setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, r1_instance_label, 0, 1, 
      											"(i1,j1 -> -1,   -1,   -1)",
      											"(i1,j1 ->  1,  -i1,   j1-7)",
      											"(i1,j1 ->  N,   -1,   -1)");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, r1_instance_label, 0, 1, "FTable_B");


setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, r1_instance_label, 1, 0, 
      											"(i1,j1 -> -1,  -1,   -1    )",
      											"(i1,j1 ->  1, -i1,   j1-6  )",
      											"(i1,j1 ->  N,  -1,   -1    )");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, r1_instance_label, 1, 0, "FTable_C_1");


############################################### max_plus(FTable_B, S2_B)  #################################################
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, r1_instance_label, 0, 0, 
      											"(i1,j1 -> -1,  -1,     -1  )",
      											"(i1,j1 ->  1,  -i1,  j1-7  )",
      											"(i1,j1 ->  N,  -1,     -1  )");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, r2_instance_label, 0, 0, "FTable_A");
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, r2_instance_label, 0, 1, 
      											"(i, j -> -1,   -1,     -1)",
      											"(i, j ->  1,    i,      j)",
      											"(i, j ->  N,   -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, r2_instance_label, 0, 1, "S2_B");
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, r2_instance_label, 1, 0, 
      											"(i1,j1 -> -1,  -1,    -1  )",
      											"(i1,j1 ->  1, -i1,  j1-6  )",
      											"(i1,j1 ->  N,  -1,    -1  )");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, r2_instance_label, 1, 0, "FTable_C_2");
                                                             
                                                                  
################################## bpmax_inner_reductions_finalize  #################################################
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 0, 0, 
      											"(i -> -1,   -1,     -1 )",
      											"(i ->  1,    i,     -1)",
      											"(i ->  N,   -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 0, 0, "seq2_t");
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 0, 1, 
      											"(i, j -> -1,   -1,     -1)",
      											"(i, j ->  1,    i,      j)",
      											"(i, j ->  N,   -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 0, 1, "S2_C");
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 0, 2, 
      											"(i, j -> -1,   -1,     -1)",
      											"(i, j ->  1,    i,      j)",
      											"(i, j ->  N,   -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 0, 2, "FTable_C");
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 1, 0, 
      											"(i1,j1 -> -1,   -1,    -1   )",
      											"(i1,j1 ->  1,  -i1,  j1-6   )",
      											"(i1,j1 ->  N,  -1,     -1   )");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 1, 0, "FTable_C_3");
  
 
################################## Transform FTable_C --> FTable_A #################################################
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, FTable_r_tile_format_A, 0, 0, 
      											"(i -> -1,   -1,     -1 )",
      											"(i ->  1,    i,     -1 )",
      											"(i ->  N,   -1,     -1 )");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, FTable_r_tile_format_A, 0, 0, "FTable_C");
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, FTable_r_tile_format_A, 1, 0, 
      											"(i1,j1 -> -1,  -1,    -1   )",
      											"(i1,j1 ->  1, -i1,   j1-6  )",
      											"(i1,j1 ->  N,  -1,    -1   )");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, FTable_r_tile_format_A, 1, 0, "FTable_A");
  
################################## Transform FTable_C --> FTable_B #################################################
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, FTable_r_tile_format_B, 0, 0, 
      											"(i -> -1,   -1,     -1)",
      											"(i ->  1,    i,     -1)",
      											"(i ->  N,   -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, FTable_r_tile_format_B, 0, 0, "FTable_C");
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, FTable_r_tile_format_B, 1, 0, 
      											"(i1,j1 -> -1,   -1,    -1)",
      											"(i1,j1 ->  1,  -i1,    j1-6)",
      											"(i1,j1 ->  N,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, FTable_r_tile_format_B, 1, 0, "FTable_A");
 


generateScheduledCode(prog, inner_reduction_system, outDir);
generateMakefile(prog, inner_reduction_system, outDir+"/mk_r1_r2");

                             
                                             