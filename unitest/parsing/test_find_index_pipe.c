/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_find_index_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:30:35 by jduval            #+#    #+#             */
/*   Updated: 2023/03/20 17:49:58 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/utils.h"

static int *array;

static void setup(void *data)
{
	(void) data;
	array = NULL;
}

static void	teardown(void *data)
{
	(void) data;
	if (array)
		free(array);
}

TEST	one_pipe(void)
{
	array = find_index_pipe("je     | lol");
	ASSERT_EQ_FMT(1, array[0], "%d");
	ASSERT_EQ_FMT(7, array[1], "%d");
	PASS();
}

TEST	two_pipe(void)
{
	array = find_index_pipe("je | suis | ton");
	ASSERT_EQ_FMT(2, array[0], "%d");
	ASSERT_EQ_FMT(3, array[1], "%d");
	ASSERT_EQ_FMT(10, array[2], "%d");
	PASS();
}

TEST	no_pipe(void)
{
	array = find_index_pipe("je suis ton pere");
	ASSERT_EQ_FMT(0, array[0], "%d");
	PASS();
}

TEST	two_with_quote_pipe(void)
{
	array = find_index_pipe("je \'|\' | \"lol |\" | ton");
	ASSERT_EQ_FMT(2, array[0], "%d");
	ASSERT_EQ_FMT(7, array[1], "%d");
	ASSERT_EQ_FMT(17, array[2], "%d");
	PASS();
}

SUITE	(test_find_index_pipe)
{
	SET_SETUP(setup, NULL);
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(one_pipe);
	RUN_TEST(two_pipe);
	RUN_TEST(no_pipe);
	RUN_TEST(two_with_quote_pipe);
}
