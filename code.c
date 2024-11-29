#include <iostream>

//header files
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>


void xy(int ,int );

// functions
void adminPanellogin();
void adminPanel();

void assignTeacher();
void updateTeacherInfo();
void addStud();
void updateStudInfo();
void assignCourse();


void teachersPanellogin();
void teacherPanel();

void provideCTm();
void findStud();
void countStud();

void studentsPanellogin();
void studentPanel();


// global values
char adminUsername[10]="PANTHO";
char adminPassword[6] = "12345";
char tcName[20]="";
char stName[20]="";


//structures
typedef struct{
        char name[20] ;
        char pass[8];
        char mobile[11];
    }teacher;
typedef struct{
        char name[20] ;
        char roll[7];
        char pass[8];
        char mobile[11];
    }student;

typedef struct{
        char teacher[20] ;
        char c_name[30];
        char student[20];
    }course;

typedef struct{
        char teacher[20];
        char student[20];
        char mark[10];
    }result;



//main function
int main()
{
    system("cls");
    xy(56,30);
    printf("Created by Pantho(1907075)\n");


    xy(15,8);
    printf("|||| ||||||||||||||||||||||||||||||||||||||| ||||");
    xy(15,9);
    printf("||||                                         ||||");
    xy(15,10);
    printf("||||     University Management System:       ||||");
    xy(15,11);
    printf("||||                                         ||||");
    xy(15,12);
    printf("|||| ||||||||||||||||||||||||||||||||||||||| ||||");
    xy(19,15);
    printf("Which panel you belong to: ");
    xy(24,17);
    printf("1. Admin Panel");
    xy(24,18);
    printf("2. Teachers Panel");
    xy(24,19);
    printf("3. Students Panel");
    xy(24,20);
    printf("4. Exit");
    xy(19,22);
    printf("Enter the corresponding number for your panel:  ");
    int d;
    scanf("%d",&d);
    switch(d){
        case 1:
            adminPanellogin();
            break;
        case 2:
            teachersPanellogin();
            break;

        case 3:
            studentsPanellogin();
            break;
        case 4:
            exit(1);
            break;
        default:
            xy(28,26);
            printf("Invalid Choice.\n\n");

    }


    return 0;
}

// here the function of login to admin panel
void adminPanellogin()
{

    system("cls");
    xy(56,30);
    printf("Created by Pantho(1907075)\n");

    xy(15,8);
    printf("|||| ||||||||||||||||||||||||||||||||||||||| ||||");
    xy(15,9);
    printf("||||                                         ||||");
    xy(15,10);
    printf("||||     Log in to Admin Panel               ||||");
    xy(15,11);
    printf("||||                                         ||||");
    xy(15,12);
    printf("|||| ||||||||||||||||||||||||||||||||||||||| ||||");


    fflush(stdin);
    xy(19,15);
    printf("Enter Your Username: ");
    char n[10];
    login:
    xy(40,15);
    gets(n);
    if(strcmp(n,adminUsername)==0)
    {
        xy(30,6);
        printf("                  ");
        xy(19,16);
        printf("Enter Your Password: ");
        char p[5];
        pass:
        xy(40,16);
        if(strcmp(gets(p),adminPassword)==0)
        {
            adminPanel();
        }else
        {
            xy(30,6);
            printf("Invalid Password !");
            goto pass;
        }

    }
    else
    {
        xy(30,6);
        printf("Invalid Username !");

        goto login;
    }


}


