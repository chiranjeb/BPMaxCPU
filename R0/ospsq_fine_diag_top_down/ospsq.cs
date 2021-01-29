base_prog = "ospsqmax";
data_type="float";
system = base_prog + "_" + data_type;
prog = ReadAlphabets(system + ".ab");
base_folder = "./../../src/progs/ospsq_max/";

NormalizeReduction(prog, system, "FTable");
AShow(prog, system);
CheckProgram(prog);
Normalize(prog);  
AShow(prog, system);


#options = createTiledCGOptionForScheduledC();

outDir = base_folder + data_type;
#generateWriteC(prog, system, options, outDir);

#generateWrapper(prog, system, options, outDir);
#generateMakefile(prog, system, options, outDir);


#setMemoryMap(prog,    system, "NR_FTable",   "FTable",   "(i1,j1,i2,j2->i1, j1, i2, j2)");
#setSpaceTimeMap(prog, system, "FTable",      "(i1,j1,i2,j2       ->  j1-i1,   i1,  j1,    i2,       i2,    j2)");
#setSpaceTimeMap(prog, system, "NR_FTable",   "(i1,j1,i2,j2,k1,k2 ->  j1-i1,   i1,  k1,    i2,       k2,    j2)", 
#                                             "(i1,j1,i2,j2       ->  j1-i1,   i1,  i1-1,  i2,       i2-1,  j2)");
#setParallel(prog, system, "", "1");
#outDir = base_folder + data_type +  "_diag_left_2_right_coarse";
#generateScheduledCode(prog, system, outDir);
#generateWrapper(prog, system, outDir);
#generateMakefile(prog, system, outDir);
#generateVerificationCode(prog, system, outDir);



#setMemoryMap(prog,    system, "NR_FTable",   "FTable",   "(i1,j1,i2,j2->i1, j1, i2, j2)");
#setSpaceTimeMap(prog, system, "FTable",      "(i1,j1,i2,j2       ->  j1-i1,   i1,  j2-i2, i2,  j1,    j2)");
#setSpaceTimeMap(prog, system, "NR_FTable",   "(i1,j1,i2,j2,k1,k2 ->  j1-i1,   i1,  j2-i2, i2,  k1,    k2)", 
#                                             "(i1,j1,i2,j2       ->  j1-i1,   i1,  j2-i2, i2,  i1-1,  i2-1)" );
#setParallel(prog, system, "", "1");
#outDir = base_folder + data_type +  "base_schedule";
#generateScheduledCode(prog, system, outDir);
#generateWrapper(prog, system, outDir);
#generateMakefile(prog, system, outDir);
#generateVerificationCode(prog, system, outDir);

#setParallel(prog, system, "", "3");
#outDir = base_folder + data_type +  "_diag_left_2_right_left_2_right_fine/";
#generateScheduledCode(prog, system, options, outDir);
#generateWrapper(prog, system, options, outDir);
#generateMakefile(prog, system, options, outDir);
#generateVerificationCode(prog, system, outDir);


#outDir = base_folder + data_type + "_bottom_up_bottom_up_fine";
#setMemoryMap(prog,    system, "NR_FTable",    "FTable",   "(i1,j1,i2,j2-> i1, j1, i2, j2)");
#setSpaceTimeMap(prog, system, "FTable",       "(i1,j1,i2,j2       ->  -i1,     j1,     j1,     -i2,     j2,      j2)");
#setSpaceTimeMap(prog, system, "NR_FTable",    "(i1,j1,i2,j2,k1,k2 ->  -i1,     j1,     k1,     -i2,     k2,      j2)", 
#                                              "(i1,j1,i2,j2       ->  -i1,     j1,     i1-1,   -i2,     i2-1,    j2)");
#setParallel(prog, system, "", "3");
#generateScheduledCode(prog, system, options, outDir);
#generateWrapper(prog, system, options, outDir);
#generateMakefile(prog, system, options, outDir);
#generateVerificationCode(prog, system, outDir);


outDir = base_folder + data_type + "_fine_diag_top_down";
setMemoryMap(prog,    system, "NR_FTable",    "FTable",   "(i1,j1,i2,j2-> i1, j1, i2, j2)");
setSpaceTimeMap(prog, system, "FTable",       "(i1,j1,i2,j2       ->  j1-i1,     i1,     j1,     i2,     j2,      j2)");
setSpaceTimeMap(prog, system, "NR_FTable",    "(i1,j1,i2,j2,k1,k2 ->  j1-i1,     i1,     k1,     i2,     k2,      j2)", 
                                              "(i1,j1,i2,j2       ->  j1-i1,     i1,     i1-1,   i2,     i2-1,    j2)");
setParallel(prog, system, "", "3");
generateScheduledCode(prog, system, outDir);
generateWrapper(prog, system, outDir);
generateMakefile(prog, system, outDir);
generateVerificationCode(prog, system, outDir);







