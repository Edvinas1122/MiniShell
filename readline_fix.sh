# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    readline_fix.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emomkus <emomkus@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 18:58:48 by emomkus           #+#    #+#              #
#    Updated: 2022/04/11 19:00:16 by emomkus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

if ! [ -r $HOME/goinfre/.brew/Cellar/readline ]; then
	rm -rf $HOME/goinfre/.brew

	git clone --depth=1 https://github.com/Homebrew/brew $HOME/goinfre/.brew

	echo 'export PATH=$HOME/goinfre/.brew/bin:$PATH' >> $HOME/goinfre/.zshrc

	source $HOME/goinfre/.zshrc && brew update

	brew install readline
fi

#Install up-to-date readline on local user instead using the old readline on school iMac