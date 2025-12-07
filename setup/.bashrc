# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples

# If not running interactively, don't do anything
case $- in
    *i*) ;;
      *) return;;
esac

# don't put duplicate lines or lines starting with space in the history.
# See bash(1) for more options
HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
HISTSIZE=1000
HISTFILESIZE=2000

# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
shopt -s checkwinsize

# If set, the pattern "**" used in a pathname expansion context will
# match all files and zero or more directories and subdirectories.
#shopt -s globstar

# make less more friendly for non-text input files, see lesspipe(1)
[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# set variable identifying the chroot you work in (used in the prompt below)
if [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi

# set a fancy prompt (non-color, unless we know we "want" color)
case "$TERM" in
    xterm-color|*-256color) color_prompt=yes;;
esac

# uncomment for a colored prompt, if the terminal has the capability; turned
# off by default to not distract the user: the focus in a terminal window
# should be on the output of commands, not on the prompt
#force_color_prompt=yes

if [ -n "$force_color_prompt" ]; then
    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
	# We have color support; assume it's compliant with Ecma-48
	# (ISO/IEC-6429). (Lack of such support is extremely rare, and such
	# a case would tend to support setf rather than setaf.)
	color_prompt=yes
    else
	color_prompt=
    fi
fi

if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
fi
unset color_prompt force_color_prompt

# If this is an xterm set the title to user@host:dir
case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
    ;;
*)
    ;;
esac

# enable color support of ls and also add handy aliases
if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls --color=auto'
    #alias dir='dir --color=auto'
    #alias vdir='vdir --color=auto'

    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
fi

# colored GCC warnings and errors
#export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'

# some more ls aliases
alias ll='ls -alF'
alias la='ls -A'
alias l='ls -CF'

# Add an "alert" alias for long running commands.  Use like so:
#   sleep 10; alert
alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'

# Alias definitions.
# You may want to put all your additions into a separate file like
# ~/.bash_aliases, instead of adding them here directly.
# See /usr/share/doc/bash-doc/examples in the bash-doc package.

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

