#include <stdio.h>
#include <assert.h>

typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;

char *format = "<tr>\n"
               "<td>%s</td>\n"
               "<td>%d</td>\n"
               "<td>%s</td>\n"
               "<td>%f, %f, %f, %f</td>\n"
               "<td>%d, %d, %d</td>\n"
               "</tr>\n";

int main(){
    char strin[85], strout[85];
    scanf("%s%s", strin, strout);
    FILE *fin = fopen(strin, "rb");
    FILE *fout = fopen(strout, "w");


    fprintf(fout, "<table border=\"1\">\n<tbody>\n");
    Student stu;
    while(fread(&stu, sizeof(Student), 1, fin) != 0){
        fprintf(fout, format, stu.name,
                              stu.id,
                              stu.phone,
                              stu.grade[0], stu.grade[1], stu.grade[2], stu.grade[3],
                              stu.birth_year, stu.birth_month, stu.birth_day);
    }
    fprintf(fout, "</tbody>\n</table>\n");

    fclose(fin);
    fclose(fout);
    return 0;
}
