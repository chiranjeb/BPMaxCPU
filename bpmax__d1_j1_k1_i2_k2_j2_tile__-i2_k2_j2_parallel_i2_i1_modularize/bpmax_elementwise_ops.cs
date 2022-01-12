prog = ReadAlphabets("bpmax_elementwise_ops.ab");

system = "bpmax_elementwise_ops";
AShow(prog, system);

outDir = "./src";

Normalize(prog); 
CheckProgram(prog);

AShow(prog, system);


setSpaceTimeMap(prog, system, "FTable_2D",    "(i, j    -> i,  j)");
                                                                          

#setParallel(prog, rootSystem, "", "3");
generateScheduledCode(prog, system, outDir);

                             
                                             