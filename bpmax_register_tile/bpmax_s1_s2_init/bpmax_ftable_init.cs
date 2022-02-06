prog = ReadAlphabets("bpmax_ftable_init.ab");

rootSystem = "bpmax_ftable_init";
AShow(prog, rootSystem);
CheckProgram(prog);

outDir = "./src";

Normalize(prog); 
CheckProgram(prog);

AShow(prog, rootSystem);

setSpaceTimeMap(prog, rootSystem, "FTable_C_I1_J1_I2_J2",    "(i, j    ->  0, i,  j, 0)");
#setParallel(prog, rootSystem, "", "1");
generateScheduledCode(prog, rootSystem, outDir);

                             
                                             