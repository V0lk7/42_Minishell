/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_first_character.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:55:02 by jduval            #+#    #+#             */
/*   Updated: 2023/03/14 15:08:10 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../greatest.h"

TEST	no_word_before(void)
{
	ASSERT_EQ_FMT(FALSE, first_character("| lol"), "%d");
	PASS();
}

TEST	word_before(void)
{
	ASSERT_EQ_FMT(TRUE, first_character("hey | lol"), "%d");
	PASS();
}

TEST	null_word(void)
{
	ASSERT_EQ_FMT(FALSE, first_character(NULL), "%d");
	PASS();
}

TEST	no_pipe(void)
{
	ASSERT_EQ_FMT(TRUE, first_character("hey girl"), "%d");
	PASS();
}

TEST	empty_line(void)
{
	ASSERT_EQ_FMT(FALSE, first_character("\t\r\n     \t\v    "), "%d");
	PASS();
}

TEST	empty_word(void)
{
	ASSERT_EQ_FMT(FALSE, first_character(""), "%d");
	PASS();
}

SUITE (test_first_character)
{
	RUN_TEST(no_word_before);
	RUN_TEST(word_before);
	RUN_TEST(null_word);
	RUN_TEST(no_pipe);
	RUN_TEST(empty_line);
	RUN_TEST(empty_word);
}
