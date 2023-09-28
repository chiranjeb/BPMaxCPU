prog = ReadAlphabets("bpmax_plus_plus.ab");

system = "bpmax";
NormalizeReduction(prog, system, "FTable");
AShow(prog, system);
CheckProgram(prog);
Normalize(prog);
ASave(prog, "plus_plus_IR.ab");
outDir = "./plus_plus";
setMemorySpace(prog, system, "FTable",      "FTable, NR_FTable, NR_FTable_3, NR_FTable_4");
setMemoryMap(prog, system,   "NR_FTable_1", "NR_FTable1",   "(i1,j1,i2,j2->i1, j2)");
setMemoryMap(prog, system,   "NR_FTable_2", "NR_FTable2",   "(i1,j1,i2,j2->i1, j2)");

setSpaceTimeMap(prog, system, "S1",           "(i,j               ->  0,     0,      0,   j-i,          i,       0,     0,     0)");
setSpaceTimeMap(prog, system, "S2",           "(i,j               ->  0,     0,      0,   j-i,          i,       0,     0,     0)");
setSpaceTimeMap(prog, system, "FTable",       "(i1,j1,i2,j2       ->  1,   j1-i1,    M,   0,            i1,      -i2,   j2,    0)");
setSpaceTimeMap(prog, system, "NR_FTable",    "(i1,j1,i2,j2,k1,k2 ->  1,   j1-i1,   i1,   k1,           i2,      k2,    j2,    0)", 
                                              "(i1,j1,i2,j2       ->  0,   j1-i1,   i1,   0,            i2,      0,     j2,    0)");
setSpaceTimeMap(prog, system, "NR_FTable_3",  "(i1,j1,i2,j2,k1    ->  1,   j1-i1,   i1,   k1,           i2,      i2,    j2,    0)", 
                                              "(i1,j1,i2,j2       ->  0,   j1-i1,   i1,    0,           i2,      0,     j2,    0)");
setSpaceTimeMap(prog, system, "NR_FTable_4",  "(i1,j1,i2,j2,k1    ->  1,   j1-i1,   i1,   k1,           i2,      i2,    j2,    0)", 
                                              "(i1,j1,i2,j2       ->  0,   j1-i1,   i1,    0,           i2,      0,     j2,    0)");
setSpaceTimeMap(prog, system, "NR_FTable_1",  "(i1,j1,i2,j2,k2    ->  1,   j1-i1,    M,   0,            i1,      -i2,   k2,    j2)", 
                                              "(i1,j1,i2,j2       ->  1,   j1-i1,    M,   0,            i1,      -i2,   i2-1,  j2)");  
setSpaceTimeMap(prog, system, "NR_FTable_2",  "(i1,j1,i2,j2,k2    ->  1,   j1-i1,    M,   0,            i1,      -i2,   k2,    j2)", 
                                              "(i1,j1,i2,j2       ->  1,   j1-i1,    M,   0,            i1,      -i2,   i2-1,  j2)");


setParallel(prog, system, "", "4");
AShow(prog, system);
generateScheduledCode(prog, system, outDir);
generateWrapper(prog, system, outDir);
generateVerificationCode(prog, system, outDir);

