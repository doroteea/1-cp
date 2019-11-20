typedef struct {
    int year;
    int month;
    int day;
} date;

typedef struct {
    char * name;
    date dateOfBirth;
    char * address;
} student;

student * readStudents(int n);
