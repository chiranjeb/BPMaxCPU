prog = ReadAlphabets("bpmax_R0_R3_R4.ab");
outer_reduction_system = "bpmax_outer_reductions";

r0_r3_r4_instance_system = "bpmax_outer_reductions";

Normalize(prog);  
AShow(prog, r0_r3_r4_instance_system);
CheckProgram(prog);

outDir = "./src";
#PrintAST(prog, r0_r3_r4_instance_system);

r0_instance_label   = "UseEquation_FTable_C_I1_J1_0";
r3_instance_label   = "UseEquation_FTable_C_I1_J1_1";
r4_instance_label   = "UseEquation_FTable_C_I1_J1_2";


FTable_r_tile_format_A = "UseEquation_FTable_AA";
FTable_r_tile_format_B = "UseEquation_FTable_BB";



######################################################################################################################
###############################################     bpmax_r0_r3_r4            ########################################
setSpaceTimeMap(prog, r0_r3_r4_instance_system,  r3_instance_label,       "(i ,j         ->       0, i, j, 0, 0, 0)");
setSpaceTimeMap(prog, r0_r3_r4_instance_system,  r4_instance_label,       "(i ,j         ->       0, i, j, 0, 0, 0)");
setSpaceTimeMap(prog, r0_r3_r4_instance_system,  FTable_r_tile_format_A,  "(i, j         ->       0, i, j, 0, 0, 1)");
setSpaceTimeMap(prog, r0_r3_r4_instance_system,  FTable_r_tile_format_B,  "(i, j, k      ->       0, i, k, 1, j, 0)");
setSpaceTimeMap(prog, r0_r3_r4_instance_system,  r0_instance_label,       "(i ,j, k      ->       0, i, k, 1, j, 1)");


                                                  
setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, r0_instance_label, 0, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r0_instance_label, 0, 0, "FTable_A");
setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, r0_instance_label, 0, 1, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r0_instance_label, 0, 1, "FTable_B");
setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, r0_instance_label, 1, 0, 
      											          "(i1 -> -1,   -1,     -1,  -1    )",
      											          "(i1->  1,    i1,      0,  -3    )",
      											          "(i1->  M+M,  -1,     -1,  -1    )");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r0_instance_label, 1, 0, "FTable_C_I1_J1_0");





setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, r3_instance_label, 0, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r3_instance_label, 0, 0, "S1");
setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, r3_instance_label, 0, 1, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r3_instance_label, 0, 1, "FTable_C");
setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, r3_instance_label, 1, 0, 
      											          "(i1 -> -1,   -1,     -1,  -1    )",
      											          "(i1->  1,    i1,      0,  -3    )",
      											          "(i1->  M+M,  -1,     -1,  -1    )");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r3_instance_label, 1, 0, "FTable_C_I1_J1_1");



setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, r4_instance_label, 0, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r4_instance_label, 0, 0, "FTable_C");
setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, r4_instance_label, 0, 1, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r4_instance_label, 0, 1, "S1");
setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, r4_instance_label, 1, 0, 
      											          "(i1 -> -1,   -1,     -1,  -1    )",
      											          "(i1->  1,    i1,      0,  -3    )",
      											          "(i1->  M+M,  -1,     -1,  -1    )");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r4_instance_label, 1, 0, "FTable_C_I1_J1_2");







################################## Transform FTable_C --> FTable_A #################################################
setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, FTable_r_tile_format_A, 0, 0, 
      											"(i -> -1,   -1,     -1 )",
      											"(i ->  1,    i,     -1 )",
      											"(i ->  N,   -1,     -1 )");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, FTable_r_tile_format_A, 0, 0, "FTable_C");
setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, FTable_r_tile_format_A, 1, 0, 
      											"(i1,j1 -> -1,  -1,    -1   )",
      											"(i1,j1 ->  1, -i1,   j1-6  )",
      											"(i1,j1 ->  N,  -1,    -1   )");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, FTable_r_tile_format_A, 1, 0, "FTable_AA");
  
################################## Transform FTable_C --> FTable_B #################################################
setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, FTable_r_tile_format_B, 0, 0, 
      											"(i -> -1,   -1,     -1)",
      											"(i ->  1,    i,     -1)",
      											"(i ->  N,   -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, FTable_r_tile_format_B, 0, 0, "FTable_C");
setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, FTable_r_tile_format_B, 1, 0, 
      											"(i1,j1 -> -1,   -1,    -1)",
      											"(i1,j1 ->  1,  -i1,    j1-6)",
      											"(i1,j1 ->  N,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, FTable_r_tile_format_B, 1, 0, "FTable_BB");
                                          
setParallel(prog, r0_r3_r4_instance_system, "", "1");
generateScheduledCode(prog, r0_r3_r4_instance_system, outDir);

                                       