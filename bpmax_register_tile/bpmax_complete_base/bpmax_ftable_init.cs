prog = ReadAlphabets("bpmax_ftable_init.ab");

rootSystem = "bpmax_ftable_init";
AShow(prog, rootSystem);
CheckProgram(prog);

outDir = "./src";

Normalize(prog); 
CheckProgram(prog);

AShow(prog, rootSystem);

setSpaceTimeMap(prog, rootSystem, "FTable_C_I1_J1",    "(i1, j1, i2, j2    ->  i1,  j1, i2, j2)");
setParallel(prog, rootSystem, "", "0");
generateScheduledCode(prog, rootSystem, outDir);

                             
                                             