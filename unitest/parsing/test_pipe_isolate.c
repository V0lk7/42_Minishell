/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipe_isolate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:30:35 by jduval            #+#    #+#             */
/*   Updated: 2023/03/20 17:07:28 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/parsing.h"

static char **array;

static void setup(void *data)
{
	(void) data;
	array = NULL;
}

static void	teardown(void *data)
{
	(void) data;
	if (array)
	{
		for(int i = 0; array[i]; i++)
			free(array[i]);
		free(array);
	}
}

TEST	no_pipe(void)
{
	array = isolate_by_pipe("cat -e lol");
	ASSERT_STR_EQ("cat -e lol", array[0]);
	if (array[1] == NULL)
		ASSERT_EQ(1, 1);
	else
		ASSERT_EQ(1, 0);
	PASS();
}

TEST	one_pipe(void)
{
	array = isolate_by_pipe("cat -e | ls -la");
	ASSERT_STR_EQ("cat -e ", array[0]);
	ASSERT_STR_EQ(" ls -la", array[1]);
	if (array[2] == NULL)
		ASSERT_EQ(1, 1);
	else
		ASSERT_EQ(1, 0);
	PASS();
}

TEST	two_pipe(void)
{
	array = isolate_by_pipe("cat -e | ls -la | echo");
	ASSERT_STR_EQ("cat -e ", array[0]);
	ASSERT_STR_EQ(" ls -la ", array[1]);
	ASSERT_STR_EQ(" echo", array[2]);
	if (array[3] == NULL)
		ASSERT_EQ(1, 1);
	else
		ASSERT_EQ(1, 0);
	PASS();
}

TEST	mlt_pipe(void)
{
	array = isolate_by_pipe("a|b|c");
	ASSERT_STR_EQ("a", array[0]);
	ASSERT_STR_EQ("b", array[1]);
	ASSERT_STR_EQ("c", array[2]);
	if (array[3] == NULL)
		ASSERT_EQ(1, 1);
	else
		ASSERT_EQ(1, 0);
	PASS();
}

TEST	mlt_pipe2(void)
{
	array = isolate_by_pipe("a|\'b\'|\"\"c");
	ASSERT_STR_EQ("a", array[0]);
	ASSERT_STR_EQ("\'b\'", array[1]);
	ASSERT_STR_EQ("\"\"c", array[2]);
	if (array[3] == NULL)
		ASSERT_EQ(1, 1);
	else
		ASSERT_EQ(1, 0);
	PASS();
}

SUITE	(test_isolate_by_pipe)
{
	SET_SETUP(setup, NULL);
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(no_pipe);
	RUN_TEST(one_pipe);
	RUN_TEST(two_pipe);
	RUN_TEST(mlt_pipe);
	RUN_TEST(mlt_pipe2);
}
