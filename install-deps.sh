

TMPDIR="/tmp/crystal-deps"
init_tmpdir() {
  rm -rf "$TMPDIR"
  mkdir "$TMPDIR"
}

enter_tmpdir() {
  cd "$TMPDIR/$1"
}
exit_tmpdir() {
  cd "$TMPDIR"
}

finish_tmpdir() {
  rm -rf "$TMPDIR"
}

install_gumbo() {
  git clone "https://github.com/google/gumbo-parser" "$TMPDIR/gumbo-parser"
  enter_tmpdir gumbo-parser
  ./autogen.sh
  ./configure
  make
  sudo make install
}


set -- install_gumbo 

dependency_functions() {
  for i in "$1"; do
    "$i"
  done
}


init_tmpdir
dependency_functions "$@"
finish_tmpdir
