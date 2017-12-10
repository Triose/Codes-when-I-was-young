#include <stdio.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
    char ch;
    char * optValue;
    int i;
    while((ch = getopt(argc, argv, "ae:")) != EOF) 
	switch(ch) {
	    case 'a':
		printf("Argument name is 'A'\n");
		break;
	    case 'e':
		printf("Argument name is 'E'\n");
		optValue = optarg;
		printf("The value of this argument is %s\n", optValue);
		break;
	    default:
		fprintf(stderr, "Unknown option\n");
		return 1;
	}
    argc -= optind;
    argv += optind;
    puts("Argument as followed:\n");
    for(i = 0; i < argc; i++) {
	puts(*(argv + i));
    }
    printf("optind = %i\n", optind);
    return 0;
}
