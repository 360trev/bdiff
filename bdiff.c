/* Simple binary diff tool with ascii output of diff's
 
 1. load <src1> & load <src2> files into memory...
 2.  do processing on them
 3. free buffers & exit

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the
   "Software"), to deal in the Software without restriction, including
   without limitation the rights to use, copy, modify, merge, publish,
   distribute, sublicense, and/or sell copies of the Software, and to
   permit persons to whom the Software is furnished to do so, subject to
   the following conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
   AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
   OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
   IN THE SOFTWARE.
*/
#include "load_file.h"

int main(int argc, char *argv[])
{
  size_t src1len=0,src2len=0,i;
	unsigned char *psrc1Buf=0,*psrc2Buf=0;
	unsigned chA,chB;
	int count=0;

		printf("binary difference tool - 0.1\n");
		printf("Last Built: %s, Time: %s\n\n",__DATE__, __TIME__);

		/* check src1 and src2 file specified */
		if (argc < 2){
			fprintf(stderr, "usage: %s <src1> <src2>\n",argv[0]);
			return 0;
		}

		/* load first file */
		psrc1Buf = load_file((char *)argv[1],&src1len);
		if(psrc1Buf == 0) { return 0; }

		/* load second file */
		psrc2Buf = load_file((char *)argv[2],&src2len);
		if(psrc1Buf == 0) { free(psrc1Buf); return 0; }

    printf("\n");

		if(src1len == src2len) {
			// walk all bytes in files comparing each one...
			for(i=0;i<src1len;i++) 
			{
				chA = psrc1Buf[i];		// byte from first file
				chB = psrc2Buf[i];		// byte from second file
				// is this byte identical?
				if(chA != chB) { 
					printf("0x%-8.8x (%8d): %2.2x -> %2.2x\n",i,i,chA,chB); 
					count++; 	// keep count of number of differences
				}
			}
			printf("\nTotal byte differences: %d (%x) bytes\n\n",count,count);
		} 
		else 
		{
			printf("Files to compare must be same byte size!\n");
		}

	/* free src2 file buffer */
	if(psrc2Buf != 0) { free(psrc2Buf);	}
	/* free src1 file buffer */
	if(psrc1Buf != 0){	free(psrc1Buf);	}

	printf("\nþ All Done...\n"); 
	return 0; 
}
