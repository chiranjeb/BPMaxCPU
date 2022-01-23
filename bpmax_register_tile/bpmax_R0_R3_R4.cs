prog = ReadAlphabets("bpmax_R0_R3_R4.ab");
outer_reduction_system = "bpmax_outer_reductions";

r0_r3_r4_instance_system = "bpmax_outer_reductions";

Normalize(prog);  
#AShow(prog, subSystem);
CheckProgram(prog);

outDir = "./src";

#outer_reduction_label = "UseEquation_FTable_4D_dummy";
r0_instance_label = "UseEquation_FTable_C_section_1";
r3_instance_label = "UseEquation_FTable_C_section_2";
r4_instance_label = "UseEquation_FTable_4D";


#PrintAST(prog, r0_r3_r4_instance);

##############################################################################################################################
###############################################     bpmax_r0_r3_r4                    ########################################
setSpaceTimeMap(prog, r0_r3_r4_instance_system,  r3_instance_label,       "(i ,j         ->    i, i, j)");
setSpaceTimeMap(prog, r0_r3_r4_instance_system,  r4_instance_label,       "(i ,j         ->    i, i, j)");
setSpaceTimeMap(prog, r0_r3_r4_instance_system,  r0_instance_label,       "(i ,j, k      ->    i, k, j)");


                                                  
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
setMemorySpaceForUseEquationOptimization(prog, r0_r3_r4_instance_system, r4_instance_label, 1, 0, "FTable_4D");



        
                                          
                                                                          
generateScheduledCode(prog, outer_reduction_system, outDir);

                                       