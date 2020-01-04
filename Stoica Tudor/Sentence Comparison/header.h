#define MAXIMUM_NR_OF_SENTENCES 105
#define MAXIMUM_LENGTH_OF_SENTENCE 55
#define NR_OF_ALPHABET_LETTERS 26

typedef struct{

    int letter;
    int occurences;

}lettersAndOccurences;

char ** initSentences(char **s);
int readSentences(char **s,FILE *ff,int nr);
lettersAndOccurences* initFr(lettersAndOccurences *fr);
void findlettersOccurences(char **s,int nr,lettersAndOccurences *fr);
void sortOccurences(lettersAndOccurences *fr);
void outputOccurences(lettersAndOccurences *fr,FILE *out);
