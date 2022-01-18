prog = ReadAlphabets("bpmax_R0_R3_R4.ab");
outer_reduction_system = "bpmax_outer_reductions";

r0_r3_r4_instance_system = "bpmax_max_r0_r3_r4_instance";

Normalize(prog);  
#AShow(prog, subSystem);
CheckProgram(prog);

outDir = "./src";

outer_reduction_label = "UseEquation_FTable_4D_dummy";
r0_instance_label = "UseEquation_FTable_C_section_1";
r3_instance_label = "UseEquation_FTable_C_section_2";
r4_instance_label = "UseEquation_FTable_C_section_3";


#PrintAST(prog, r0_r3_r4_instance);

##############################################################################################################################
###############################################     bpmax_outer_reductions ###################################################
setSpaceTimeMap(prog, outer_reduction_system,  outer_reduction_label,       "(i                 ->   -1,  i,  0,     0)");
setSpaceTimeMap(prog, outer_reduction_system, "FTable_outer_reductions",    "(i1, j1, i2, j2    ->   i1, j1,  i2, j2)");

                                                  
setSpaceTimeMapForUseEquationOptimization(prog, outer_reduction_system, outer_reduction_label, 0, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, outer_reduction_system, outer_reduction_label, 0, 0, "FTable_A");

setSpaceTimeMapForUseEquationOptimization(prog, outer_reduction_system, outer_reduction_label, 0, 1, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, outer_reduction_system, outer_reduction_label, 0, 1, "FTable_B");

setSpaceTimeMapForUseEquationOptimization(prog, outer_reduction_system, outer_reduction_label, 0, 2, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, outer_reduction_system, outer_reduction_label, 0, 2, "FTable_C");

setSpaceTimeMapForUseEquationOptimization(prog, outer_reduction_system, outer_reduction_label, 0, 3, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-6,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, outer_reduction_system, outer_reduction_label, 0, 3, "S1");



setSpaceTimeMapForUseEquationOptimization(prog, outer_reduction_system, outer_reduction_label, 1, 0, 
      											          "(i1 -> -1,   -1,     -1,  -1    )",
      											          "(i1->  1,    i1,      0,  -3    )",
      											          "(i1->  M+M,  -1,     -1,  -1    )");
setMemorySpaceForUseEquationOptimization(prog, outer_reduction_system, outer_reduction_label, 1, 0, "FTable_4D_dummy");

                                          
##############################################################################################################################
###############################################     bpmax_r0_r3_r4                    ########################################
setSpaceTimeMap(prog, r0_r3_r4_instance_system,  r3_instance_label,       "(i ,j       ->    i,  j,     0)");
setSpaceTimeMap(prog, r0_r3_r4_instance_system,  r4_instance_label,       "(i ,j       ->    i,  j,     1)");
setSpaceTimeMap(prog, r0_r3_r4_instance_system,  r0_instance_label,       "(i ,j       ->    i,  j,     2)");


                                                  
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
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r0_instance_label, 1, 0, "FTable_C_section_1");


setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, r3_instance_label, 0, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r3_instance_label, 0, 0, "S1");

setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, r3_instance_label, 0, 1, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r3_instance_label, 0, 1, "FTable_B");

setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, r0_instance_label, 1, 0, 
      											          "(i1 -> -1,   -1,     -1,  -1    )",
      											          "(i1->  1,    i1,      0,  -3    )",
      											          "(i1->  M+M,  -1,     -1,  -1    )");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r3_instance_label, 1, 0, "FTable_C_section_2");




setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, r4_instance_label, 0, 0, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r4_instance_label, 0, 0, "FTable_A");

setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, r4_instance_label, 0, 1, 
      											"(i1,j1 -> -1,   -1,     -1,  -1,      -1)",
      											"(i1,j1 ->  1,   j1-i1,  i1,  j1-7,    -1)",
      											"(i1,j1 ->  M+M,  -1,     -1,  -1,     -1)");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r4_instance_label, 0, 1, "S1");

setSpaceTimeMapForUseEquationOptimization(prog, r0_r3_r4_instance_system, r4_instance_label, 1, 0, 
      											          "(i1 -> -1,   -1,     -1,  -1    )",
      											          "(i1->  1,    i1,      0,  -3    )",
      											          "(i1->  M+M,  -1,     -1,  -1    )");
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r4_instance_label, 1, 0, "FTable_C_section_3");



        
                                          
                                                                          
generateScheduledCode(prog, outer_reduction_system, outDir);

                                       