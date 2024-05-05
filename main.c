#include "project.h"

const char *user_name="hamedoo";
const char password = 123;
char str[];
char user_password;
uint32 std_id;
linked_student *head_;
int stud_number;
int mode ;
uint32 list_length;
int main()
{


    while (1){
            printf("select user mode [1 --> teacher_mode  or  2--> student_mode]:");
            scanf("%d",&mode);
            if(mode ==1){
                fflush(stdin);
                printf("enter user name: ");
                scanf("%[^\n]%*c",str);
                if((strcmp(str,user_name))==0){
                    printf("enter password: ");
                    scanf("%i",&user_password);
                    if(password == user_password){
                        printf("enter number of students : ");
                        scanf("%d",&stud_number);
                        add_student_info(&head_,stud_number);
                        get_linked_length(head_ , &stud_number);
                        printf("number of students = %i\n",stud_number);
                        display_data(head_);
                        list_length = Get_Length(head_);
                    }
                    else{printf("error password \n");}


                }
                else{printf("error name \n");}


            }
            else if(mode == 2){
                printf("number of students is : %i \n",list_length);
                uint32 count_1 = list_length;
                while(count_1 != 0){


                    printf("enter your id :");
                    scanf("%i",&std_id);

                    linked_student *usage_student = head_;
                    while(usage_student->stud_info.stud_id != std_id){
                        usage_student = usage_student->linker;
                        if((usage_student->stud_info.stud_id != std_id)&&(usage_student ==NULL)){
                            printf("enter correct id :");
                            continue;
                        }
                    }
                    printf("your level is : %i\n",usage_student->stud_info.stud_level);
                    printf("------------------------------------------------------------\n");
                    redirect_to_exam(usage_student->stud_info.stud_level,c_exam);
                    take_exam(usage_student);
                    printf("degree ==   %i \n",usage_student->stud_info.stud_grade);
                    count_1--;
                }
                printf("data befor being ordered \n");
                display_data(head_);
                printf("data after being ordered \n");
                print_report(&head_ );

            }
            else{printf("select correct mode\n");}
    }

    return 0;
}
