prog = ReadAlphabets("bpmax_R1_R2_FTable.ab");
inner_reduction_system = "bpmax_inner_reductions";

#AShow(prog, subSystem);
CheckProgram(prog);

outDir = "./src";

inner_diagonal_label = "UseEquation_FTable_C_section";
r1_instance_label = "UseEquation_FTable_C_section_r1";
r2_instance_label = "UseEquation_FTable_C_section_r2";
inner_red_final_label = "UseEquation_FTable_C_section_3";
FTable_r_tile_format_A = "UseEquation_FTable_A";
FTable_r_tile_format_B = "UseEquation_FTable_B";


CheckProgram(prog);

outDir = "./src";

setSpaceTimeMap(prog, inner_reduction_system,  inner_diagonal_label,    "(i, j     ->   N_sec-i,  j,     0 )");
setSpaceTimeMap(prog, inner_reduction_system,  r1_instance_label,       "(i, j     ->   N_sec-i,  j,     0 )");
setSpaceTimeMap(prog, inner_reduction_system,  r2_instance_label,       "(i, j     ->   N_sec-i,  j,     0 )");
setSpaceTimeMap(prog, inner_reduction_system,  inner_red_final_label,   "(i, j     ->   N_sec-i,  j,     1 )");
setSpaceTimeMap(prog, inner_reduction_system,  FTable_r_tile_format_A,  "(i, j     ->   N_sec-i,  j,     2 )");
setSpaceTimeMap(prog, inner_reduction_system,  FTable_r_tile_format_B,  "(i, j     ->   N_sec-i,  j,     3 )");


setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, inner_diagonal_label, 0, 0, 
      											"(i -> -1,   -1,     -1)",
      											"(i ->  1,    i,     -1)",
      											"(i ->  N,   -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, inner_diagonal_label, 0, 0, "seq2");

setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, inner_diagonal_label, 0, 1, 
      											"(i1,j1 -> -1,   -1,    -1  )",
      											"(i1,j1 ->  1,  -i1,  j1-7  )",
      											"(i1,j1 ->  N,  -1,     -1  )");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, inner_diagonal_label, 0, 1, "S2");


setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, inner_diagonal_label, 1, 0, 
      											"(i1,j1 -> -1,   -1,     -1 )",
      											"(i1,j1 ->  1,  -i1,   j1-6 )",
      											"(i1,j1 ->  N,   -1,     -1 )");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, inner_diagonal_label, 1, 0, "FTable_C_section");


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
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, r1_instance_label, 1, 0, "FTable_C_section_r1");



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
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, r2_instance_label, 1, 0, "FTable_C_section_r2");





setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 0, 0, 
      											"(i -> -1,   -1,     -1 )",
      											"(i ->  1,    i,     -1)",
      											"(i ->  N,   -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 0, 0, "seq2");
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 0, 1, 
      											"(i, j -> -1,   -1,     -1)",
      											"(i, j ->  1,    i,      j)",
      											"(i, j ->  N,   -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 0, 1, "S2_A");
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 0, 2, 
      											"(i, j -> -1,   -1,     -1)",
      											"(i, j ->  1,    i,      j)",
      											"(i, j ->  N,   -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 0, 2, "S2_B");
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 0, 3, 
      											"(i1,j1 -> -1,   -1,     0    )",
      											"(i1,j1 ->  1, -i1,     j1-7  )",
      											"(i1,j1 ->  N,  -1,     0     )");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 0, 3, "FTable_C");
setSpaceTimeMapForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 1, 0, 
      											"(i1,j1 -> -1,   -1,    -1   )",
      											"(i1,j1 ->  1,  -i1,  j1-6   )",
      											"(i1,j1 ->  N,  -1,     -1   )");
setMemorySpaceForUseEquationOptimization(prog, inner_reduction_system, inner_red_final_label, 1, 0, "FTable_C_section_3");
  
 
 
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
 

#options = createTiledCGOptionForScheduledC();
#setDefaultDTilerConfiguration(prog, subSystem, 0, 2, "sequential");
generateScheduledCode(prog, inner_reduction_system, outDir);
                             
                                             