// function for admin panel
void adminPanel(){
    system("cls");
    xy(56,30);
    printf("Created by Pantho(1907075)\n");

    xy(15,8);
    printf("|||| ||||||||||||||||||||||||||||||||||||||| ||||");
    xy(15,9);
    printf("||||                                         ||||");
    xy(15,10);
    printf("||||              Admin Panel                ||||");
    xy(15,11);
    printf("||||                                         ||||");
    xy(15,12);
    printf("|||| ||||||||||||||||||||||||||||||||||||||| ||||");


    xy(19,15);
    printf("%s (ADMIN*)",adminUsername);
    xy(24,17);
    printf("1. Assign Teacher");
    xy(24,18);
    printf("2. Update Teacher Information");
    xy(24,19);
    printf("3. Add Student");
    xy(24,20);
    printf("4. Update Student Information");
    xy(24,21);
    printf("5. Assigning Course to a Teacher");
    xy(24,22);
    printf("6. Back to Panel menu");
    xy(24,23);
    printf("7. Exit");


    xy(19,25);
    printf("Enter a number according what you want to do:  ");
    int d;
    scanf("%d",&d);
    switch(d){
        case 1:
            assignTeacher();
            break;
        case 2:
            updateTeacherInfo();
            break;

        case 3:
            addStud();
            break;
        case 4:
            updateStudInfo();
            break;
        case 5:
            assignCourse();
            break;
        case 6:
            main();
            break;
        case 7:
            exit(1);
            break;
        default:
            xy(28,27);
            printf("Invalid Choice.\n\n");

    }
}

// function for assigning teacher through admin
void assignTeacher()
{
    FILE *t;
    t= fopen("teacher.txt","ab+");
    system("cls");

    xy(56,30);
    printf("Created by Pantho(1907075)\n");


    fflush(stdin);
    teacher newTec;
    xy(15,8);
    printf("Assigning a teacher: ");
    xy(20,9);
    printf("Enter the name of teacher: ");
    gets(newTec.name);
    xy(20,10);
    printf("Set the password for %s(not more than 8 character): ",newTec.name);
    gets(newTec.pass);
    xy(20,11);
    printf("Put the mobile number of %s: ",newTec.name);
    gets(newTec.mobile);

    fwrite(&newTec,sizeof(newTec),1,t);

    fclose(t);
    xy(20,12);
    printf("To add another teacher press \'a\' and press any key to continue");
    if(getch()=='a'){
        assignTeacher();

    }


    adminPanel();

}

// function for update the information of a teacher through admin
void updateTeacherInfo()
{
    xy(56,30);
    printf("Created by Pantho(1907075)\n");

    fflush(stdin);
    system("cls");
    FILE *t;
    t= fopen("teacher.txt","ab+");

    teacher pTech;
    xy(10,5);
    printf("S.No\tName of Teacher\t\tPassword\tMobile Number");
    xy(10,6);
    printf("----------------------------------------------------------");

    int i=1,j=8;
    while(fread(&pTech,sizeof(pTech),1,t) == 1){
        xy(10,j);
        printf("%d\t%s\t\t\t%s\t\t%s",i,pTech.name,pTech.pass,pTech.mobile);
        i++;
        j++;
    }

    fflush(stdin);
    xy(15,++j);
    printf("Update the information of (name of teacher) : ");
    char cTech[20];
    gets(cTech);

    teacher qTech;

    FILE* tmp;
    tmp=fopen("temp.txt","ab+");
    rewind(t);
    fflush(stdin);
    int fd=1;
    while(fread(&qTech,sizeof(qTech),1,t) == 1){
        if(strcmp(qTech.name,cTech)==0){

            system("cls");
            xy(15,8);
            printf("Updating Information of %s: ",cTech);
            xy(20,9);
            printf("Enter the new name of teacher: "); fflush(stdin);
            gets(qTech.name);
            xy(20,10);
            printf("Set the password for %s(not more than 8 character): ",qTech.name); fflush(stdin);
            gets(qTech.pass);
            xy(20,11);
            printf("Put the mobile number of %s: ",qTech.name); fflush(stdin);
            gets(qTech.mobile);

            fd=0;
            fwrite(&qTech,sizeof(qTech),1,tmp);
        }
        else{
            fwrite(&qTech,sizeof(qTech),1,tmp);
        }
    }
    fclose(t);
    fclose(tmp);

    remove("teacher.txt");
    rename("temp.txt","teacher.txt");
    fflush(stdin);
    if(fd){
        xy(15,j+=3);
        printf("Not found\n\n");

    }

    xy(20,++j);
    printf("press \'a\' to go back to admin panel or any key to stay here.");
    if(getch()=='a'){
        system("cls");
        adminPanel();
    }else{
        updateTeacherInfo();
    }

}

