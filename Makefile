file_for_g++ = lex.yy.c parser.tab.c
mips_class = Generate_MIPS/generate_mips.cpp
mips_header = Generate_MIPS/generate_mips.h

micro: scanner.l parser.y $(mips_class) $(mips_header)
	bison -d parser.y
	flex scanner.l
	g++ $(file_for_g++) $(mips_class) -o micro -lfl 

clean:
	rm -r parser.tab.c parser.tab.h lex.yy.c micro mips.asm
