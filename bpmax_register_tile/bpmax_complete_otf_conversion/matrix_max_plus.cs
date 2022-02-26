prog = ReadAlphabets("matrix_max_plus.ab");

system_s1 = "matrix_max_plus";

outDir = "./src";

NormalizeReduction(prog, system_s1, "C");
Normalize(prog); 
CheckProgram(prog);



AShow(prog, system_s1);
setSpaceTimeMap(prog, system_s1, "C", "(i,j, k ->  i,   k,  j)" , "(i,j    -> -1,   i,  j)" );
generateScheduledCode(prog, system_s1, outDir);