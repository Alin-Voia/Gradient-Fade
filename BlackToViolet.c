#include <stdio.h>
#define WIDTH 800
#define HEIGHT 800
#define MAX_GRAY 255


typedef struct
{
    unsigned char R[WIDTH][HEIGHT];
    unsigned char G[WIDTH][HEIGHT];
    unsigned char B[WIDTH][HEIGHT];
}image;


int main()
{
    image image_1;

	FILE* pgmimg;
	pgmimg = fopen("Violet_Gradient_For_Point_b.ppm", "wb");

	// Writing Magic Number to the File
	fprintf(pgmimg, "P3\n");

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
			image_1.R[i][j] = value;
			image_1.G[i][j] = 0;
			image_1.B[i][j] = value;
		}
    }

    for (int j = 0; j < HEIGHT; j++)
    {
        for (int i = 0; i < WIDTH; i++)
		 {
			// Writing the gray values in the 2D array to the file
			fprintf(pgmimg, "%d %d %d ", image_1.R[i][j], image_1.G[i][j], image_1.B[i][j]);
		}
		fprintf(pgmimg, "\n");
	}
	fclose(pgmimg);

	return(0);
}
