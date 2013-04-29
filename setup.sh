#!/bin/bash
############################
# .setup.sh
# This script creates symlinks from the home directory to any desired dotfiles in ~/dotfiles
############################
########## Variables

dir=~/dotfiles                    # dotfiles directory           # old d
backup=~/dotfiles.backup/setup/

#files=".zshrc .aliases .functions .todo-cli"    # list of files/folders to symlink in homedir
files=".gitignore .gitconfig .hushlogin .zshrc .aliases .functions .todo-cli"
##########

# create dotfiles_old in homedir
echo "Creating $backup for backup of any existing dotfiles"
mkdir -p $backup
echo "...done"


# change to the dotfiles directory
echo -n "Changing to the $dir directory ..."
cd $dir
echo "done"


for file in $files; do
    echo "Moving any existing dotfiles from ~ to $backup"
    cp -R ~/$file $backup
    echo "Copied $file to $backup"
    rm -R ~/$file
    echo "Deleted $file"
    echo "Creating symlink to $file in home directory."
    ln -s $dir/$file ~/$file
done