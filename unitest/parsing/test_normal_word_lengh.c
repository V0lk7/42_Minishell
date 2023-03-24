/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_normal_word_lengh.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:18:50 by jduval            #+#    #+#             */
/*   Updated: 2023/03/24 13:57:55 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../greatest.h"

TEST	nwl1(void)
{
	ASSERT_EQ_FMT(3, normal_word_lengh("je suis ton", 3), "%d");
	PASS();
}

TEST	nwl2(void)
{
	ASSERT_EQ_FMT(3, normal_word_lengh("je suis", 3), "%d");
	PASS();
}

TEST	nwl3(void)
{
	ASSERT_EQ_FMT(1, normal_word_lengh("je suis", 0), "%d");
	PASS();
}

TEST	nwl4(void)
{
	ASSERT_EQ_FMT(7, normal_word_lengh("je suis|lol", 3), "%d");
	PASS();
}

TEST	nwl5(void)
{
	ASSERT_EQ_FMT(14, normal_word_lengh("lol=\"echo <lol\"", 0), "%d");
	PASS();
}

TEST	nwl6(void)
{
	ASSERT_EQ_FMT(16, normal_word_lengh("lol=\"echo <lol  \"", 0), "%d");
	PASS();
}

SUITE (test_normal_word_lengh)
{
	RUN_TEST(nwl1);
	RUN_TEST(nwl2);
	RUN_TEST(nwl3);
	RUN_TEST(nwl4);
	RUN_TEST(nwl5);
	RUN_TEST(nwl6);
}
