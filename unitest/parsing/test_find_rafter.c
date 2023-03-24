/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_find_rafter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:48:42 by jduval            #+#    #+#             */
/*   Updated: 2023/03/21 12:00:02 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/utils.h"

TEST	no_rafter(void)
{
	ASSERT_EQ_FMT(0, find_rafter("ls -la"), "%d");
	PASS();
}

TEST	one_rafter(void)
{
	ASSERT_EQ_FMT(1, find_rafter("ls >-la"), "%d");
	PASS();
}

TEST	two_rafter(void)
{
	ASSERT_EQ_FMT(2, find_rafter("<ls cat > la"), "%d");
	PASS();
}

TEST	one_hdoc_rafter(void)
{
	ASSERT_EQ_FMT(2, find_rafter("<<ls cat > la"), "%d");
	PASS();
}

TEST	one_append_rafter(void)
{
	ASSERT_EQ_FMT(2, find_rafter("<<ls cat i>> la"), "%d");
	PASS();
}

TEST	mlt_rafter(void)
{
	ASSERT_EQ_FMT(3, find_rafter("<<ls <cat i>> la"), "%d");
	PASS();
}

SUITE (test_find_rafter)
{
	RUN_TEST(no_rafter);
	RUN_TEST(one_rafter);
	RUN_TEST(two_rafter);
	RUN_TEST(one_hdoc_rafter);
	RUN_TEST(one_append_rafter);
	RUN_TEST(mlt_rafter);
}
