##################################
# ZSH Configuration
##################################
ZSH=$HOME/.oh-my-zsh
COMPLETION_WAITING_DOTS="true"
ZSH_THEME="ys"
export UPDATE_ZSH_DAYS=3
autoload colors && colors
export CLICOLOR=1

# Constants
DOTFILES=$HOME/dotfiles

# History
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
setopt COMPLETE_ALIASES # don't expand aliases before completion

# OSX locale fix
# http://const-cast.blogspot.com/2009/04/mercurial-on-mac-os-x-valueerror.html
if [[ -z "$LC_ALL" ]] ; then
    export LC_ALL=en_US.UTF-8
    export LANG=en_US.UTF-8
fi

##################################
# Source Includes
##################################
source $ZSH/oh-my-zsh.sh
source ~/.aliases
source ~/.functions
source $DOTFILES/z/z.sh
source $DOTFILES/wp-cli/utils

# Load RVM into a shell session as a function
[[ -s "$HOME/.rvm/scripts/rvm" ]] && source "$HOME/.rvm/scripts/rvm"

# GRC colorizes nifty unix tools all over the place
if $(grc &>/dev/null) && ! $(brew &>/dev/null)
then
  source `brew --prefix`/etc/grc.bashrc
fi

# Load Extras File for Private/Local Configurations
if [ -f $HOME/.extras ];
then
  source $HOME/.extras
fi

##################################
# PLUGIN Settings
##################################
# Example format: plugins=(rails git textmate ruby lighthouse)
plugins=(git brew npm rails bundler rvm zsh-syntax-highlighting history-substring-search)

##################################
# EDITOR Definitions
##################################
export EDITOR=vim
export SVN_EDITOR=vim

##################################
# PATH Settings
##################################
# Node.js
NODE_PATH="/usr/local/lib/node"
export NODE_PATH

# Homebrew
PATH="/usr/local/sbin:$PATH"

# MySQL
PATH="/usr/local/mysql/bin:$PATH"

# Node Package Manager
PATH="/usr/local/share/npm/bin:$PATH"

# Ruby
export PATH="~/.rvm/rubies/ruby-1.9.3-p392/bin/ruby:$PATH"

# PHP
PATH="/usr/local/Cellar/php54/5.4.14/bin:$PATH"

# local svn
PATH="/opt/subversion/bin:$PATH"

export PATH

export MANPATH="/usr/local/man:/usr/local/mysql/man:/usr/local/git/man:$MANPATH"