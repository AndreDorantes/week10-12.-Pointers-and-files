#include <stdio.h>

const char *in_filename = "infile.txt";
const char *out_filename = "outfile.txt";

int main() {

	FILE *infile;           
	FILE *outfile;          

	int c;              

	infile = fopen(in_filename, "r");
	if (infile == NULL) {
		printf(stderr, "Error on opening %s\n", in_filename);
		return(8);
	}

	outfile = fopen(out_filename, "w+");
	if (outfile == NULL) {
		printf(stderr, "Error on opening %s\n", out_filename);
		return(8);
	}

	while (1) {

		c = fgetc(infile);

		if (c == EOF) {
			break;
		}

		if (c == '\t') {
			fputc(' ', outfile);
			fputc(' ', outfile);
			fputc(' ', outfile);
			fputc(' ', outfile);
		} else {
			fputc(c, outfile);
		}
	}

	fclose(infile);
	fclose(outfile);

	getch();
	return(0);
}

