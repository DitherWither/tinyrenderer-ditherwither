#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);

void line(int x_start, int y_start, int x_end, int y_end, TGAImage& image,
    TGAColor color)
{
    int x_span = x_end - x_start;
    int y_span = y_end - y_start;
    for (float t = 0.; t < 1.; t += 0.1) {
        int x = x_start + x_span * t;
        int y = y_start + y_span * t;
        image.set(x, y, color);
    }
}

int main(int argc, char** argv)
{
    TGAImage image(100, 100, TGAImage::RGB);
    // image.set(52, 41, red);
	line(10, 10, 50, 50, image, red);
    image.flip_vertically(); // i want to have the origin at the left bottom
                             // corner of the image
    image.write_tga_file("output.tga");
    return 0;
}
