/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_node_redirect.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:05:40 by jduval            #+#    #+#             */
/*   Updated: 2023/04/21 16:44:48 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/utils.h"
#include "../../includes/parsing.h"
#include "../../includes/clear.h"
#include "../../includes/enum.h"

static t_data	*node;

static void	setup(void *data)
{
	(void) data;
	node = NULL;
}

static void teardown(void *data)
{
	(void) data;
	free_all_nodes(&node);
}

TEST	test1(void)
{
	int	i = 0;
	node = create_node_redirect("cat < lol mdr", &i, i, 0);
	ASSERT_EQ_FMT(REDIRECTION, node->name, "%d");
	ASSERT_EQ_FMT(IN, node->data.rdict.way, "%d");
	ASSERT_EQ_FMT(6, i, "%d");
	ASSERT_STR_EQ("lol", node->data.rdict.file[0]);
	PASS();
}

TEST	test2(void)
{
	int	i = 0;
	node = create_node_redirect("cat << lol mdr", &i, i, 0);
	ASSERT_EQ_FMT(REDIRECTION, node->name, "%d");
	ASSERT_EQ_FMT(HDOC, node->data.rdict.way, "%d");
	ASSERT_EQ_FMT(7, i, "%d");
	ASSERT_STR_EQ("lol", node->data.rdict.file[0]);
	PASS();
}

TEST	test3(void)
{
	int	i = 0;
	node = create_node_redirect("cat >> \'lol  \' mdr", &i, i, 0);
	ASSERT_EQ_FMT(REDIRECTION, node->name, "%d");
	ASSERT_EQ_FMT(APPEND, node->data.rdict.way, "%d");
	ASSERT_EQ_FMT(7, i, "%d");
	ASSERT_STR_EQ("\'lol  \'", node->data.rdict.file[0]);
	PASS();
}

TEST	test4(void)
{
	int	i = 0;
	node = create_node_redirect("cat\'lol > \'< mdr", &i, i, 0);
	ASSERT_EQ_FMT(REDIRECTION, node->name, "%d");
	ASSERT_EQ_FMT(IN, node->data.rdict.way, "%d");
	ASSERT_EQ_FMT(13, i, "%d");
	ASSERT_STR_EQ("mdr", node->data.rdict.file[0]);
	PASS();
}

SUITE (test_create_node_redirect)
{
	SET_SETUP(setup, NULL);
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(test1);
	RUN_TEST(test2);
	RUN_TEST(test3);
	RUN_TEST(test4);
}
