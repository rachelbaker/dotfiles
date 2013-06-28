" Vim Setup for Rachel Baker <rachel@rachelbaker.me>

" Set color scheme
set background=dark
syntax on

set number
set ruler
set textwidth=80

set showmatch

" Enable search highlighting
set hlsearch

" Incrementally match the search
set incsearch

set smartcase
set ignorecase

" Tabstops are 4 spaces
set tabstop=2
set shiftwidth=2
set softtabstop=2
set expandtab
set autoindent

filetype plugin indent on

" When the page starts to scroll, keep the cursor 8 lines from the top and 8
" lines from the bottom
set scrolloff=8

" set visual bell, be nice to your co-workers
set vb

" Set directory for swap files
set directory=~/.vim/tmp

" Allow backspacing over indent, eol, and the start of an insert
set backspace=2

" Make sure that unsaved buffers that are to be put in the background are
" allowed to go in there (ie. the "must save first" error doesn't come up)
set hidden

" Adjust syntax highlighting colors - if possible
set background=dark

" Enhanced mode of command-line completion
set wildmenu

" Make command line two lines high
set ch=2

" Always show status line
set laststatus=2

" Keep some stuff in the history
set history=100

" Show the current mode
set showmode