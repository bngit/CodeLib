#!/bin/bash

Show_help () {
    echo "Usage: `basename "$0"` [-hr] [-d Directory]"
    echo "Generate the cscope.out and the ctags"
    echo ""
    echo "  -h              Show this help"
    echo "  -d Directory    Tags the files under that Directory"
    echo "  -r              Delete the tags files"
    exit 0
}

DIRECTORY=./
delete_flag=false
OPTIND=1
# Resetting OPTIND is necessary if getopts was used previously in the script.
while getopts ":hrf:" opt; do
    case $opt in
        h)
            Show_help
            ;;
        r)
            delete_flag=true
            ;;
        d)
            DIRECTORY=$OPTARG
            cd "$DIRECTORY"
            ;;
        \?)
            echo "Invalid option: -$OPTARG" >&2
            exit 1
            ;;
        :)
            echo "Option -$OPTARG requires an argument." >&2
            exit 1
            ;;
  esac
done
shift "$((OPTIND-1))" # Shift off the options and optional --.

# delete the cscope files and the tags
if [ "$delete_flag" = true ]; then
    cd "$DIRECTORY"
    rm -f cscope.files cscope.out cscope.in.out cscope.po.out tags
    exit 0
fi

# check ctags
if command -v unictags > /dev/null 2>&1; then
    CTAGS=unictags
elif command -v ctags > /dev/null 2>&1; then
    CTAGS=ctags
else
    echo >&2 "Require ctags but it's not installed.  Aborting."
    exit 1
fi

# check cscope
if command -v cscope > /dev/null 2>&1; then
    CSCOPE=cscope
else
    echo >&2 "Require cscpoe but it's not installed.  Aborting."
    exit 1
fi

echo -e 'Generate cscope library'
find $PWD -type f -iname "*.cpp" -or -name "*.h" \
    | grep -iv "_test\|_mock\|mock" > cscope.files

# -b: just build
$CSCOPE -b -k -q

echo -e 'Generate tags files'
$CTAGS -R --c++-kinds=+p --fields=+iaS --extra=+fq .

echo "-----OK!------"
exit 0
