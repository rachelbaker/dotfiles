##################################
# ZSH Configuration
##################################
ZSH=$HOME/.oh-my-zsh
autoload colors && colors

COMPLETION_WAITING_DOTS="true"
ZSH_THEME="ys"

DOTFILES=$HOME/dotfiles

# Projects folder to enable `c [tab]` shortcut
export PROJECTS=$HOME/Sites
export UPDATE_ZSH_DAYS=3

HISTFILE=~/.zsh_history
HISTSIZE=10000
SAVEHIST=10000

setopt NO_BG_NICE # don't nice background tasks
setopt NO_HUP
setopt NO_LIST_BEEP
setopt HIST_VERIFY
setopt SHARE_HISTORY
setopt EXTENDED_HISTORY # add timestamps to history
setopt PROMPT_SUBST
setopt CORRECT
setopt COMPLETE_IN_WORD
setopt IGNORE_EOF
setopt APPEND_HISTORY
setopt INC_APPEND_HISTORY SHARE_HISTORY  # increment and share history
setopt HIST_IGNORE_ALL_DUPS
setopt HIST_REDUCE_BLANKS

# don't expand aliases _before_ completion has finished
setopt complete_aliases


##################################
# Source Includes
##################################
source $ZSH/oh-my-zsh.sh
source ~/.aliases
source ~/.functions
source $DOTFILES/z/z.sh
source $DOTFILES/wp-cli/utils

# Load RVM into a shell session *as a function*
# [[ -s "$HOME/.rvm/scripts/rvm" ]] && source "$HOME/.rvm/scripts/rvm"

# GRC colorizes nifty unix tools all over the place
if $(grc &>/dev/null) && ! $(brew &>/dev/null)
then
  source `brew --prefix`/etc/grc.bashrc
fi

# Load Extras File
if [ -f $HOME/.extras ];
then
  source $HOME/.extras
fi


##################################
# PLUGIN Settings
##################################
# Example format: plugins=(rails git textmate ruby lighthouse)
plugins=(git sublime brew)

##################################
# EDITOR Definitions
##################################
export EDITOR="'/Applications/Sublime Text 2.app/Contents/SharedSupport/bin/subl' -w"
export SVN_EDITOR="'/Applications/Sublime Text.app/Contents/SharedSupport/bin/subl' -w"

##################################
# PATH Settings
##################################

# Node.js
NODE_PATH="/usr/local/lib/node"
export NODE_PATH

# Homebrew
PATH="/usr/local/sbin:$PATH"

# MySQL
# PATH="/usr/local/Cellar/mysql/5.6.10/bin:$PATH"
PATH="/usr/local/mysql/bin:$PATH"

# Node Package Manager
PATH="/usr/local/share/npm/bin:$PATH"

# Ruby
PATH="~/.rvm/rubies/ruby-1.9.3-p392/bin/ruby:$PATH"

# PHP
#nPATH="/usr/local/sbin:$PATH"
PATH="$(brew --prefix josegonzalez/php/php54)/bin:$PATH"

# Virtualbox
# PATH=/Applications/VirtualBox.app/Contents/MacOS:$PATH

# RVM for scripting
#PATH=$PATH:$HOME/.rvm/bin

# CTags
export PATH="/usr/local/bin:$PATH"

# local svn
PATH="/opt/subversion/bin:$PATH"

# Git
# PATH="/usr/local/git/bin"

export PATH

export MANPATH="/usr/local/man:/usr/local/mysql/man:/usr/local/git/man:$MANPATH"