// function for add student through admin
void addStud()
{
    FILE *s;
    s= fopen("student.txt","ab+");
    system("cls");

    xy(56,30);
    printf("Created by Pantho(1907075)\n");

    fflush(stdin);
    student newTec;
    xy(15,8);
    printf("Assigning a student: ");
    xy(20,9);
    printf("Enter the name of student: ");
    gets(newTec.name);
    xy(20,10);
    printf("Enter the roll of %s: ",newTec.name);
    gets(newTec.roll);
    xy(20,11);
    printf("Set the password for %s(not more than 8 character): ",newTec.name);
    gets(newTec.pass);
    xy(20,12);
    printf("Put the mobile number of %s: ",newTec.name);
    gets(newTec.mobile);

    fwrite(&newTec,sizeof(newTec),1,s);
    fclose(s);

    xy(20,13);
    printf("To add another student press \'a\' and press any key to continue...");
    if(getch()=='a'){
        addStud();
    }

    adminPanel();
}

// function for update the information of a student through admin
void updateStudInfo()
{
    fflush(stdin);
    system("cls");

    xy(56,30);
    printf("Created by Pantho(1907075)\n");

    FILE *s;
    s= fopen("student.txt","ab+");

    student pStud;
    xy(10,5);
    printf("S.No\t\tName of student\t\tRoll\t\tPassword\t\tMobile Number");
    xy(10,6);
    printf("--------------------------------------------------------------------------------------------------");

    int i=1,j=8;
    while(fread(&pStud,sizeof(pStud),1,s) == 1){
        xy(10,j);
        printf("%d\t\t%s\t\t\t%s\t\t%s\t\t\t%s",i,pStud.name,pStud.roll,pStud.pass,pStud.mobile);
        i++;
        j++;
    }

    fflush(stdin);
    xy(15,++j);
    printf("Update the information of (name of student) : ");
    char cStud[20];
    gets(cStud);

    student qStud;

    FILE* tmp;
    tmp=fopen("temp.txt","ab+");
    rewind(s);
    fflush(stdin);

    int fd=1;
    while(fread(&qStud,sizeof(qStud),1,s) == 1){
        if(strcmp(qStud.name,cStud)==0){

            system("cls");
            xy(15,8);
            printf("Updating Information of %s: ",cStud);
            xy(20,9);
            printf("Enter the new name of student: "); fflush(stdin);
            gets(qStud.name);
            xy(20,10);
            printf("Enter the roll of %s: ",qStud.name); fflush(stdin);
            gets(qStud.roll);
            xy(20,11);
            printf("Set the password for %s(not more than 8 character): ",qStud.name); fflush(stdin);
            gets(qStud.pass);
            xy(20,12);
            printf("Put the mobile number of %s: ",qStud.name); fflush(stdin);
            gets(qStud.mobile);

            fd=0;
            fwrite(&qStud,sizeof(qStud),1,tmp);
        }
        else{
            fwrite(&qStud,sizeof(qStud),1,tmp);
        }
    }
    fclose(s);
    fclose(tmp);

    remove("student.txt");
    rename("temp.txt","student.txt");
    fflush(stdin);
    if(fd){
        xy(15,j+=3);
        printf("Not found\n\n");

    }

    xy(20,j+=3);
    printf("press \'a\' to go back to admin panel or any key to stay here.");
    if(getch()=='a'){
        system("cls");
        adminPanel();
    }else{
        updateStudInfo();
    }
}



