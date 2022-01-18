prog = ReadAlphabets("bpmax_single_strand.ab");

system_s1 = "bpmax_single_strand_s1";
system_s2 = "bpmax_single_strand_s2";

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

#NormalizeReduction(prog, system_s2, "S2");
AShow(prog, system_s2);
setSpaceTimeMap(prog, system_s2, "S2",      "(i,j    -> j-i,   i)"); 
#setSpaceTimeMap(prog, system_s2, "NR_S2",   "(i,j,k  ->  j-i,   k,   j)", 
#                                            "(i,j    ->   i,   j,   0)");    
#setSpaceTimeMap(prog, system_s2, "S2",      "(i,j    -> j-i,   i)");                              
setParallel(prog, system_s2, "", "1");
generateScheduledCode(prog, system_s2, outDir);                                        