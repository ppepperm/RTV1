/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:57:58 by ppepperm          #+#    #+#             */
/*   Updated: 2020/07/23 16:58:01 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int	push_sphere(t_scene *scene, char **nums)
{
	t_object	*object;

	if (!(object = (t_object*)malloc(sizeof(t_object))))
		return (0);
	object->type = T_SPHERE;
	if (!(object->data = return_sphere(nums)))
	{
		free(object);
		return (0);
	}
	object->pos = init_p3(ft_atoi(nums[1]),\
	ft_atoi(nums[2]), ft_atoi(nums[3]));
	object->t = init_transform(init_p3(1, 0, 0),\
	init_p3(0, 1, 0), init_p3(0, 0, 1));
	object->i_t = i_transform(object->t);
	object->colour = init_rgb(ft_atoi(nums[5]),\
	ft_atoi(nums[6]), ft_atoi(nums[7]), 255);
	object->reflect = ft_atoi(nums[8]);
	object->mirror = (double)ft_atoi(nums[9])/100;
	object->intersect = intersect_sphere;
	object->light_funk = sphere_light;
	object->norm_funk = sphere_norm;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}

int	push_plane(t_scene *scene, char **nums)
{
	t_object	*object;

	if (!(object = (t_object*)malloc(sizeof(t_object))))
		return (0);
	object->type = T_PLANE;
	if (!(object->data = return_plane(nums)))
	{
		free(object);
		return (0);
	}
	object->pos = init_p3(0, 0, 0);
	object->t = init_transform(init_p3(1, 0, 0),\
	init_p3(0, 1, 0), init_p3(0, 0, 1));
	object->i_t = i_transform(object->t);
	object->colour = init_rgb(ft_atoi(nums[5]),\
	ft_atoi(nums[6]), ft_atoi(nums[7]), 255);
	object->reflect = ft_atoi(nums[8]);
	object->mirror = (double)ft_atoi(nums[9])/100;
	object->intersect = intersect_plane;
	object->light_funk = plane_light;
	object->norm_funk = plane_norm;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}

int	push_cone(t_scene *scene, char **nums)
{
	t_object	*object;

	if (!(object = (t_object*)malloc(sizeof(t_object))))
		return (0);
	object->type = T_CONE;
	if (!(object->data = return_cone(nums)))
	{
		free(object);
		return (0);
	}
	object->pos = init_p3(ft_atoi(nums[1]),\
	ft_atoi(nums[2]), ft_atoi(nums[3]));
	object->t = init_transform(init_p3(1, 0, 0),\
	init_p3(0, 1, 0), init_p3(0, 0, 1));
	object->i_t = i_transform(object->t);
	object->colour = init_rgb(ft_atoi(nums[6]),\
	ft_atoi(nums[7]), ft_atoi(nums[8]), 255);
	object->reflect = ft_atoi(nums[9]);
	object->mirror = (double)ft_atoi(nums[10])/100;
	object->intersect = intersect_cone;
	object->light_funk = cone_light;
	object->norm_funk = cone_norm;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}

int	push_cylinder(t_scene *scene, char **nums)
{
	t_object	*object;

	if (!(object = (t_object*)malloc(sizeof(t_object))))
		return (0);
	object->type = T_CYLINDER;
	if (!(object->data = return_cylinder(nums)))
	{
		free(object);
		return (0);
	}
	object->pos = init_p3(ft_atoi(nums[1]),\
	ft_atoi(nums[2]), ft_atoi(nums[3]));
	object->t = init_transform(init_p3(1, 0, 0),\
	init_p3(0, 1, 0), init_p3(0, 0, 1));
	object->i_t = i_transform(object->t);
	object->colour = init_rgb(ft_atoi(nums[5]),\
	ft_atoi(nums[6]), ft_atoi(nums[7]), 255);
	object->reflect = ft_atoi(nums[8]);
	object->mirror = (double)ft_atoi(nums[9])/100;
	object->intersect = intersect_cylinder;
	object->light_funk = cylinder_light;
	object->norm_funk = cylinder_norm;
	object->next = scene->objects;
	scene->objects = object;
	return (1);
}

int	push_hyperboloid(t_scene *scene, char **nums)
{
    t_object	*object;

    if (!(object = (t_object*)malloc(sizeof(t_object))))
        return (0);
    object->type = T_HYPERBOLOID;
    if (!(object->data = return_hyperboloid(nums)))
    {
        free(object);
        return (0);
    }
    object->pos = init_p3(ft_atoi(nums[1]),\
	ft_atoi(nums[2]), ft_atoi(nums[3]));
    object->t = init_transform(init_p3(1, 0, 0),\
	init_p3(0, 1, 0), init_p3(0, 0, 1));
    object->i_t = i_transform(object->t);
    object->colour = init_rgb(ft_atoi(nums[6]),\
	ft_atoi(nums[7]), ft_atoi(nums[8]), 255);
    object->reflect = ft_atoi(nums[9]);
    object->mirror = (double)ft_atoi(nums[10])/100;
    object->intersect = intersect_hyperboloid;
    object->light_funk = cone_light;
    object->norm_funk = hyperboloid_norm;
    object->next = scene->objects;
    scene->objects = object;
    return (1);
}
