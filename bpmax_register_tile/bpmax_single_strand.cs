prog = ReadAlphabets("bpmax_single_strand.ab");
outDir = "./src";

Normalize(prog); 
CheckProgram(prog);

system_s1 = "bpmax_single_strand_s1";
AShow(prog, system_s1);
setSpaceTimeMap(prog, system_s1, "S1",      "(i,j    -> j-i,   i)"); 
setParallel(prog, system_s1, "", "1");
generateScheduledCode(prog, system_s1, outDir);

system_s2 = "bpmax_single_strand_s2";
AShow(prog, system_s2);
setSpaceTimeMap(prog, system_s2, "S2",      "(i,j    -> j-i,   i)"); 
setParallel(prog, system_s2, "", "1");
generateScheduledCode(prog, system_s2, outDir);                                        