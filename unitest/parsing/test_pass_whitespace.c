/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pass_whitespace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:55:02 by jduval            #+#    #+#             */
/*   Updated: 2023/03/15 16:44:07 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../greatest.h"

TEST	space_beginning(void)
{
	ASSERT_EQ_FMT(3, pass_whitespace("\n\t lol", 0), "%d");
	PASS();
}

TEST	space_under(void)
{
	ASSERT_EQ_FMT(8, pass_whitespace("je suis ton pere", 7), "%d");
	PASS();	
}

TEST	space_end(void)
{
	ASSERT_EQ_FMT(11, pass_whitespace("je suis\n\t\r ", 7), "%d");
	PASS();	
}

TEST	null_string(void)
{
	ASSERT_EQ_FMT(0, pass_whitespace("", 0), "%d");
	PASS();	
}

TEST	on_character(void)
{
	ASSERT_EQ_FMT(3, pass_whitespace("je suis", 3), "%d");
	PASS();	
}

SUITE (test_pass_whitespace)
{
	RUN_TEST(space_beginning);
	RUN_TEST(space_under);
	RUN_TEST(space_end);
	RUN_TEST(null_string);
	RUN_TEST(on_character);
}
