prog = ReadAlphabets("bpmax_single_strand_tile.ab");
outDir = "./src";

Normalize(prog); 
CheckProgram(prog);

bpmax_single_strand_system = "bpmax_single_strand_s2_tile";
Normalize(prog);  
CheckProgram(prog);
outDir = "./src";
#PrintAST(prog, system_bpmax_single_strand_finalize);

AShow(prog, bpmax_single_strand_system);

s_reduction_diagonal_label = "UseEquation_S_C_1";
mm_max_plus_instance_label = "UseEquation_S_C_2";
s_reduction_final_label = "UseEquation_S_C_3";
s_tile_format_A = "UseEquation_S_A";
s_tile_format_B = "UseEquation_S_B";


setSpaceTimeMap(prog, bpmax_single_strand_system,  s_reduction_diagonal_label,  "(i, j     ->   -i,  -1,    j,    j )");
setSpaceTimeMap(prog, bpmax_single_strand_system,  mm_max_plus_instance_label,  "(i, j, k  ->   -i,  -1,    k,    j )");
setSpaceTimeMap(prog, bpmax_single_strand_system,  s_reduction_final_label,     "(i, j     ->   -i,  -1,    j,    j )");
setSpaceTimeMap(prog, bpmax_single_strand_system,  s_tile_format_A,             "(i, j     ->   -i,   j,    1,    j )");
setSpaceTimeMap(prog, bpmax_single_strand_system,  s_tile_format_B,             "(i, j     ->   -i,   j,    2,    j )");


setSpaceTimeMapForUseEquationOptimization(prog, bpmax_single_strand_system, s_reduction_diagonal_label, 0, 0, 
      											"(i -> -1,   -1,     -1)",
      											"(i ->  1,    i,     -1)",
      											"(i ->  N,   -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, bpmax_single_strand_system, s_reduction_diagonal_label, 0, 0, "seq2_t");
setSpaceTimeMapForUseEquationOptimization(prog, bpmax_single_strand_system, s_reduction_diagonal_label, 1, 0, 
      											"(i1,j1 -> -1,   -1,    -1  )",
      											"(i1,j1 ->  1,  -i1,  j1-7  )",
      											"(i1,j1 ->  N,  -1,     -1  )");
setMemorySpaceForUseEquationOptimization(prog, bpmax_single_strand_system, s_reduction_diagonal_label, 1, 0, "S_C_1");




setSpaceTimeMapForUseEquationOptimization(prog, bpmax_single_strand_system, mm_max_plus_instance_label, 0, 0, 
      											"(i, j -> -1,   -1,     -1,  -1)",
      											"(i, j ->  1,    i,      j,   0)",
      											"(i, j ->  N,   -1,     -1,  -1)");
setMemorySpaceForUseEquationOptimization(prog, bpmax_single_strand_system, mm_max_plus_instance_label, 0, 0, "S_A");

setSpaceTimeMapForUseEquationOptimization(prog, bpmax_single_strand_system, mm_max_plus_instance_label, 0, 1, 
      											"(i1,j1 -> -1,   -1,   -1)",
      											"(i1,j1 ->  1,  -i1,   j1-7)",
      											"(i1,j1 ->  N,   -1,   -1)");
setMemorySpaceForUseEquationOptimization(prog, bpmax_single_strand_system, mm_max_plus_instance_label, 0, 1, "S_B");
setSpaceTimeMapForUseEquationOptimization(prog, bpmax_single_strand_system, mm_max_plus_instance_label, 1, 0, 
      											"(i1,j1 -> -1,  -1,   -1    )",
      											"(i1,j1 ->  1, -i1,   j1-6  )",
      											"(i1,j1 ->  N,  -1,   -1    )");
setMemorySpaceForUseEquationOptimization(prog, bpmax_single_strand_system, mm_max_plus_instance_label, 1, 0, "S_C_2");



setSpaceTimeMapForUseEquationOptimization(prog, bpmax_single_strand_system, s_reduction_final_label, 0, 0, 
      											"(i1,j1 -> -1,  -1,     -1  )",
      											"(i1,j1 ->  1,  -i1,  j1-7  )",
      											"(i1,j1 ->  N,  -1,     -1  )");
setMemorySpaceForUseEquationOptimization(prog, bpmax_single_strand_system, s_reduction_final_label, 0, 0, "seq2_t");
setSpaceTimeMapForUseEquationOptimization(prog, bpmax_single_strand_system, s_reduction_final_label, 0, 1, 
      											"(i, j -> -1,   -1,     -1)",
      											"(i, j ->  1,    i,      j)",
      											"(i, j ->  N,   -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, bpmax_single_strand_system, s_reduction_final_label, 0, 1, "S_C");

setSpaceTimeMapForUseEquationOptimization(prog, bpmax_single_strand_system, s_reduction_final_label, 1, 0, 
      											"(i1,j1 -> -1,  -1,    -1  )",
      											"(i1,j1 ->  1, -i1,  j1-6  )",
      											"(i1,j1 ->  N,  -1,    -1  )");
setMemorySpaceForUseEquationOptimization(prog, bpmax_single_strand_system, s_reduction_final_label, 1, 0, "S_C_3");
                                                             
                                                                  
 
setSpaceTimeMapForUseEquationOptimization(prog, bpmax_single_strand_system, s_tile_format_A, 0, 0, 
      											"(i -> -1,   -1,     -1 )",
      											"(i ->  1,    i,     -1 )",
      											"(i ->  N,   -1,     -1 )");
setMemorySpaceForUseEquationOptimization(prog, bpmax_single_strand_system, s_tile_format_A, 0, 0, "S_C");
setSpaceTimeMapForUseEquationOptimization(prog, bpmax_single_strand_system, s_tile_format_A, 1, 0, 
      											"(i1,j1 -> -1,  -1,    -1   )",
      											"(i1,j1 ->  1, -i1,   j1-6  )",
      											"(i1,j1 ->  N,  -1,    -1   )");
setMemorySpaceForUseEquationOptimization(prog, bpmax_single_strand_system, s_tile_format_A, 1, 0, "S_A");
  
  
setSpaceTimeMapForUseEquationOptimization(prog, bpmax_single_strand_system, s_tile_format_B, 0, 0, 
      											"(i -> -1,   -1,     -1)",
      											"(i ->  1,    i,     -1)",
      											"(i ->  N,   -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, bpmax_single_strand_system, s_tile_format_B, 0, 0, "S_C");
setSpaceTimeMapForUseEquationOptimization(prog, bpmax_single_strand_system, s_tile_format_B, 1, 0, 
      											"(i1,j1 -> -1,   -1,    -1)",
      											"(i1,j1 ->  1,  -i1,    j1-6)",
      											"(i1,j1 ->  N,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, bpmax_single_strand_system, s_tile_format_B, 1, 0, "S_A");
 

generateScheduledCode(prog, bpmax_single_strand_system, outDir);
generateMakefile(prog, bpmax_single_strand_system, outDir+"/mk_s_reductions");

