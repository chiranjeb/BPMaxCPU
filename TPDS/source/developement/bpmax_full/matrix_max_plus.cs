prog = ReadAlphabets("matrix_max_plus.ab");

system_s1 = "matrix_max_plus_section";

outDir = "./src";

NormalizeReduction(prog, system_s1, "C_section");
Normalize(prog); 
CheckProgram(prog);



AShow(prog, system_s1);
setSpaceTimeMap(prog, system_s1, "C_section", "(i,j, k ->  i,   k,  j)" ,
                                              "(i,j    ->  i,   j,  0)" );
setParallel(prog, system_s1, "", "1");
generateScheduledCode(prog, system_s1, outDir);