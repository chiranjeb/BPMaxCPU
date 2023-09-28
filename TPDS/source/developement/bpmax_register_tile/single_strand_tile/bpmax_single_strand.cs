prog = ReadAlphabets("bpmax_single_strand.ab");

rootSystem = "bpmax";

outDir = "./src";

Normalize(prog); 
CheckProgram(prog);

AShow(prog, rootSystem);


## PrintAST to figure out the label for the use equation that needs to be scheduled                                                 
PrintAST(prog, rootSystem);
equation_s2 = "UseEquation_S2_A";
equation_seq2_t = "UseEquation_seq2_t";
equation_s2_output_2d = "UseEquation_S2";


setSpaceTimeMap(prog, rootSystem, equation_seq2_t,            "( i         ->  0,      0,   i,  0,     0)");
setSpaceTimeMap(prog, rootSystem, equation_s2,                "( i         ->  0,      2,   i,  0,     0)");
setSpaceTimeMap(prog, rootSystem, equation_s2_output_2d,      "( i         ->  1,      2,   i,  0,     0)");

                                                                          
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


################################   S2  #################################################
setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_s2_output_2d, 0, 0, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_s2_output_2d, 0, 0, "S2_C");

setSpaceTimeMapForUseEquationOptimization(prog, rootSystem, equation_s2_output_2d, 1, 0, 
      											"(i -> -1,   -1,     -1,  -1, 0)",
      											"(i ->  1,    i,     -1,  -1, 0)",
      											"(i ->  M,   -1,     -1,  -1, 0)");
setMemorySpaceForUseEquationOptimization(prog, rootSystem, equation_s2_output_2d, 1, 0, "S2");



CheckProgram(prog);
setParallel(prog, rootSystem, "", "3");
generateScheduledCode(prog, rootSystem, outDir);
#generateMakefile(prog, rootSystem, outDir);
#generateWrapper(prog, rootSystem, outDir);


                             
                                             