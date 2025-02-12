void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(arry[i]);
	free(array);
}

bool	direction_error(t_coordinates *direction)
{
	if (direction->x > 1 || direction->x < -1)
		return (true);
	if (direction->y > 1 || direction->y < -1)
		return (true);
	if (direction->z > 1 || direction->z < -1)
		return (true);
	return (false);
}

void	parse_direction(char *input, t_camera *cam)
{
	char	**coordinates;

	coordinates = ft_split(input, ",");
	if (!coordinates)
		/*exit malloc error*/
	/*add some error check*/
	cam->direction->x = ft_atof(coordinates[0]);
	cam->direction->y = ft_atof(coordinates[1]);
	cam->direction->z = ft_atof(coordinates[2]);
	if (direction_error(cam->direction))
		/*exit direction error*/
	free_array(coordinates);	

}
void	parse_origin(char *input, t_camera *cam)
{
	char	**coordinates;
	
	/*check for format mistakes
		example:
			commas, ecc..*/
	coordinates = ft_split(input, ",");
	if (!coordinates)
		/*exit with error malloc*/

	/*check for errors in the floats: 
		- more than one point
		- and then? */
	if (!n[0] || !n[1] || !n[2] || n[3])
		/*exit with wrong args num message*/
	cam->origin->x = ft_atof(coordinates[0]);
	cam->origin->y = ft_atof(coordinates[1]);
	cam->origin->z = ft_atof(coordinates[2]);

	free_array(coordinates);

}

void	parse_camera(char **tokens)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		/*malloc error exit*/
	/*if (args are not 4)
		exit with error message ;*/
	parse_origin(tokens[1], cam);
	parse_direction(tokens[2], cam);
	parse_fov(tokens[3], cam);
	
	/*assign cam to main minirt struct*/


}
