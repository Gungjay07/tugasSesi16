#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

void addStudent(char campusNames[MAX_STUDENTS], char names[MAX_STUDENTS][50], int years[MAX_STUDENTS], char majors[MAX_STUDENTS][50], int *studentCount, char campusName);
void transferStudent(char campusNames[MAX_STUDENTS], char names[MAX_STUDENTS][50], int years[MAX_STUDENTS], char majors[MAX_STUDENTS][50], int studentCount);
void listStudents(char campusNames[MAX_STUDENTS], char names[MAX_STUDENTS][50], int years[MAX_STUDENTS], char majors[MAX_STUDENTS][50], int studentCount, char campusName);

int main()
{
    char campusNames[MAX_STUDENTS];
    char names[MAX_STUDENTS][50];
    int years[MAX_STUDENTS];
    char jurusan[MAX_STUDENTS][50];
    int studentCount = 0;
    int choice;

    do
    {
        printf("1. Add Student To Campus A\n");
        printf("2. Add Student To Campus B\n");
        printf("3. Transfer Student\n");
        printf("4. List Student Campus A\n");
        printf("5. List Student Campus B\n");
        printf("6. EXIT\n");
        printf("Pilihan menu : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent(campusNames, names, years, jurusan, &studentCount, 'A');
            break;
        case 2:
            addStudent(campusNames, names, years, jurusan, &studentCount, 'B');
            break;
        case 3:
            transferStudent(campusNames, names, years, jurusan, studentCount);
            break;
        case 4:
            listStudents(campusNames, names, years, jurusan, studentCount, 'A');
            break;
        case 5:
            listStudents(campusNames, names, years, jurusan, studentCount, 'B');
            break;
        case 6:
            printf("Exit\n");
            break;
        default:
            printf("Salah menu.\n");
        }
    } while (choice != 6);

    return 0;
}

void addStudent(char campusNames[MAX_STUDENTS], char names[MAX_STUDENTS][50], int years[MAX_STUDENTS], char jurusan[MAX_STUDENTS][50], int *studentCount, char campusName)
{

    printf("Masukkan nama : ");
    scanf("%s", names[*studentCount]);
    printf("Masukkan tahun ajaran : ");
    scanf("%d", &years[*studentCount]);
    printf("Masukkan jurusan : ");
    scanf("%s", jurusan[*studentCount]);

    campusNames[*studentCount] = campusName;
    (*studentCount)++;

    printf("Mahasiswa berhasil ditambahkan ke Campus %c.\n", campusName);
}

void transferStudent(char campusNames[MAX_STUDENTS], char names[MAX_STUDENTS][50], int years[MAX_STUDENTS], char jurusan[MAX_STUDENTS][50], int studentCount)
{
    char studentName[50];
    printf("Masukan nama mahasiswa untuk di pindahkan : ");
    scanf("%s", studentName);

    int index = -1;
    for (int i = 0; i < studentCount; ++i)
    {
        if (strcmp(names[i], studentName) == 0)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        char targetCampus;
        do
        {
            printf("Masukkan campus (A/B): ");
            scanf(" %c", &targetCampus);
        } while (targetCampus != 'A' && targetCampus != 'B');

        campusNames[index] = targetCampus;
    }
    else
    {
        printf("Mahasiswa tidak ditemukan.\n");
    }
}

void listStudents(char campusNames[MAX_STUDENTS], char names[MAX_STUDENTS][50], int years[MAX_STUDENTS], char jurusan[MAX_STUDENTS][50], int studentCount, char campusName)
{
    printf("Mahasiswa di campus %c:\n", campusName);
    for (int i = 0; i < studentCount; ++i)
    {
        if (campusNames[i] == campusName)
        {
            printf("Name: %s, Tahun: %d, jurusan: %s\n", names[i], years[i], jurusan[i]);
        }
    }
}