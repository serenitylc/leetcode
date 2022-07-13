" General setting
set number
set title
set hlsearch
set autoindent
set smartindent
syntax on

" Improve smoothness of redrawing
set ttyfast

" Controls the number format recognized by ctrl-a and ctrl-x
set nrformats=

" Don't redraw while executing macros (good performance config)
set lazyredraw

" In many terminal emulators the mouse works just fine, thus enable it.
set mouse=a

" Enable clipboard if possible
if has('clipboard')
    if has('unnamedplus') " When possible use + register for copy-paste
        set clipboard=unnamed,unnamedplus
    else " On mac and Windows, use * register for copy-paste
        set clipboard=unnamed
    endif
endif
    
" Set utf8 as standard encoding and en_US as the standard language
set encoding=utf8
    
" Custom key mapping 
let mapleader=','

" Tap Ctrl-d to delete a line under INSERT MODE
imap <C-d> <Esc>ddi

" Tap jj to NORMAL MODE
inoremap jj <Esc>`^

" Tap leader+w to save
inoremap <leader>w <Esc>:w<cr>
noremap <leader>w :w<cr>

" Tap Ctrl-[hjkl] to switch window
noremap <C-h> <C-w>h
noremap <C-j> <C-w>j
noremap <C-k> <C-w>k
noremap <C-l> <C-w>l
    
" Tap Ctrl-[ae] to begin/end of line
inoremap <C-a> <Home>
inoremap <C-e> <End>

" Tap Ctrl-[bf] to move cursor left/right
inoremap <C-b> <Left>
inoremap <C-f> <Right>

" Tap Ctrl-[hl] to move left/right by word
inoremap <C-h> <S-Left>
inoremap <C-l> <S-Right>

" Tap Ctrl-[kj] to move cursor up/down
inoremap <C-k> <C-o>gk
inoremap <C-j> <C-o>gj

nmap ; :

call plug#begin()
" The default plugin directory will be as follows:
"   - Vim (Linux/macOS): '~/.vim/plugged'
"   - Vim (Windows): '~/vimfiles/plugged'
"   - Neovim (Linux/macOS/Windows): stdpath('data') . '/plugged'
" You can specify a custom plugin directory by passing it as the argument
"   - e.g. `call plug#begin('~/.vim/plugged')`
"   - Avoid using standard Vim directory names like 'plugin'
Plug 'mhinz/vim-startify'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'Yggdroot/indentLine'
Plug 'easymotion/vim-easymotion'
" Initialize plugin system
call plug#end()

nmap ss <Plug>(easymotion-s2)