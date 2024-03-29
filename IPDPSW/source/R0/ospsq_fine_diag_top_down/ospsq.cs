system = "ospsqmax_float";
prog = ReadAlphabets("ospsq_float.ab");

NormalizeReduction(prog, system, "FTable");
AShow(prog, system);
CheckProgram(prog);
Normalize(prog);  
AShow(prog, system);


outDir = "./src";
setMemoryMap(prog,    system, "NR_FTable",    "FTable",   "(i1,j1,i2,j2-> i1, j1, i2, j2)");
setSpaceTimeMap(prog, system, "FTable",       "(i1,j1,i2,j2       ->  j1-i1,     i1,     j1,     i2,     j2,      j2)");
setSpaceTimeMap(prog, system, "NR_FTable",    "(i1,j1,i2,j2,k1,k2 ->  j1-i1,     i1,     k1,     i2,     k2,      j2)", 
                                              "(i1,j1,i2,j2       ->  j1-i1,     i1,     i1-1,   i2,     i2-1,    j2)");
setParallel(prog, system, "", "3");
generateScheduledCode(prog, system, outDir);
generateWrapper(prog, system, outDir);
generateMakefile(prog, system, outDir);
generateVerificationCode(prog, system, outDir);







