nnoremap <F6> :NERDTreeToggle<CR>

syntax on
set number
set cursorline
set cursorcolumn
set autoindent
set cindent
set mouse=r
set modeline
set modelines=5
set tabstop=4
highlight ExtraWhitespace ctermbg=red guibg=red
match ExtraWhitespace /\s\+$\|\s+\s{1}/
set nocompatible