# enable programmable completion features (you don't need to enable
# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
# sources /etc/bash.bashrc).
if ! shopt -oq posix; then
  if [ -f /usr/share/bash-completion/bash_completion ]; then
    . /usr/share/bash-completion/bash_completion
  elif [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
  fi
fi



export PATH=$PATH:/c/Users/hessa/AppData/Local/Programs/Python/Python311/Scripts

alias refresh='source ~/.bashrc'
alias bashrc='code ~/.bashrc'
alias amend='git commit --amend --no-edit && git push -f'
alias python='winpty C:/Users/hessa/AppData/Local/Programs/Python/Python311/python.exe'
alias py='winpty C:/Users/hessa/AppData/Local/Programs/Python/Python311/python.exe'
alias pip='winpty C:/Users/hessa/AppData/Local/Programs/Python/Python311/Scripts/pip.exe'
alias build='cd ~/cmake_builds/*/ && cmake --build . --config Release --target all -- -j 8 && cd -'
alias run='ninja -j$(nproc)'

alias ignore='code ~/.gitignore'
alias fetch='git fetch --prune'
alias pull='git stash && git fetch --prune && git pull --prune && git stash pop'

alias tps='[ -d "cmake_builds/" ] && echo"" || cd ../../ && ./cmake_builds/*/bin/tps -server localhost:12345'
alias term='terminator -l default'

alias explore='explorer.exe .'
alias yaml='code ~/.config/clangd/config.yaml'
alias clangd='code ~/.clang-format'

alias apr='rm -rf myapp.exe && g++ myapp.cpp -I./Headers -L./Lib -lPDFNetC -lstdc++ -lpthread -lm  -Wl,-rpath,./Lib -Wl,-rpath,$ORIGIN -o myapp && cp ./Lib/PDFNetC.dll . && ./myapp.exe'

alias search='find . -iname ' # dont forget quotations eg."*.git*"
# use 'find . -iname -type f "*folder name*" to search for folder names
alias tel='telnet 10.10.100.38 31801'

alias remote='ssh sam.ganjian@10.10.100.38 -p 22'
alias dev='ssh sam.ganjian@10.10.100.38 -p 22'
alias prod='ssh hganjian@felixcloud1.payfelix.com'
#qmake CONFIG+=debug && makenew
# git submodule update --init --recursive
alias mclean='make distclean'
alias fl='cd ~/felix'
alias sand='cd /sandbox/hector_hessam'
alias raws='ssh -i "~/CloudHSM-Key.pem" ec2-user@54.174.202.39'

# to run the pythons:
# 1. python -m venv venv
# 2. source venv/Scripts/activate. type deactivate to get out
# 3. pip install -r requirements.txt
# 4. streamlit run x.py
alias deep='ollama run deepseek-r1:7b'
# alias deep='ollama run samganjian'
alias sam='ollama run samGPT'
alias oc='ollama create samGPT -f ./samganjian.modelfile'
alias gpt='winpty C:/Users/hessa/AppData/Local/Programs/Python/Laluncher/py.exe app.py'

function run
{
  if [ -z "$1" ]
  then
    echo "No file name was given. Using default" &&
    rm -rf ./test.exe && g++ ./test.cpp -o test && ./test.exe
  else
    rm -rf ./$1.exe && g++ ./$1.cpp -o test && ./$1.exe
  fi
}

function dbup
{
  if [ -z "$1" ]
  then
    echo "Please insert the name of the database to update" &&
    ls -ltF /media/hga/Files/opt/hacon/tps/sqliteDB/
  else
    rm -rf /media/hga/Files/opt/hacon/tps/sqliteDB/test.sdb && cp /media/hga/Files/opt/hacon/tps/sqliteDB/$1 /media/hga/Files/opt/hacon/tps/sqliteDB/test.sdb && ./cmake_builds/*/bin/tps_dbm* --upgrade --dbfile  /media/hga/Files/opt/hacon/tps/sqliteDB/test.sdb --yes
  fi
}

# alias log='code `ls -t  ~/.local/share/TPS/HaCon/tps/log/tps-tps_admin* | head -1`'
function log
{
  if [[ "$PWD" == *tps_bn* ]]
  then
    echo "Current project: BN"
    if [ -z "$1" ]
    then
      code `ls -t  ~/.local/share/TPS/HaCon/tps/log/*tps_admin* | head -1`
    else
      code `ls -t  ~/.local/share/TPS/HaCon/tps/log/*$1* | head -1`cd
    fi

  elif [[ "$PWD" == *tps_siph* ]]
  then
    echo "Current project: SIPH"
    if [ -z "$1" ]
    then
      code `ls -t  ~/.local/share/TPS/HaCon/tps/log/*testuser* | head -1`
    else
      code `ls -t  ~/.local/share/TPS/HaCon/tps/log/*$1* | head -1`
    fi

  elif [[ "$PWD" == *tps_trv* ]]
  then
    echo "Current project: TRV"
    if [ -z "$1" ]
    then
      code `ls -t  ~/.local/share/TPS/HaCon/tps/log/*tps_admin* | head -1`
    else
      code `ls -t  ~/.local/share/TPS/HaCon/tps/log/*$1* | head -1`
    fi

  elif [[ "$PWD" == *tps_master* ]]
  then
    echo "Current project: MASTER"
    if [ -z "$1" ]
    then
      code `ls -t  ~/.local/share/TPS/HaCon/tps/log/*tps_* | head -1`
    else
      code `ls -t  ~/.local/share/TPS/HaCon/tps/log/*$1* | head -1`
    fi
  else
  echo "Current project: Unknown. Opening last file in tps/log"
  if [ -z "$1" ]
    then
      code `ls -t  ~/.local/share/TPS/HaCon/tps/log/* | head -1`
    else
      code `ls -t  ~/.local/share/TPS/HaCon/tps/log/*$1* | head -1`
    fi
  fi
}
