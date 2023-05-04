/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rafter_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:51:03 by jduval            #+#    #+#             */
/*   Updated: 2023/03/21 15:55:10 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/utils.h"

TEST	test1(void)
{
	ASSERT_EQ_FMT(HDOC, rafter_id("cat << lol -e", 0), "%d");
	PASS();
}

TEST	test2(void)
{
	ASSERT_EQ_FMT(IN, rafter_id("cat < lol -e", 0), "%d");
	PASS();
}

TEST	test3(void)
{
	ASSERT_EQ_FMT(APPEND, rafter_id("cat >> lol -e", 0), "%d");
	PASS();
}

TEST	test4(void)
{
	ASSERT_EQ_FMT(OUT, rafter_id("cat > lol -e", 0), "%d");
	PASS();
}

SUITE (test_rafter_id)
{
	RUN_TEST(test1);
	RUN_TEST(test2);
	RUN_TEST(test3);
	RUN_TEST(test4);
}
