file_for_g++ = lex.yy.c parser.tab.c
mips_header = Generate_MIPS/Generate_Mips.hpp Generate_MIPS/Variable_Stack.hpp

micro: scanner.l parser.y $(mips_class) $(mips_header)
	bison -d parser.y
	flex scanner.l
	g++ $(file_for_g++) $(mips_class) -o xc -lfl 

clean:
	rm -r parser.tab.c parser.tab.h lex.yy.c xc