// function for assigning course for a teacher through admin
void assignCourse()
{
    system("cls");

    xy(56,30);
    printf("Created by Pantho(1907075)\n");

    FILE *t,*s,*c;

    fflush(stdin);

    teacher tec;
    student stud;
    course crs;

    xy(20,15);
    printf("Enter the name of teacher:");

    t=fopen("teacher.txt","rb");
    int ok=1;
    teah:

    xy(47,15);

    fflush(stdin);
    rewind(t);
    gets(crs.teacher);

    while(fread(&tec,sizeof(tec),1,t)){

        if(strcmp(tec.name,crs.teacher)==0){
            ok=0;
        }
    }
    if(ok){
        goto teah;
    }
    fclose(t);


    s=fopen("student.txt","ab+");
    xy(20,16);
    printf("Enter the name of student:");

    ok=1;
    stun:
    xy(47,16);
    fflush(stdin);
    rewind(s);
    gets(crs.student);
    while(fread(&stud,sizeof(stud),1,s)){
        if(strcmp(stud.name,crs.student)==0){
            ok=0;
        }
    }
    if(ok){
        goto stun;
    }
    fclose(s);


    c=fopen("course.txt","ab+");
    xy(20,17);
    printf("Enter the course name:");
    gets(crs.c_name);



    fwrite(&crs,sizeof(crs),1,c);

    fclose(c);
    xy(20,20);
    printf("To assign another course press \'a\' and press any key to go back:");
    if(getch()=='a'){
        assignCourse();
    }
    adminPanel();

}



// function for loging in to teacher panel
void teachersPanellogin()
{
    system("cls");

    xy(56,30);
    printf("Created by Pantho(1907075)\n");

    fflush(stdin);
    xy(15,8);
    printf("|||| ||||||||||||||||||||||||||||||||||||||| ||||");
    xy(15,9);
    printf("||||                                         ||||");
    xy(15,10);
    printf("||||     Log in to Teachers Panel            ||||");
    xy(15,11);
    printf("||||                                         ||||");
    xy(15,12);
    printf("|||| ||||||||||||||||||||||||||||||||||||||| ||||");


    char tname[20] ,tpass[8];
    login:
    fflush(stdin);
    xy(19,15);
    printf("Enter Your Username: ");
    xy(40,15);
    gets(tname);


    FILE *f;
    f=fopen("teacher.txt","ab+");
    teacher pTech;
    int ok=1;
    rewind(f);
    fflush(stdin);
    while(fread(&pTech,sizeof(pTech),1,f)==1){
             //puts(pTech.name);
            if(!strcmp(tname, pTech.name))
            {
                xy(30,6);
                printf("                  ");
                xy(19,16);
                printf("Enter Your Password: ");
                char p[5];
                pass:
                xy(40,16);
                if(strcmp(gets(p),pTech.pass)==0)
                {
                    ok=0;
                    strcpy(tcName,pTech.name);
                    teacherPanel();
                }else
                {
                    xy(30,6);
                    printf("Invalid Password !");
                    goto pass;
                }

            }
    }
    if(ok){
        xy(30,6);
        printf("Invalid Username !");
        goto login;
    }


}
// function related to teacher panel
void teacherPanel()
{

    if(strlen(tcName)==0){
        teachersPanellogin();
    }
    system("cls");

    xy(56,30);
    printf("Created by Pantho(1907075)\n");


    xy(15,8);
    printf("|||| ||||||||||||||||||||||||||||||||||||||| ||||");
    xy(15,9);
    printf("||||                                         ||||");
    xy(15,10);
    printf("||||              Teachers Panel             ||||");
    xy(15,11);
    printf("||||                                         ||||");
    xy(15,12);
    printf("|||| ||||||||||||||||||||||||||||||||||||||| ||||");


    xy(19,15);
    printf("%s(TEACHER)",tcName);
    xy(24,17);
    printf("1. Provide class test mark");
    xy(24,18);
    printf("2. Find student using name");
    xy(24,19);
    printf("3. No of student in a particular course");
    xy(24,20);
    printf("4. Back to panel menu");
    xy(24,21);
    printf("5. Exit");
    xy(19,25);
    printf("Enter a number according what you want to do:  ");
    int d;
    scanf("%d",&d);
    switch(d){
        case 1:
            provideCTm();
            break;
        case 2:
            findStud();
            break;

        case 3:
            countStud();
            break;
        case 4:
            main();
            break;
        case 5:
            exit(1);
            break;
        default:
            xy(28,27);
            printf("Invalid Choice.\n\n");

    }

}





