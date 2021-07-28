#include <stdio.h>
#include <string.h>

char *in_file = "infile.txt";

int main() {

	FILE *infile;          
	char line[100];         

	int position;           

	infile = fopen(in_file, "r");
	if (infile == NULL) {
		fprintf(stderr, "Error opening %s\n", in_file);
		return(8);
	}

	position = 0;
	while (fgets(line, sizeof(line), infile)) {
		if (line[0] == '\n') {
			printf("\n");
			position = 0;
			continue;
		}

		line[strlen(line) - 1] = '\0';          

		switch (position) {
			case 1:
			case 2:
			case 5:
			case 6:
				printf("%s\n", line);      
				break;
			case 0:
			case 4:
				printf("%s ", line);       
				break;
			case 3:
				printf("%s, ", line);      
				break;
			default:
				printf("Error unknown field\n");
		}

		++position;

	}

	fclose(infile);

	getch();
	return(0);
}
