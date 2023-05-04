/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_count_words.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:27:55 by jduval            #+#    #+#             */
/*   Updated: 2023/03/22 16:38:51 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/utils.h"

TEST	test1(void)
{
	ASSERT_EQ_FMT(1, count_words("je", 0), "%d");
	PASS();
}

TEST	test2(void)
{
	ASSERT_EQ_FMT(2, count_words("je suis", 0), "%d");
	PASS();
}

TEST	test3(void)
{
	ASSERT_EQ_FMT(1, count_words("je < suis", 1), "%d");
	PASS();
}

TEST	test4(void)
{
	ASSERT_EQ_FMT(3, count_words("cat <in>out lol -a", 2), "%d");
	PASS();
}

SUITE (test_count_words)
{
	RUN_TEST(test1);
	RUN_TEST(test2);
	RUN_TEST(test3);
	RUN_TEST(test4);
}