// providing ct mark to particular student through teacher
void provideCTm()
{
    if(strlen(tcName)==0){
        teachersPanellogin();
    }

    system("cls");

    xy(56,30);
    printf("Created by Pantho(1907075)\n");




    FILE *c;
    c=fopen("course.txt","rb");
    course crs;

    char course[20][30]={""};
    int n=0;
    rewind(c);
    while(fread(&crs,sizeof(crs),1,c)){
        if(strcmp(crs.teacher,tcName)==0){
            strcpy(course[n], crs.c_name);
            n++;
        }
    }
    fclose(c);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
           if (strcmp(course[i], course[j]) == 0) {
                int d=j;
                while(d<n){
                  strcpy(course[d], course[d + 1]);
                  d++;
                }
                --j;
                --n;
            }
        }
    }



    fflush(stdin);
    int y;
    xy(20,12);
    printf("For which course you would like to give CT marks ?\n");
    for(int i=0;i<n;i++){
        xy(25,13+i);
        printf("%d. %s\n",i+1,course[i]);
        y=16+i;
    }

    xy(20,y);
    printf("Enter the serial number of the course : ");
    int s;
    serCourse:
    fflush(stdin);
    xy(61,y);
    scanf("%d",&s);
    if(s>n){
        xy(27,7);
        printf("Invalid input!");
        goto  serCourse ;
    }

    char tmpCrs[30]="", filename[34]="" ;

    strcpy(tmpCrs,course[s-1]);
    strcpy(filename,tmpCrs);
    strcat(filename,"-");
    strcat(filename,tcName);
    strcat(filename,".txt");

    result newRslt,chRslt;
    strcpy(newRslt.teacher,tcName);


    system("cls");


    FILE *cr,*resu;
    cr=fopen("course.txt","rb");
    resu=fopen(filename,"wb+");
    y=12;

    while(fread(&crs,sizeof(crs),1,cr)==1){
            int a = (strcmp(crs.c_name,tmpCrs)==0);
            int b = (strcmp(crs.teacher,tcName)==0);

            if(a&&b){
                    fflush(stdin);
                    xy(20,y);
                    printf("Enter the number for %s:  ",crs.student);
                    scanf("%s",&newRslt.mark);
                    strcpy(newRslt.student,crs.student);

                    fwrite(&newRslt,sizeof(newRslt),1,resu);
            }
            y++;
    }
    fclose(cr);
    fclose(resu);

    xy(20,y+=3);
    printf("To set the CT mark of another course press \'a\' and press any key to go back:");
    if(getch()=='a'){
        provideCTm();
    }
    teacherPanel();

}



// providing ct mark to particular student through teacher
void findStud()
{
    if(strlen(tcName)==0){
        teachersPanellogin();
    }

    system("cls");

    xy(56,30);
    printf("Created by Pantho(1907075)\n");





    FILE *c;
    c=fopen("course.txt","rb");
    course crs;

    char course[20][30]={""};
    int n=0;
    rewind(c);
    while(fread(&crs,sizeof(crs),1,c)){
        if(strcmp(crs.teacher,tcName)==0){
            strcpy(course[n], crs.c_name);
            n++;
        }
    }
    fclose(c);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp((course[i]),(course[j]))==0){
                int d=j;
                while(d<n){
                  strcpy((course[d]),(course[d+1]));
                  d++;
                }
                --j;
                --n;
            }
        }
    }



    fflush(stdin);
    int y;
    xy(20,12);
    printf("From which course you want to find student ? \n");
    for(int i=0;i<n;i++){
        xy(25,13+i);
        printf("%d. %s\n",i+1,course[i]);
        y=16+i;
    }

    xy(20,y);
    printf("Enter the serial number of the course : ");
    int s;
    serCourse:
    fflush(stdin);
    xy(61,y);
    scanf("%d",&s);
    if(s>n){
        xy(27,7);
        printf("Invalid input!");
        goto  serCourse ;
    }

    char tmpCrs[30]="";
    strcpy(tmpCrs,(course[s-1]));

    system("cls");

    FILE *cr;
    cr=fopen("course.txt","rb");
    char allstd[100][20];

    xy(20,11);
    printf("All your student for %s course",tmpCrs);
    y=12;
    int i=1;
    while(fread(&crs,sizeof(crs),1,cr)==1){
            int a = (strcmp(crs.c_name,tmpCrs)==0);
            int b = (strcmp(crs.teacher,tcName)==0);
            if(a&&b){
                fflush(stdin);
                xy(20,y);
                printf("%d \t %s",i,crs.student);
                strcpy((allstd[i-1]),crs.student);
                y++;;
                i++;
            }


    }

    againInput:
    xy(20,y+=3);
    int p;
    printf("Press the serial number for the information of student :");
    scanf("%d",&p);
    if(p>i){
        xy(25,8);
        printf("Invalid input");
        y-=3;
        goto againInput;
    }

    char tmpStud[20]="" ;
    strcpy(tmpStud,allstd[p-1]);





    FILE *std;
    std=fopen("student.txt","rb");
    student ts;

    while(fread(&ts,sizeof(ts),1,std)==1)
    {
        if(strcmp(ts.name,tmpStud)==0)
        {
            xy(25,y+=2);
            printf("Student's name : %s",ts.name);
            xy(25,++y);
            printf("Student's roll : %s",ts.roll);
            xy(25,++y);
            printf("Student's mobileNo : %s",ts.mobile);
        }
    }

    fclose(std);



    xy(20,y+=3);
    printf("To find another student press \'a\' and press any key to go back:");
    if(getch()=='a'){
        findStud();
    }
    teacherPanel();


}


