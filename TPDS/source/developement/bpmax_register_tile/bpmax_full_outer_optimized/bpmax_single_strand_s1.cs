prog = ReadAlphabets("bpmax_single_strand_s1.ab");

system_s1 = "bpmax_single_strand_s1";

outDir = "./src";

#NormalizeReduction(prog, system_s1, "S1");
Normalize(prog); 
CheckProgram(prog);



AShow(prog, system_s1);
setSpaceTimeMap(prog, system_s1, "S1",      "(i,j    -> j-i,   i)"); 
#setSpaceTimeMap(prog, system_s1, "NR_S1",   "(i,j,k  ->  j-i,   k,   j)", 
#                                            "(i,j    ->   i,   j,   0)");    
#setSpaceTimeMap(prog, system_s1, "S1",      "(i,j    -> j-i,   i)"); 
setParallel(prog, system_s1, "", "1");
generateScheduledCode(prog, system_s1, outDir);