#ifndef __GENERATE_MIPS_HPP__
#define __GENERATE_MIPS_HPP__

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>

enum operations{lsquare,_not,_and,_or,add,minus,multiple,divide,lt,gt,
                equal,noteq,lteq,gteq,shlop,shrop,andand,oror,paren,minus_number};

class Generate_Mips{
    private:
        /* This vector store the data segment of mips code */
		// std::vector<std::string> data_segment{".data",
		// 	"_prompt: .asciiz \"Enter the value of variable \" ",
		// 	"_enter: .asciiz \"  \\n\" "};
        std::vector<std::string> data_segment{".data"};
		/* This vector store the text segment of mips code */
		std::vector<std::string> text_segment{".text",
            "lui $t0,4097"};
        int gt_not_count=0,equal_count=0,lteq_count=0,gteq_count=0,s1_zero_count=0,s2_zero_count=0;
    public:
        void expression_variable(int variable_idx,int cmulative_idx){
            text_segment.push_back("lw $t1,"+std::to_string(variable_idx*4)+"($t0)");
            text_segment.push_back("sw $t1,"+std::to_string(cmulative_idx*4)+"($t0)");
        }
        void expression_decla(int index, int value){
            text_segment.push_back("li $t1,"+std::to_string(value));
            text_segment.push_back("sw $t1,"+std::to_string(index*4)+"($t0)");
        }
        void operations_in_memory(int idx1,int idx2,operations operation){
            switch (operation){
                case 0:
                    // TODO
                case 1:
                    // TODO
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("li $s2,"+std::to_string(__INT32_MAX__));
                    text_segment.push_back("xor $s0,$s1,$s2");
                    text_segment.push_back("sw $s0,"+std::to_string(idx1*4)+"($t0)");
                    break;
                case 2:
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lw $s2,"+std::to_string(idx2*4)+"($t0)");
                    text_segment.push_back("and $s0,$s1,$s2");
                    text_segment.push_back("sw $s0,"+std::to_string(idx1*4)+"($t0)");
                    break;
                case 3:
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lw $s2,"+std::to_string(idx2*4)+"($t0)");
                    text_segment.push_back("or $s0,$s1,$s2");
                    text_segment.push_back("sw $s0,"+std::to_string(idx1*4)+"($t0)");
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
                    text_segment.push_back("mflo $t1");
                    text_segment.push_back("sw $t1,"+std::to_string(idx1*4)+"($t0)");
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
                    text_segment.push_back("slt $t3,$s1,$s2");
                    text_segment.push_back("li $t4,1");
                    text_segment.push_back("sw $zero,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("beq $t3,$t4,gt_not_label"+std::to_string(gt_not_count));
                    text_segment.push_back("beq $s1,$s2,gt_not_label"+std::to_string(gt_not_count));    
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
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lw $s2,"+std::to_string(idx2*4)+"($t0)");
                    text_segment.push_back("slt $t3,$s1,$s2");
                    text_segment.push_back("li $t4,1");
                    text_segment.push_back("sw $t4,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("beq $t3,$t4,lteq_label"+std::to_string(lteq_count));
                    text_segment.push_back("beq $s1,$s2,lteq_label"+std::to_string(lteq_count));    
                    text_segment.push_back("sw $zero,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lteq_label"+std::to_string(lteq_count++)+":");
                    break;
                /* 从这里开始想通了greater than只要把两个寄存器的位置换一下就好 上面一直是按照不小于等于来做的 */
                case 13:
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lw $s2,"+std::to_string(idx2*4)+"($t0)");
                    text_segment.push_back("slt $t3,$s2,$s1");
                    text_segment.push_back("li $t4,1");
                    text_segment.push_back("sw $t4,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("beq $t3,$t4,gteq_label"+std::to_string(gteq_count));
                    text_segment.push_back("beq $s1,$s2,gteq_label"+std::to_string(gteq_count));    
                    text_segment.push_back("sw $zero,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("gteq_label"+std::to_string(gteq_count++)+":");
                    break;
                case 14:
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lw $s2,"+std::to_string(idx2*4)+"($t0)");
                    text_segment.push_back("sllv $t3,$s1,$s2");
                    text_segment.push_back("sw $t3,"+std::to_string(idx1*4)+"($t0)");
                    break;
                case 15:
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lw $s2,"+std::to_string(idx2*4)+"($t0)");
                    text_segment.push_back("srlv $t3,$s1,$s2");
                    text_segment.push_back("sw $t3,"+std::to_string(idx1*4)+"($t0)");
                    break;
                case 16:
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lw $s2,"+std::to_string(idx2*4)+"($t0)");
                    text_segment.push_back("sw $zero,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("li $t3,1");
                    text_segment.push_back("beq $s1,$zero,s1_zero_label"+std::to_string(s1_zero_count));
                    text_segment.push_back("beq $s2,$zero,s2_zero_label"+std::to_string(s2_zero_count));
                    text_segment.push_back("sw $t3,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("s1_zero_label"+std::to_string(s1_zero_count++)+":");
                    text_segment.push_back("s2_zero_label"+std::to_string(s2_zero_count++)+":");
                    break;
                case 17:
                    text_segment.push_back("lw $s1,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("lw $s2,"+std::to_string(idx2*4)+"($t0)");
                    text_segment.push_back("li $t3,1");
                    text_segment.push_back("sw $t3,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("bne $s1,$zero,s1_zero_label"+std::to_string(s1_zero_count));
                    text_segment.push_back("bne $s2,$zero,s2_zero_label"+std::to_string(s2_zero_count));
                    text_segment.push_back("sw $zero,"+std::to_string(idx1*4)+"($t0)");
                    text_segment.push_back("s1_zero_label"+std::to_string(s1_zero_count++)+":");
                    text_segment.push_back("s2_zero_label"+std::to_string(s2_zero_count++)+":");
                    break;
                case 18:
                    break;
            }
        }

        void variable_valued(int var_idx,int cumlative_index){
            text_segment.push_back("lw $t1,"+std::to_string(cumlative_index*4)+"($t0)");
            text_segment.push_back("sw $t1,"+std::to_string(var_idx*4)+"($t0)");
        }
        void array_valued(int cumlative_index,int length){
            text_segment.push_back("lw $t1,"+std::to_string(cumlative_index*4-4)+"($t0)");
            text_segment.push_back("lw $t2,"+std::to_string(cumlative_index*4)+"($t0)");
            text_segment.push_back("li $t3,4");
            text_segment.push_back("mul $t4,$t3,$t1");
            text_segment.push_back("add $t4,$t4,$t0");
            text_segment.push_back("sw $t1,0($t4)");
        };
        void variable_decla(int index,int value){
            text_segment.push_back("li $t1,"+std::to_string(value));
            text_segment.push_back("sw $t1,"+std::to_string(index*4)+"($t0)");
        }
        void generate_mips_code(){
            std::ofstream outfile("compile.asm");
            for (auto line:data_segment){
                outfile<<line<<std::endl;
            }
            for (auto line:text_segment){
                outfile<<line<<std::endl;
            }
        }
};

#endif