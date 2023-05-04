/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fill_array_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:37:25 by jduval            #+#    #+#             */
/*   Updated: 2023/03/22 18:47:47 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/utils.h"
#include "../../includes/enum.h"

static char	**cmd;

static void	setup(void *data)
{
	(void) data;
	cmd = NULL;
}

static void teardown(void *data)
{
	(void) data;
	free_array2d(cmd);
}

TEST	test1(void)
{
	cmd = fill_array_cmd("hey <in < lol > mdr >hey non", 2);
	ASSERT_STR_EQ("hey", cmd[0]);
	ASSERT_STR_EQ("non", cmd[1]);
	PASS();
}

TEST	test2(void)
{
	cmd = fill_array_cmd("<in cat >out -e", 2);
	ASSERT_STR_EQ("cat", cmd[0]);
	ASSERT_STR_EQ("-e", cmd[1]);
	PASS();
}

TEST	test3(void)
{
	cmd = fill_array_cmd("cat -e ls -la", 4);
	ASSERT_STR_EQ("cat", cmd[0]);
	ASSERT_STR_EQ("-e", cmd[1]);
	ASSERT_STR_EQ("ls", cmd[2]);
	ASSERT_STR_EQ("-la", cmd[3]);
	PASS();
}

TEST	test4(void)
{
	cmd = fill_array_cmd("\'lol\' <lol hey", 2);
	ASSERT_STR_EQ("\'lol\'", cmd[0]);
	ASSERT_STR_EQ("hey", cmd[1]);
	PASS();
}

SUITE (test_fill_array_cmd)
{
	SET_SETUP(setup, NULL);
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(test1);
	RUN_TEST(test2);
	RUN_TEST(test3);
	RUN_TEST(test4);
}
