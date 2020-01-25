#include <stdio.h>
#define WIDTH 1000
#define HEIGHT 1000
#define MAX_GRAY 255


int main()
{
    unsigned char image[WIDTH][HEIGHT];

	FILE* pgmimg;
	pgmimg = fopen("Black_Gradient_For_Point_a.pgm", "wb");

	// Writing Magic Number to the File
	fprintf(pgmimg, "P2\n");

	// Writing Width and Height
	fprintf(pgmimg, "%d %d\n", WIDTH, HEIGHT);

	// Writing the maximum gray value
	fprintf(pgmimg, "%d\n", MAX_GRAY);

	for (int i = 0; i < WIDTH; i++)
    {
        int value = i * MAX_GRAY / WIDTH;
        printf("(%d) %d\n", i, value);

        for (int j = 0; j < HEIGHT; j++)
		{
			image[i][j] = value;
		}
    }

    for (int j = 0; j < HEIGHT; j++)
    {
        for (int i = 0; i < WIDTH; i++)
		 {
			// Writing the gray values in the 2D array to the file
			fprintf(pgmimg, "%d ", image[i][j]);
		}
		fprintf(pgmimg, "\n");
	}
	fclose(pgmimg);

	return(0);
}
