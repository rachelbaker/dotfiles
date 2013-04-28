# ZSH BASE CONFIG #
ZSH=$HOME/.oh-my-zsh
autoload colors && colors
ZSH_THEME="steeef"
export UPDATE_ZSH_DAYS=3
COMPLETION_WAITING_DOTS="true"

# ZSH PLUGINS #
# Example format: plugins=(rails git textmate ruby lighthouse)
plugins=(osx brew)

# SOURCE FILES
source $ZSH/oh-my-zsh.sh
source ~/.functions
source ~/.aliases
source ~/.rvm/scripts/rvm


# SET EDITORS #
export EDITOR="'/Applications/Sublime Text 2.app/Contents/SharedSupport/bin/subl' -w"
export SVN_EDITOR="'/Applications/Sublime Text.app/Contents/SharedSupport/bin/subl' -w"

# SET PATHS #

# Node.js
NODE_PATH="/usr/local/lib/node"
export NODE_PATH


# MySQL
PATH="/usr/local/Cellar/mysql/5.6.10/bin:$PATH"


# Node Package Manager
PATH="/usr/local/share/npm/bin:$PATH"

# Ruby
PATH="/Users/rachelbaker/.rvm/rubies/ruby-1.9.3-p392/bin/ruby:$PATH"

# PHP
PATH="$(brew --prefix josegonzalez/php/php54)/bin:$PATH"

# Virtualbox
PATH=/Applications/VirtualBox.app/Contents/MacOS:$PATH

# RVM for scripting
PATH=$PATH:$HOME/.rvm/bin

# Homebrew
PATH="/usr/local/sbin:$PATH"

# CTags
# PATH="/usr/local/bin:$PATH"

export PATH