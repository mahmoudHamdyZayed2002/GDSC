#include "project.h"  // Include necessary header file

// Define a static array to store correct answers for questions
static char arr[5]={0};

// Function to display a C exam
static inline void show_exam(quistion_t exam_arr[5]){

    // Loop through each question
    for(int i=0 ; i<5 ; i++){
        printf("%s\n",exam_arr[i].text);  // Print the question text
        printf("-------------\n");  // Separator between questions
    }

}

// Function to set up a C exam
void c_exam(void){
    // Array to store exam questions and their details
    quistion_t exame_ques[5]={0};

    // Set up each exam question
    strcpy(exame_ques[0].text , "What is the output of the following C code?*\n #include <stdio.h> \n int main() {\n int x = 5;\n printf('%d', x++);\n return 0;}\n [a] 5 [b] 6 [c] 4 [d] 7");
    exame_ques[0].correct_ans = 'b';
    exame_ques[0].degree=5;
    arr[0]= exame_ques[0].correct_ans;

    // Set up other exam questions similarly...

    // Display the exam
    show_exam(exame_ques);

}

// Functions for exams in other languages (not implemented in this code)
void cpp_exam(void){}
void python_exam(void){}
void java_exam(void){}

// Function to add student information to a linked list
error_case add_student_info(linked_student **header_, uint16 number){
    linked_student *student_tmp = NULL;
    char str[30];

    // Check if header pointer is null
    if(NULL == header_){
        return null_ptr;
    }
    else{
        // Loop to add multiple students
        for(int i=0;i<number;i++){

            // Allocate memory for a new student node
            student_tmp = (linked_student*) malloc(sizeof(linked_student));
            if(student_tmp == NULL){
                return failed_allocate;
            }
            else{
                // Initialize student information
                student_tmp->stud_info.stud_grade = 0;
                printf("Student ID: ");
                scanf("%i",&(student_tmp->stud_info.stud_id));
                printf("Student Level: ");
                scanf("%i",&(student_tmp->stud_info.stud_level));
                printf("Student Name: ");
                fflush(stdin);
                gets(&str);
                strcpy(student_tmp->stud_info.stud_name , str);

                // Add student to the linked list
                if(NULL == *header_){
                    student_tmp->linker = NULL;
                    *header_ = student_tmp;
                }
                else{
                    student_tmp->linker = *header_;
                    *header_=student_tmp;
                }
            }
        }
    }
}

// Function to get the length of a linked list
error_case get_linked_length(linked_student *header , uint16 *size_){
    linked_student *temp_;
    temp_ = header;

    *size_=0;

    // Loop through the linked list and count nodes
    while(temp_!=NULL){
        (*size_)++;
        temp_=temp_->linker;
    }

}

// Function to display student information stored in a linked list
void display_data(linked_student *header){
    linked_student *temp_;
    int count =1;

    // Check if header pointer is null
    if(header == NULL){
        return null_ptr;
    }
    else{
        // Loop through the linked list and print student information
        temp_ = header;
        while(temp_!=NULL){
            printf("Student [%i] -> Name: %s \t ID: %i \t Level: %i \t Grade: %i \n", count, temp_->stud_info.stud_name, temp_->stud_info.stud_id, temp_->stud_info.stud_level, temp_->stud_info.stud_grade);
            printf("----------------------------------\n");
            temp_=temp_->linker;
            count++;
        }
        // Print "NULL" if end of list is reached
        if(NULL == temp_){
            printf("End of List\n");
        }
    }

}

// Function to redirect to a specific exam based on input level
void redirect_to_exam(uint8 level, void (*examFunc)(void)) {
    examFunc();  // Call the specified exam function
}

// Function for a student to take an exam
void take_exam(linked_student *student){

    char answer ;
    char total_degree=0;
    for(int i=0;i<5;i++){
        printf("Question [%i] Answer: ", i);
        fflush(stdin);
        scanf("%c",&answer);
        if(toupper(answer) == toupper(arr[i]))
            total_degree+=5;
    }
    student->stud_info.stud_grade = total_degree;
}

// Function to get the length of a linked list
uint32 Get_Length(linked_student *List){
    linked_student *TempNode = List;
    uint32 NodeCount = 0;

    // Loop through the linked list and count nodes
    while(TempNode != NULL){
        NodeCount++;
        TempNode = TempNode->linker;
    }

    return NodeCount;
}

// Function to print a report showing student information
void print_report(linked_student **heade_ ) {
    // Sort students by grade (incomplete)
    linked_student *temp_node = *heade_;
    linked_student *rep1_node = NULL;
    linked_student *rep2_node = temp_node->linker;
    while(temp_node->stud_info.stud_grade < rep2_node->stud_info.stud_grade){
        rep1_node = temp_node->linker;
        temp_node->linker = rep2_node->linker;
        rep2_node->linker = temp_node;
        *heade_ = rep2_node;
    }

    // Print the report
    printf("Report:\n");
    display_data(*heade_);
}




