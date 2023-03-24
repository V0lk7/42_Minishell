/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rafter_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:58:53 by jduval            #+#    #+#             */
/*   Updated: 2023/03/21 16:26:50 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/utils.h"

TEST	test1(void)
{
	ASSERT_EQ_FMT(2, rafter_index("< in ls -la", 0), "%d");
	PASS();
}

TEST	test2(void)
{
	ASSERT_EQ_FMT(9, rafter_index("< in ls >-la", 1), "%d");
	PASS();
}

TEST	test3(void)
{
	ASSERT_EQ_FMT(15, rafter_index("in \"<lol\"ls >> -la", 0), "%d");
	PASS();
}

TEST	test4(void)
{
	ASSERT_EQ_FMT(12, rafter_index("<in \'>cat\'> ls ", 4), "%d");
	PASS();
}

SUITE (test_rafter_index)
{
	RUN_TEST(test1);
	RUN_TEST(test2);
	RUN_TEST(test3);
	RUN_TEST(test4);
}
