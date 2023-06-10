/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileEditor.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:34:20 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/25 02:08:48 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_EDITOR_HPP
# define FILE_EDITOR_HPP

# include <iostream>
# include <string.h>
# include <fstream>
# include <cstdlib>

class	FileEditor {
	public:
		FileEditor();
		~FileEditor();
		static void	replace(size_t &pos, std::string &line, std::string const str1, std::string const str2);
};

#endif