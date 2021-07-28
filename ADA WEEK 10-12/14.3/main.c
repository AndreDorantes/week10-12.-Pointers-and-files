#include <stdio.h>

const char *in_filename = "infile.txt";
const char *out_filename = "outfile.txt";
const char *out_3s_filename = "out3file.txt";

int main() {

	FILE *infile;           
	FILE *outfile;          
	FILE *out3file;         

	char line[100];        
	int number;             

	infile = fopen(in_filename, "r");
	if (infile == NULL) {
		fprintf(stderr, "Error opening %s for reading\n", in_filename);
		return(8);
	}

	outfile = fopen(out_filename, "w+");
	if (outfile == NULL) {
		fprintf(stderr, "Error opening %s for writing\n", out_filename);
		fclose(infile);
		return(8);
	}

	out3file = fopen(out_3s_filename, "w+");
	if (out3file == NULL) {
		fprintf(stderr, "Error opening %s for writing\n", out_3s_filename);
		fclose(infile);
		fclose(outfile);
		return(8);
	}

	while (fgets(line, sizeof(line), infile)) {
		sscanf(line, "%d", &number);
		if ((number % 3) == 0) {
			fprintf(out3file, "%d\n", number);
		} else {
			fprintf(outfile, "%d\n", number);
		}
	}

	fclose(infile);
	fclose(outfile);
	fclose(out3file);

	getch();
	return(0);
}
