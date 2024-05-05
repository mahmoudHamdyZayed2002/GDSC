#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned int   uint32;
typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef signed int     sint32;
typedef signed char    sint8;
typedef signed short   sint16;

typedef enum{
    failed_allocate,
    null_ptr,
}error_case;

typedef struct {
    char stud_name[30];
    uint32 stud_id;
    uint16 stud_grade;
     uint8 stud_level;
}student_t;

typedef struct{
    char text[300];
    char correct_ans;
    uint8 degree;
}quistion_t;
typedef struct node{
    student_t stud_info;
    struct node *linker;
}linked_student;
error_case add_student_info(linked_student **header_,uint16 number);
error_case get_linked_length(linked_student *header , uint16 *size_);
void c_exam(void);
void cpp_exam(void);
void python_exam(void);
void java_exam(void);
void redirect_to_exam(uint8 level, void (*examFunc)(void));
void take_exam(linked_student *student);
uint32 Get_Length(linked_student *List);
void print_report(linked_student **heade_ );
