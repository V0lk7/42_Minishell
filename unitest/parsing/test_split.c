/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:37:25 by jduval            #+#    #+#             */
/*   Updated: 2023/04/24 15:47:43 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/utils.h"
#include "../../includes/enum.h"

static char	**array;

static void	setup(void *data)
{
	(void) data;
	array = NULL;
}

static void teardown(void *data)
{
	(void) data;
	free_array2d(array);
}

TEST	test1(void)
{
	array = split_by_str("je suis ton pere", "\n\t ");
	ASSERT_STR_EQ("je", array[0]);
	ASSERT_STR_EQ("suis", array[1]);
	ASSERT_STR_EQ("ton", array[2]);
	ASSERT_STR_EQ("pere", array[3]);
	PASS();
}

TEST	test2(void)
{
	array = split_by_str("\n\n   je    \n\t", "\n\t ");
	ASSERT_STR_EQ("je", array[0]);
	PASS();
}

TEST	test3(void)
{
	array = split_by_str("           je suis        ton             \t", "\n\t ");
	ASSERT_STR_EQ("je", array[0]);
	ASSERT_STR_EQ("suis", array[1]);
	ASSERT_STR_EQ("ton", array[2]);
	PASS();
}

TEST	test4(void)
{
	array = split_by_str("", "\n\t ");
	ASSERT_STR_EQ("", array[0]);
	PASS();
}

TEST	test5(void)
{
	array = split_by_str("$lol", "\n\t ");
	ASSERT_STR_EQ("$lol", array[0]);
	PASS();
}

SUITE (test_split)
{
	SET_SETUP(setup, NULL);
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(test1);
	RUN_TEST(test2);
	RUN_TEST(test3);
	RUN_TEST(test4);
	RUN_TEST(test5);
}
