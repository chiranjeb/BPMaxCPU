prog = ReadAlphabets("./bpmax_verify.ab");
system = "bpmax";
NormalizeReduction(prog, system, "FTable");
AShow(prog, system);
CheckProgram(prog);
Normalize(prog);  
outDir = "./src/";


#generateMakefile(prog, system, outDir);
#generateWrapper(prog, system, outDir);
generateVerificationCode(prog, system, outDir);