// counting the number of student for a particular course by teacher
void countStud()
{
    if(strlen(tcName)==0){
        teachersPanellogin();
    }

    system("cls");

    xy(56,30);
    printf("Created by Pantho(1907075)\n");




    FILE *c;
    c=fopen("course.txt","rb");
    course crs;

    char course[20][30]={""};
    int n=0;
    rewind(c);
    while(fread(&crs,sizeof(crs),1,c)){
        if(strcmp(crs.teacher,tcName)==0){
            strcpy((course[n]),crs.c_name);
            n++;
        }
    }
    fclose(c);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp((course[i]),(course[j]))==0){
                int d=j;
                while(d<n){
                  strcpy((course[d]),(course[d+1]));
                  d++;
                }
                --j;
                --n;
            }
        }
    }



    fflush(stdin);
    int y;
    xy(20,12);
    printf("For which course you would like to Count Students ?\n");
    for(int i=0;i<n;i++){
        xy(25,13+i);
        printf("%d. %s\n",i+1,course[i]);
        y=16+i;
    }

    xy(20,y);
    printf("Enter the serial number of the course : ");
    int s;
    serCourse:
    fflush(stdin);
    xy(61,y);
    scanf("%d",&s);
    if(s>n){
        xy(27,7);
        printf("Invalid input!");
        goto  serCourse ;
    }

    char tmpCrs[30]="";

    strcpy(tmpCrs,(course[s-1]));

    FILE *cr;
    cr=fopen("course.txt","rb");

    int con=0;
    while(fread(&crs,sizeof(crs),1,cr)==1){
            int a = (strcmp(crs.c_name,tmpCrs)==0);
            int b = (strcmp(crs.teacher,tcName)==0);
            if(a&&b){
                con++;
            }
    }

    xy(20,y+=2);
    printf("Total number of student in %s course : %d",tmpCrs,con);

    xy(20,y+=3);
    printf("To count student of another course press \'a\' and press any key to go back:");
    if(getch()=='a'){
        countStud();
    }
    teacherPanel();

}


// function for loging in to student panel
void studentsPanellogin()
{
    system("cls");
    fflush(stdin);
    xy(15,8);
    printf("|||| ||||||||||||||||||||||||||||||||||||||| ||||");
    xy(15,9);
    printf("||||                                         ||||");
    xy(15,10);
    printf("||||     Log in to Students Panel            ||||");
    xy(15,11);
    printf("||||                                         ||||");
    xy(15,12);
    printf("|||| ||||||||||||||||||||||||||||||||||||||| ||||");


    char tname[20] ,tpass[8];
    login:
    fflush(stdin);
    xy(19,15);
    printf("Enter Your Username: ");
    xy(40,15);
    gets(tname);

    int ok=1;
    FILE *f;
    f=fopen("student.txt","ab+");
    student pTech;
    while(fread(&pTech,sizeof(pTech),1,f)==1){

             if(strcmp(tname ,pTech.name)==0)
            {
                xy(30,6);
                printf("                  ");
                xy(19,16);
                printf("Enter Your Password: ");
                char p[5];
                pass:
                xy(40,16);
                if(strcmp(gets(p),pTech.pass)==0)
                {
                    ok=0;
                    strcpy(stName,tname);
                    studentPanel();
                }else
                {
                    xy(30,6);
                    printf("Invalid Password !");
                    goto pass;
                }

            }


    }
    if(ok){
        xy(30,6);
        printf("Invalid Username !");
        goto login;
    }
}

