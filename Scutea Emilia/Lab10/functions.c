student *readStudents(int n)
{
    student *a=(student*)malloc(sizeof(student)*30);
    for(int i=0; i<n; i++)
    {
        getchar();
        printf("Please insert the name of the student:\n");
        gets(a[i].name);
        printf("Please insert the address of the student:\n");
        gets(a[i].address);
        printf("Please insert the date of birth of the student:\n");
        scanf("%d %d %d",&a[i].date.day,&a[i].date.month,&a[i].date.year);
    }
    return a;
}

void printStudents(student *a,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%s %s %d %d %d \n",a[i].name,a[i].address,a[i].date.day,a[i].date.month,a[i].date.year);
    }
}

student lexOrder(student *a,int n)
{
   int ok=0;
   student *b=(student*)malloc(sizeof(student)*30);
    while(ok==0)
    {
        ok=1;
        for(int i=0; i<n-1; i++)
            if(strcmp(a[i].name,a[i+1].name)>0)
            {
                b[i]=a[i];
                a[i]=a[i+1];
                a[i+1]=b[i];
                ok=0;
            }
    }
}
