/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_redirection_case.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:55:02 by jduval            #+#    #+#             */
/*   Updated: 2023/03/16 11:35:13 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../greatest.h"

TEST	redirection_case1(void)
{
	ASSERT_EQ_FMT(6, redirection_case("cat > lol", 4), "%d");
	PASS();
}

TEST	redirection_case2(void)
{
	ASSERT_EQ_FMT(6, redirection_case("cat < lol", 4), "%d");
	PASS();
}

TEST	redirection_case3(void)
{
	ASSERT_EQ_FMT(7, redirection_case("cat >> lol", 4), "%d");
	PASS();
}

TEST	redirection_case4(void)
{
	ASSERT_EQ_FMT(7, redirection_case("cat << lol", 4), "%d");
	PASS();
}

TEST	redirection_case5(void)
{
	ASSERT_EQ_FMT(-4, redirection_case("cat <<|", 4), "%d");
	PASS();
}

TEST	redirection_case6(void)
{
	ASSERT_EQ_FMT(-4, redirection_case("cat >>| lol", 4), "%d");
	PASS();
}

TEST	redirection_case7(void)
{
	ASSERT_EQ_FMT(-4, redirection_case("cat >>", 4), "%d");
	PASS();
}

TEST	redirection_case8(void)
{
	ASSERT_EQ_FMT(-4, redirection_case("cat >>       ", 4), "%d");
	PASS();
}

TEST	redirection_case9(void)
{
	ASSERT_EQ_FMT(8, redirection_case("cat >>  je", 4), "%d");
	PASS();
}

SUITE (test_redirection_case)
{
	RUN_TEST(redirection_case1);
	RUN_TEST(redirection_case2);
	RUN_TEST(redirection_case3);
	RUN_TEST(redirection_case4);
	RUN_TEST(redirection_case5);
	RUN_TEST(redirection_case6);
	RUN_TEST(redirection_case7);
	RUN_TEST(redirection_case8);
	RUN_TEST(redirection_case9);
}