// function related to student panel
void studentPanel()
{
     if(strlen(stName)==0){
        studentsPanellogin();
    }

    system("cls");

    xy(56,30);
    printf("Created by Pantho(1907075)\n");


    xy(15,6);
    printf(" Enter \"1221\" to go back and \"404\" to exit. ");
    xy(15,8);
    printf("|||| ||||||||||||||||||||||||||||||||||||||| ||||");
    xy(15,9);
    printf("||||                                         ||||");
    xy(15,10);
    printf("||||              Students Panel             ||||");
    xy(15,11);
    printf("||||                                         ||||");
    xy(15,12);
    printf("|||| ||||||||||||||||||||||||||||||||||||||| ||||");


    xy(19,15);
    printf("%s(STUDENT)",stName);
    xy(24,17);
    printf("View CT mark for :");



    FILE *c;
    c=fopen("course.txt","rb");
    course crs;

    char course[20][30]={""};
    int n=0;
    rewind(c);
    while(fread(&crs,sizeof(crs),1,c)){
        if(strcmp(crs.student,stName)==0){
            strcpy((course[n]),crs.c_name);
            n++;
        }
    }
    fclose(c);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp((course[i]),(course[j]))==0){
                int d=j;
                while(d<n){
                  strcpy((course[d]),(course[d+1]));
                  d++;
                }
                --j;
                --n;
            }
        }
    }


    fflush(stdin);
    int y;
    for(int i=0;i<n;i++){
        xy(29,19+i);
        printf("%d. %s\n",i+1,course[i]);
        y=21+i;
    }

    xy(24,y);
    printf("Enter the serial number of the course : ");
    int s;
    serCourse:
    fflush(stdin);
    xy(71,y);
    scanf("%d",&s);
    if(s==1221){
        main();
    }
    if(s==404){
        exit(1);
    }
    if(s>n){
        xy(12,12);
        printf("Invalid input!");
        goto  serCourse ;
    }


    system("cls");

    char tmpCrs[30]="";

    strcpy(tmpCrs,(course[s-1]));

    y=15;
    n=0;
    FILE *ca;
    ca=fopen("course.txt","ab+");

    char trs[10][20]={""};
    while(fread(&crs,sizeof(crs),1,ca)==1)
    {
        int a=(strcmp(crs.c_name,tmpCrs)==0);
        int b=(strcmp(crs.student,stName)==0);
        if(a && b)
        {
            strcpy(trs[n],crs.teacher);
            n++;
        }
    }
    fclose(ca);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp((trs[i]),(trs[j]))==0){
                int d=j;
                while(d<n){
                  strcpy((trs[d]),(trs[d+1]));
                  d++;
                }
                --j;
                --n;
            }
        }
    }

    int se=1;
    for(int i=0; i<n;i++){

        char sir[30]="";
        strcpy(sir,tmpCrs);
        strcat(sir,"-");
        strcat(sir,trs[i]);
        strcat(sir,".txt");

        FILE *resul;
        resul=fopen(sir,"rb+");
        result mark;
        while(fread(&mark,sizeof(mark),1,resul)==1){
            if(strcmp(mark.student,stName)==0){
                xy(30,y++);
                printf("%d. \t %s(%s) \t %s",se++,mark.teacher,tmpCrs,mark.mark);
            }
        }
    }

    xy(25,y+=3);
    printf("Press any key to go back...");
    getch();
    studentPanel();

}


//function for changing the co-ordinated of cursor
void xy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
