#include "cub3d.h"

// Main function to initialize window and display the image
int main(void) {
    // Initialize MLX42
    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Hello World", true);
    if (!mlx) {
        fprintf(stderr, "MLX42 initialization failed\n");
        return EXIT_FAILURE;
    }

    // Create an image
    mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!img) {
        fprintf(stderr, "Image creation failed\n");
        mlx_terminate(mlx);
        return EXIT_FAILURE;
    }

    // Fill the screen with black color
    memset(img->pixels, 0, WIDTH * HEIGHT * sizeof(uint32_t));
    mlx_image_to_window(mlx, img, 0, 0);

    // Draw something here 

    // Hook the loop to keep the window open
    mlx_loop(mlx);

    // Clean up
    mlx_delete_image(mlx, img);
    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}
