prog = ReadAlphabets("bpmax_single_strand_verify.ab");

rootSystem = "bpmax";
outDir = "./src";
Normalize(prog); 
CheckProgram(prog);
AShow(prog, rootSystem);

generateVerificationCode(prog, rootSystem, outDir);

#generateMakefile(prog, rootSystem, outDir);

                             
                                     