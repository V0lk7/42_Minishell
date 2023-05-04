/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expand_lstexpand.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:05:40 by jduval            #+#    #+#             */
/*   Updated: 2023/04/24 13:28:27 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/utils.h"
#include "../../includes/parsing.h"
#include "../../includes/clear.h"
#include "../../includes/enum.h"

static t_expand	*node;
static char	*str = "lol$lol\'mdr\'$mdr";
static char	*str1 = "$lol";
static char	*str2 = "$lol$mdr";

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
	node = divide_words(str);
	ASSERT_STR_EQ("lol", node->word);
	ASSERT_EQ_FMT(0, node->id, "%d");
	ASSERT_STR_EQ("$lol", node->next->word);
	ASSERT_EQ_FMT(1, node->next->id, "%d");
	ASSERT_STR_EQ("\'mdr\'", node->next->next->word);
	ASSERT_EQ_FMT(0, node->next->next->id, "%d");
	ASSERT_STR_EQ("$mdr", node->next->next->next->word);
	ASSERT_EQ_FMT(1, node->next->next->next->id, "%d");
	PASS();
}

TEST	test2(void)
{
	node = divide_words(str1);
	ASSERT_STR_EQ("$lol", node->word);
	ASSERT_EQ_FMT(1, node->id, "%d");
	PASS();
}

TEST	test3(void)
{
	node = divide_words(str2);
	ASSERT_STR_EQ("$lol", node->word);
	ASSERT_EQ_FMT(1, node->id, "%d");
	ASSERT_STR_EQ("$mdr", node->next->word);
	ASSERT_EQ_FMT(1, node->next->id, "%d");
	PASS();
}

SUITE (test_lstexpand)
{
	SET_SETUP(setup, NULL);
	SET_TEARDOWN(teardown, NULL);
	RUN_TEST(test1);
	RUN_TEST(test2);
	RUN_TEST(test3);
}
