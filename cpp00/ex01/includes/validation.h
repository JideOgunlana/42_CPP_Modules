/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:40:13 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/22 14:19:58 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include <iostream>
# include <iomanip>
# include <string>
# include <cctype>
# include <cstdlib>

typedef struct	s_validation
{
	bool	valid_first_name,
			valid_last_name,
			valid_nick_name,
			valid_phone,
			valid_secret;
}			t_validation;

typedef struct	s_user_input
{
	std::string	new_first_name,
				new_last_name,
				new_nick_name,
				new_phone,
				new_secret,
				contact_index;
}				t_user_input;


#endif