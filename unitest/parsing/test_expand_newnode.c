/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expand_newnode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:05:40 by jduval            #+#    #+#             */
/*   Updated: 2023/04/24 12:00:36 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/utils.h"
#include "../../includes/parsing.h"
#include "../../includes/clear.h"
#include "../../includes/enum.h"

static t_expand	*node;
static char	*str = "lol$lol\'mdr\'$mdr";

static void	setup(void *data)
{
	(void) data;
	node = NULL;
}

static void teardown(void *data)
{
	(void) data;
	free_lst_expand(node);
}

TEST	test1(void)
{
	int	i = 0;
	node = node_expand(str, &i);
	ASSERT_EQ_FMT(0, node->id, "%d");
	ASSERT_EQ_FMT(3, i, "%d");
	ASSERT_STR_EQ("lol", node->word);
	PASS();
}

TEST	test2(void)
{
	int	i = 3;
	node = node_expand(str, &i);
	ASSERT_EQ_FMT(1, node->id, "%d");
	ASSERT_STR_EQ("$lol", node->word);
	ASSERT_EQ_FMT(7, i, "%d");
	PASS();
}

TEST	test3(void)
{
	int	i = 7;
	node = node_expand(str, &i);
	ASSERT_EQ_FMT(0, node->id, "%d");
	ASSERT_STR_EQ("\'mdr\'", node->word);
	ASSERT_EQ_FMT(12, i, "%d");
	PASS();
}

TEST	test4(void)
{
	int	i = 12;
	node = node_expand(str, &i);
	ASSERT_EQ_FMT(1, node->id, "%d");
	ASSERT_STR_EQ("$mdr", node->word);
	ASSERT_EQ_FMT(16, i, "%d");
	PASS();
}

SUITE (test_node_expand)
{
	SET_SETUP(setup, NULL);
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(test1);
	RUN_TEST(test2);
	RUN_TEST(test3);
	RUN_TEST(test4);
}
