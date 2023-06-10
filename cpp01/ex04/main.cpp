/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:34:08 by bogunlan          #+#    #+#             */
/*   Updated: 2023/03/25 12:37:46 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/FileEditor.hpp"

void	createNewFileContent(std::ifstream &ifs, std::ofstream &ofs, char *s1, char *s2) {

	std::string str1 = s1;
	std::string str2 = s2;
	std::string line;
	while (!ifs.eof()) {
		std::getline(ifs, line);
		std::size_t pos;
		pos = line.find(str1, 0);
		std::size_t &pos_ref = pos;
		if (str1 != str2 && str1 != "") {
			while (pos != std::string::npos) {
				std::string &line_ref = line;
				FileEditor::replace(pos_ref, line_ref, str1, str2);
			}
		}
		if (ifs.eof())
			break;
		ofs << line << std::endl;
	}
	ofs << line;
}

int	main(int argc, char **argv) {

	if (argc != 4)
	{
		std::cout << "Usage: ./fstream \"file-name\" \"str\" \"replacement\"" << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		dst_file;

	ifs.open(argv[1], std::ios::in);
	if (!ifs) {
		return EXIT_FAILURE;
	}

	dst_file = argv[1];
	dst_file.append(".replace");

	char	replacement[dst_file.length() + 1];
	strcpy(replacement, dst_file.c_str());

	ofs.open(replacement, std::ios::out);
	if (!ofs) {
		return EXIT_FAILURE;
	}
	std::ifstream	&input = ifs;
	std::ofstream	&output = ofs;
	createNewFileContent(input, output, argv[2], argv[3]);
	ifs.close();
	ofs.close();

	return EXIT_SUCCESS;
}
