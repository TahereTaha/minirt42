/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:37:20 by tatahere          #+#    #+#             */
/*   Updated: 2025/02/12 11:05:03 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42/MLX42.h"
#include "vector_math.h"
#define WIDTH 256
#define HEIGHT 256

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(void)
{
//
//		some tests with the vector math implementation.
//

	//	magnitudes.
	t_vec3	vec;
	vec.x = 3;
	vec.y = 2;
	vec.z = 5;
	printf("\n\n\n\ntesting the magnitude\n\n");
	printf("the vector is:\n");
	vec3_print(vec);
	printf("the magnitude is:%f\n", vec3_get_magnitude(vec));
	

	//	addition.
	printf("\n\n\n\ntesting the addition\n\n");
	t_vec2	vector1;
	vector1.x = 5;
	vector1.y = 3;
	vec2_print(vector1);
	t_vec2	vector2;
	vector2.x = 2;
	vector2.y = -1;
	vec2_print(vector2);
	t_vec2	vector3;
	vector3 = vec2_add(vector1, vector2);
	vec2_print(vector3);


	//	scaling.
	printf("\n\n\n\ntesting the scaling\n\n");
	vector1.x = 23;
	vector1.y = 42;
	vec2_print(vector1);
	vector2 = vec2_scale(vector1, 1.5);
	vec2_print(vector2);

	//	normalization.
	printf("\n\n\n\ntesting the normalizaton\n\n");
	
	printf("\ncase0;\n");
	vector1.x = 25;
	vector1.y = 0;
	vec2_print(vector1);
	vector2 = vec2_normalize(vector1);
	vec2_print(vector2);
	printf("the magnitude is:%f\n", vec2_get_magnitude(vector2));
	
	printf("\ncase1;\n");
	vector1.x = 23;
	vector1.y = 42;
	vec2_print(vector1);
	vector2 = vec2_normalize(vector1);
	vec2_print(vector2);
	printf("the magnitude is:%f\n", vec2_get_magnitude(vector2));
	
	printf("\ncase2;\n");
	vector1.x = 0.2;
	vector1.y = 0.1;
	vec2_print(vector1);
	vector2 = vec2_normalize(vector1);
	vec2_print(vector2);
	printf("the magnitude is:%f\n", vec2_get_magnitude(vector2));
	
	printf("\ncase3;\n");
	vector1.x = 0;
	vector1.y = 0;
	vec2_print(vector1);
	vector2 = vec2_normalize(vector1);
	vec2_print(vector2);
	printf("the magnitude is:%f\n", vec2_get_magnitude(vector2));


	printf("\n\n\n\ntesting the linear combination\n\n");
	vector1.x = 1;
	vector1.y = 2;
	vec2_print(vector1);
	vector2.x = 3;
	vector2.y = -1;
	vec2_print(vector2);
	vector3 = vec2_linear_combination(vector1, 1.5, vector2, 0.6);
	vec2_print(vector1);


	
	exit(42);





//
//		some test with the window and mlx
//


	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
