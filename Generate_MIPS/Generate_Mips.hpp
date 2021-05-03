#ifndef __GENERATE_MIPS_HPP__
#define __GENERATE_MIPS_HPP__

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

enum operations{lsquare,_not,_and,_or,add,minus,multiple,divide,lt,gt,
                equal,noteq,lteq,gteq,shlop,shrop,andand,oror,paren};

class Generate_Mips{
    private:
        /* This vector store the data segment of mips code */
		std::vector<std::string> data_segment{".data",
			"_prompt: .asciiz \"Enter the value of variable \" ",
			"_enter: .asciiz \"  \\n\" "};
		/* This vector store the text segment of mips code */
		std::vector<std::string> text_segment{".text",
            "lui $t0,4097"};
        int gt_not_count=0,equal_count=0;
    public:
        void operations_in_memory(int idx1,int idx2,operations operation){
            switch (operation){
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lw $s2,"+std::to_string(idx2*4)+"($t0)");
                    text_segment.push_back("add $s0,$s1,$s2");
                    text_segment.push_back("sw $s0,"+std::to_string(idx1*4)+"($t0)");
                    break;
                case 5:
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lw $s2,"+std::to_string(idx2*4)+"($t0)");
                    text_segment.push_back("sub $s0,$s1,$s2");
                    text_segment.push_back("sw $s0,"+std::to_string(idx1*4)+"($t0)");
                    break;
                case 6:
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lw $s2,"+std::to_string(idx2*4)+"($t0)");
                    text_segment.push_back("mul $s0,$s1,$s2");
                    text_segment.push_back("sw $s0,"+std::to_string(idx1*4)+"($t0)");
                    break;
                case 7:
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lw $s2,"+std::to_string(idx2*4)+"($t0)");
                    text_segment.push_back("div $s1,$s2");
                    text_segment.push_back("sw $lo,"+std::to_string(idx1*4)+"($t0)");
                    break;
                case 8:
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lw $s2,"+std::to_string(idx2*4)+"($t0)");
                    text_segment.push_back("slt $s0,$s1,$s2");
                    text_segment.push_back("sw $s0,"+std::to_string(idx1*4)+"($t0)");
                    break;
                case 9:
                    /* use beq slt to design the greater than */
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lw $s2,"+std::to_string(idx2*4)+"($t0)");
                    text_segment.push_back("slt $t3,$t1,$t2");
                    text_segment.push_back("li $t4,1");
                    text_segment.push_back("sw $zero,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("beq $t3,$t4,gt_not_label"+std::to_string(gt_not_count));
                    text_segment.push_back("beq $t1,$t2,gt_not_label"+std::to_string(gt_not_count));    
                    text_segment.push_back("sw $t4,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("gt_not_label"+std::to_string(gt_not_count++)+":");                 
                    break;
                case 10:
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lw $s2,"+std::to_string(idx2*4)+"($t0)");
                    text_segment.push_back("li $t3,1");
                    text_segment.push_back("sw $t3,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("beq $s1,$s2,equal_label"+std::to_string(equal_count));
                    text_segment.push_back("sw $zero,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("equal_label"+std::to_string(equal_count++)+":");
                    break;
                case 11:
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lw $s2,"+std::to_string(idx2*4)+"($t0)");
                    text_segment.push_back("li $t3,1");
                    text_segment.push_back("sw $zero,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("beq $s1,$s2,equal_label"+std::to_string(equal_count));
                    text_segment.push_back("sw $t3,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("equal_label"+std::to_string(equal_count++)+":");
                    break;
                case 12:
                    std::cout<<"Case 12 Execution"<<std::endl;
                    generate_mips->operations_in_memory(count-1,count,lteq);
                    break;
                case 13:
                    std::cout<<"Case 13 Execution"<<std::endl;
                    generate_mips->operations_in_memory(count-1,count,gteq);
                    break;
                case 14:
                    std::cout<<"Case 14 Execution"<<std::endl;
                    generate_mips->operations_in_memory(count-1,count,shlop);
                    break;
                case 15:
                    std::cout<<"Case 15 Execution"<<std::endl;
                    generate_mips->operations_in_memory(count-1,count,shrop);
                    break;
                case 16:
                    std::cout<<"Case 16 Execution"<<std::endl;
                    generate_mips->operations_in_memory(count-1,count,andand);
                    break;
                case 17:
                    std::cout<<"Case 17 Execution"<<std::endl;
                    generate_mips->operations_in_memory(count-1,count,oror);
                    break;
                case 18:
                    std::cout<<"Case 18 Execution"<<std::endl;
                    generate_mips->operations_in_memory(count-1,count,paren);
                    break;
            }
        }
};

#endif
