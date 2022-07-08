/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:14:15 by ciclo             #+#    #+#             */
/*   Updated: 2022/07/08 12:42:13 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

char	*ft_strnstr(const char *string_b, const char *string_a, size_t n)
{
	size_t	i;
	size_t	j;
	char	*dst;
	char	*src;

	i = 0;
	dst = ((char *)string_b);
	src = ((char *)string_a);
	if (*src == 0 || src == 0)
		return (dst);
	while (dst[i] && i < n)
	{
		j = 0;
		while (src[j] == dst[i + j] && i + j < n)
		{
			if (src[j + 1] == '\0')
				return (dst + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	main_menu(void)
{
	printf("		====>MAIN MENU<====\n");
	printf("	1) Play Game\n");
	printf("	2) Free Text\n");
	printf("	3) Read File\n");
	printf("	0) EXIT\n");
}

void	game_menu(void)
{
	printf("		====>GAME<====\n");
	printf("	1) Say Hello\n");
	printf("	2) Talk to Mama\n");
	printf("	3) Talk to Papa\n");
	printf("	4) Talk to Granny!\n");
	printf("	5) Kill'em all...\n");
	printf("	6) Show MENU\n");
	printf("	0) EXIT GAME\n");
}

void	start_game(void)
{
	char	*line;
	int		granny_count;

	granny_count = 0;
	game_menu();
	while ((line = get_next_line(0)))
	{
		line = ft_strtrim(line, "       ");
		if (*line == '1')
		{
			printf("Hello to you toooo!\n");
		}
		else if (*line == '2')
		{
			if (granny_count)
			{
				printf("HOW DARE YOU YELL AT YOUR GRANNY! DONT TALK TO ME!\n");
				continue ;
			}
			else
			{
				printf("Dear, what do you want?\n");
				line = get_next_line(0);
				if (ft_strnstr(line, "love", ft_strlen(line)))
					printf("I love you too, honey!\n");
				else
					printf("So you don't love ME!? :(\n");
			}
		}
		else if (*line == '3')
			if (granny_count)
			{
				printf("You LITTLE RAT! Why u scream to grand'ma!!!\n");
					continue ;
			}
		else
                        {
                                printf("Tell me son... what's on your mind?\n");
                                line = get_next_line(0);
                                if (ft_strnstr(line, "fuck", ft_strlen(line)))
                                        printf("AHHHHHH you little piece of shit come here right now!!! I'll smack your ass!\n");
                                else
                                        printf("So you don't love ME!? :(\n");

                        }
		else if (*line == '4')
		{
			printf("Hello my sweet, here's your granny, ask my anything...\n");
			line = get_next_line(0);
			if (ft_strnstr(line, "!!!", ft_strlen(line)))
			{
				printf("Ahhhhhhh don't scream at me! what did I do to you, you damn bastard!\n");
				granny_count++;
			}
			else
				printf("Hugh!? What did you say!? No no since 1998!\n");
		}
		else if (*line == '5')
		{
			printf("Done.... how sad.... bye bye\n");
			break ;
		}
		else if (*line == '6')
			game_menu();
		else if (*line == '0')
			break ;
		else
			printf("Sorry that's not a valid option... :(\n");
	}
}

int	main(void)
{
	char	*line;

	main_menu();
	while ((line = get_next_line(0)))
	{
		line = ft_strtrim(line, " 	");
		if (*line == '1')
			start_game();
		else if (*line == '2')
			while (printf("%s", get_next_line(0)) > 1);
		else if (*line == '3')
			printf("Working on it\n");
		else if (*line == '0')
			break ;
		else
			printf("Sorry that's not a valid option... :(\n");
		printf("Option choosen: %s\n", line);
		main_menu();
	}
}
