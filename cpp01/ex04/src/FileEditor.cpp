/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileEditor.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:34:14 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/25 12:41:43 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FileEditor.hpp"

FileEditor::FileEditor() {
	return ;
}

FileEditor::~FileEditor() {
	return ;
}

void	FileEditor::replace(size_t &pos, std::string &line, std::string const str1, std::string const str2) {
	line.erase(pos, str1.length());
	line.insert(pos, str2);
	// line = line.substr(0, pos) + str2 + line.substr(pos + str1.length()); alternative to the lines above
	pos = line.find(str1, pos + str2.length());
}
