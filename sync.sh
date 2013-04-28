#!/bin/bash
############################
# synch.sh
# This script syncs dotfiles
############################

########## Variables

dir=~/dotfiles                    # dotfiles directory

cd $dir
git pull
function doIt() {
    rsync --exclude ".git/" --exclude ".DS_Store" --exclude "sync.sh" --exclude "bootstrap.sh" --exclude "README.md" -av . ~
}
if [ "$1" == "--force" -o "$1" == "-f" ]; then
    doIt
else
    read -p "This may overwrite existing files in your home directory. Are you sure? (y/n) " -n 1
    echo
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        doIt
    fi
fi
unset doIt