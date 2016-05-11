#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main( int argc, char ** args ) {
	int len, i, max;

	char * line1, * line2, * line3, * line4;
	size_t buffer = 250;

	int hist[buffer];

	for(i = 0; i < buffer; i++) {
		hist[i] = 0;
	}

	line1 = (char *) malloc(buffer + 1);
	line2 = (char *) malloc(buffer + 1);
	line3 = (char *) malloc(buffer + 1);
	line4 = (char *) malloc(buffer + 1);
	
	while( !feof( stdin ) ) {
		getline( &line1, &buffer, stdin );
		getline( &line2, &buffer, stdin );
		getline( &line3, &buffer, stdin );
		getline( &line4, &buffer, stdin );
		
		len = strlen( line2 );
		len--; // remove endline character
		hist[len]++;
	}

	max = 0;
	for(i = 0; i < buffer; i++) {
		if(hist[i] > 0) max = i;
	}

	for(i = 0; i < max + 1; i++) {
		printf("%d\t%d\n", i, hist[i]);
	}

	free( line1 );
	free( line2 );
	free( line3 );
	free( line4 );
}
