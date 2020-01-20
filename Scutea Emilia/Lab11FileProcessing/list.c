item *readItem(item *a)
{
    FILE *f;
    f=fopen("list.txt","rw");
    char * strbuf = (char*) malloc(sizeof(char)*MAX_LENGTH);

      while(fgets(strbuf, MAX_LENGTH, f) != NULL)
            puts(strbuf);
}
