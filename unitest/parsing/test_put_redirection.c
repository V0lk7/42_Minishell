/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_put_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:44:19 by jduval            #+#    #+#             */
/*   Updated: 2023/03/24 13:26:14 by jduval           ###   ########.fr       */
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
	node = put_redirection("cat < lol >> hey ", 2, 0);
	ASSERT_EQ_FMT(REDIRECTION, node->name, "%d");
	ASSERT_EQ_FMT(IN, node->data.rdict.way, "%d");
	ASSERT_EQ_FMT(0, node->data.rdict.fd, "%d");
	ASSERT_STR_EQ("lol", node->data.rdict.file);

	ASSERT_EQ_FMT(REDIRECTION, node->next->name, "%d");
	ASSERT_EQ_FMT(APPEND, node->next->data.rdict.way, "%d");
	ASSERT_EQ_FMT(0, node->next->data.rdict.fd, "%d");
	ASSERT_STR_EQ("hey", node->next->data.rdict.file);
	PASS();
}

TEST	test2(void)
{
	node = put_redirection("cat < lol >> hey < \'  mdr\'", 3, 0);
	ASSERT_EQ_FMT(REDIRECTION, node->name, "%d");
	ASSERT_EQ_FMT(IN, node->data.rdict.way, "%d");
	ASSERT_EQ_FMT(0, node->data.rdict.fd, "%d");
	ASSERT_STR_EQ("lol", node->data.rdict.file);

	ASSERT_EQ_FMT(REDIRECTION, node->next->name, "%d");
	ASSERT_EQ_FMT(APPEND, node->next->data.rdict.way, "%d");
	ASSERT_EQ_FMT(0, node->next->data.rdict.fd, "%d");
	ASSERT_STR_EQ("hey", node->next->data.rdict.file);

	ASSERT_EQ_FMT(REDIRECTION, node->next->next->name, "%d");
	ASSERT_EQ_FMT(IN, node->next->next->data.rdict.way, "%d");
	ASSERT_EQ_FMT(0, node->next->next->data.rdict.fd, "%d");
	ASSERT_STR_EQ("\'  mdr\'", node->next->next->data.rdict.file);
	PASS();
}

SUITE (test_put_redirection)
{
	SET_SETUP(setup, NULL);
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(test1);
	RUN_TEST(test2);

}
